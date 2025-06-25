# RFID-BASED-AUTHENTICATION-SYSTEM
# NCYS-PROJECT: RFID Attendance System with QR Code Authentication

The **NCYS-PROJECT** is a C++ application developed for secure and efficient attendance management using RFID cards and QR codes. The system allows for the creation of an individual database, RFID card generation, real-time attendance logging, and export of attendance data to CSV files. It includes QR code generation for additional identity verification.

---

## 📌 Features

- RFID-based user authentication
- QR code generation and authentication
- Attendance tracking and logging
- User-friendly admin and user menu interface
- Data export to CSV for further analysis

---

## 🛠 Libraries Used

| Library           | Purpose                                                                 |
|------------------|-------------------------------------------------------------------------|
| `iostream`        | Input/output operations                                                 |
| `fstream`         | Reading/writing to CSV files                                            |
| `string`          | String manipulation                                                     |
| `random`          | Generating random RFID numbers                                          |
| `qrcodegen/QrCode.hpp` | External library for generating QR codes (ensure it is properly installed) |

---

## 🔧 Functions Overview

### 1. `toLowercase`  
- Converts strings to lowercase  
- Used to standardize role input for users (e.g., "Faculty", "Student")

### 2. `readRFID`  
- Simulates reading an RFID card via user input

### 3. `generateRandomRFID`  
- Generates a unique RFID string based on the input year  
- Ensures every person gets a distinct RFID

### 4. `generateQRCode`  
- Generates a QR code using `qrcodegen` and saves it as an SVG  
- Used when adding new users for secure authentication

### 5. `authenticatePerson`  
- Verifies user identity via RFID matching with the database

### 6. `addPerson`  
- Adds new user to the system  
- Generates RFID and QR code and stores user data

### 7. `exportAttendance`  
- Writes attendance data to a CSV file (`attendance.csv`)  
- Useful for reports or external analysis

### 8. `userMenu`  
- Displays menu options for users to mark attendance

### 9. `main`  
- The main driver function  
- Handles the program's menu, input flow, and function calls

---

## 🔄 Program Flow

### Option 1: Admin Menu  
- Add a new person (name, role, year)  
- Generates a random RFID  
- Generates and stores a QR code  
- Adds person to the database

### Option 2: User Menu  
- Allows users to mark attendance  
- Performs RFID authentication  
- Displays success message upon successful verification

### Option 3: Show Database  
- Displays all users with details (name, role, RFID, attendance)

### Option 4: Export Attendance  
- Exports the full attendance record to a file named `attendance.csv`

### Option 5: Exit  
- Closes the application

---

## 🧾 Conclusion

The **NCYS-PROJECT** RFID Attendance System provides a secure and scalable solution for managing attendance in academic or institutional environments. By combining RFID and QR code technology, the system ensures both flexibility and security for user authentication and tracking.

---

## ⚠️ Notes

- Make sure the `qrcodegen` library is properly installed and configured in your development environment.  
- This project is developed **for educational purposes as part of coursework at FAST-NUCES**.
