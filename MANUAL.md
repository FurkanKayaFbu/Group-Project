


# 📖 User Manual

This manual explains how to interact with the Student Management System once the application is running.

## 🕹️ Application Interface
The application runs as a Command Line Interface (CLI). Once connected to the database, you will be presented with a main menu.

### Main Menu Options
You can navigate through the system by entering the corresponding number:

**'1'**  **Add New Student:** Allows you to enter student details (Name, Surname, Student ID, Department) to be stored in the PostgreSQL database.

**'2'** **List All Students:** Fetches and displays all registered students from the database in a table format.

**'3'** **Update Student Information:** Modify existing student records using their unique Student ID.

**'4'** **Delete Student:** Permanently removes a student record from the system.

**'0'** **Exit:** Safely closes the database connection and terminates the program.

---

## 📝 Example Usage

### Adding a Student
1. Select Option `1` from the main menu.
2. Enter the Student ID: `20230101`
3. Enter the Name: `Furkan`
4. Enter the Surname: `Kaya`
5. Enter the Department: `Computer_Eng`
6. Enter the E-mail: `furkan.kaya@gmail.com`
7. The system will display: `"Inserted student : Furkan"`

### Listing Students
Select Option `2`. The system will retrieve all records from the PostgreSQL database and display them as follows:

| ID | Name | Surname | Department | E-mail |
|----|------|---------|------------|--------|
| 20230101 | Furkan | Kaya | Computer_Eng | furkan.kaya@gmail.com |
---

## ⚠️ Important Notes
* **Data Validation:** Please ensure Student IDs are numeric. The system will prompt an error for invalid formats.

* **Database Errors:** If the database is disconnected, the application will show a "Database Connection Error" and return to the main menu.

