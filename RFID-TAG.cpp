//NCYS-PROJECT [RFID TAG]

#include <iostream>
#include <string>
#include <random>

using namespace std;

const int MAX_DATABASE_SIZE = 100;  // Max number of persons in the database

string readRFID();         // Function to generate a random RFID based on the year
string generateRandomRFID(int year) 
{
    random_device rd;                        // we are using a random device to seed the random number generator
    mt19937 gen(rd());                       // Using random device to generate a random seed for date
    uniform_int_distribution<> dis(0, 9);    // Defining distribution for the random numbers
    string randomNumbers;                    // function to generate four random numbers
    for (int i = 0; i < 4; ++i) 
    {
        randomNumbers += to_string(dis(gen));
    }
    string yearStr = to_string(year).substr(2);    // Converts the year to a two-digit string
    return yearStr + "k-" + randomNumbers;         // Combine the year and random numbers to form the RFID
}

class Person {
public:
    string name;
    string role;        // options : "Student" or "Faculty"
    bool present;
    string authorizedRFID;

    bool isAuthorizedRFID(const string& rfid) const 
    {
        return authorizedRFID == rfid;
    }
};

string toLowercase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
// Function to read RFID card
string readRFID() 
{
    cout << "Simulating RFID card reading...\n";
    // For demonstration, we'll use a simple input
    string rfidData;
    cout << "Enter RFID data: ";
    cin >> rfidData;
    return rfidData;
}
// Function for authenticatePerson
Person& authenticatePerson(Person database[], int& databaseSize);

void addPerson(Person database[], int& databaseSize) {
    if (databaseSize < MAX_DATABASE_SIZE) {
        Person newPerson;
        cout << "Enter person's name: ";
        getline(cin >> ws, newPerson.name);
        cout << "Enter person's role (Student/Faculty): ";
        getline(cin >> ws, newPerson.role);

        // Ask the admin for the year
        int year;
        cout << "Enter the year (e.g., 2023): ";
        cin >> year;

        // Generate a random RFID for the new person based on the year
        newPerson.authorizedRFID = generateRandomRFID(year);

        newPerson.role = toLowercase(newPerson.role);
        newPerson.present = false;

        database[databaseSize++] = newPerson;
        cout << "Person added to the database with RFID: " << newPerson.authorizedRFID << "\n";
    }
    else {
        cout << "Database is full. Cannot add more persons.\n";
    }
}

void userMenu(Person database[], int& databaseSize) {
    cout << "User Menu:\n";
    cout << "1. Mark Attendance\n";
    cout << "2. Exit\n";

    int userChoice;
    cin >> userChoice;

    switch (userChoice) {
    case 1: {
        Person& authenticatedPerson = authenticatePerson(database, databaseSize);
        if (!authenticatedPerson.name.empty()) {
            cout << "Attendance marked for: " << authenticatedPerson.name << "\n";
        }
        else {
            cout << "Authentication failed. Attendance not marked.\n";
        }
        break;
    }
    case 2:
        cout << "Exiting user menu.\n";
        break;
    default:
        cout << "Invalid option. Returning to the main menu.\n";
    }
}

Person& authenticatePerson(Person database[], int& databaseSize) {
    string rfidData = readRFID();

    for (int i = 0; i < databaseSize; ++i) {
        if (database[i].isAuthorizedRFID(rfidData)) {
            database[i].present = true;
            return database[i];
        }
    }

    cout << "Person not found or authentication failed.\n";
    static Person dummyPerson;
    return dummyPerson;
}

int main() {
    Person database[MAX_DATABASE_SIZE];
    int databaseSize = 0;

    while (true) {
        cout << "Choose an option:\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. Display Database\n";
        cout << "4. Export Attendance\n";
        cout << "5. Exit\n";

        int mainChoice;
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            addPerson(database, databaseSize);
            break;
        case 2:
            userMenu(database, databaseSize);
            break;
        case 3:
            cout << "Database Contents:\n";
            for (int i = 0; i < databaseSize; ++i) {
                cout << "Name: " << database[i].name << "\n";
                cout << "Role: " << database[i].role << "\n";
                cout << "Present: " << (database[i].present ? "Yes" : "No") << "\n";
                cout << "Authorized RFID: " << database[i].authorizedRFID << "\n\n";
            }
            break;
        case 4:
            // Export attendance function will be made and used with filing.
            break;
        case 5:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}
