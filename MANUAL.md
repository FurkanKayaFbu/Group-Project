


# 📖 User Manual

This manual explains how to interact with the Student Management System once the application is running.

## 🕹️ Application Interface
The application runs as a Command Line Interface (CLI). Once connected to the database, you will be presented with a main menu.

### Main Menu Options
You can navigate through the system by entering the corresponding number:

1. **Add New Student:** Allows you to enter student details (Name, Surname, Student ID, Department) to be stored in the PostgreSQL database.
2. **List All Students:** Fetches and displays all registered students from the database in a table format.
3. **Update Student Information:** Modify existing student records using their unique Student ID.
4. **Delete Student:** Permanently removes a student record from the system.
5. **Search Student:** Quickly find a specific student by their ID or Name.
6. **Exit:** Safely closes the database connection and terminates the program.

---

## 📝 Example Usage

### Adding a Student
1. Select Option `1`.
2. Enter the Name: `Furkan`
3. Enter the Surname: `Kaya`
4. Enter the Student ID: `20230101`
5. The system will display: `"Student successfully added to the database!"`

### Listing Students
Select Option `2`. The system will retrieve data and display:
| ID | Name | Surname | Department |
|----|------|---------|------------|
| 20230101 | Furkan | Kaya | Computer Eng. |

---

## ⚠️ Important Notes
* **Data Validation:** Please ensure Student IDs are numeric. The system will prompt an error for invalid formats.
* **Persistent Storage:** Since we use Docker Volumes, your data will remain saved even if you restart the application.
* **Database Errors:** If the database is disconnected, the application will show a "Database Connection Error" and return to the main menu.
