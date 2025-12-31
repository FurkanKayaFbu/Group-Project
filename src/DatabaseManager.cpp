#include "../include/DatabaseManager.h"
#include <iostream>

//Constructor for the Connection
DatabaseManager::DatabaseManager(const std::string& connStr) : connectionString(connStr) {}

//Disconnect Function
void DatabaseManager::disconnect() {
    std::cout << "Disconnected." << std::endl;
}

//Connection Function
bool DatabaseManager::connect() {
    std::string testConnString = "host=db port=5432 dbname=studentdb user=studentuser password=studentpass";

    try {
        std::cout << "Attempting to connect to Postgres..." << std::endl;
        pqxx::connection c(testConnString);

        if (c.is_open()) {
            std::cout << "SUCCESS: Connected to database: " << c.dbname() << std::endl;
            return true;
        } else {
            std::cout << "ERROR: Opened connection but it seems closed?" << std::endl;
            return false;
        }
    } catch (const std::exception &e) {
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
        return false;
    }
}

// Create Table Function
void DatabaseManager::createTable() {
    try {
        pqxx::connection c(connectionString);
        if (c.is_open()) {
            //Work ensures command works safely.
            pqxx::work w(c);

            w.exec("DROP TABLE IF EXISTS students;");

            // The SQL Commands
            std::string sql = "CREATE TABLE students ("
                              "id INT PRIMARY KEY,"
                              "name VARCHAR(100) NOT NULL,"
                              "surname VARCHAR(100) NOT NULL,"
                              "department VARCHAR(100) NOT NULL,"
                              "email VARCHAR(100) NOT NULL UNIQUE);";

            w.exec(sql);
            w.commit(); // Saves the changes
            std::cout << "Table 'students' ensured." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Table Creation Failed: " << e.what() << std::endl;
    }
}

//Insertion Function to insert student information
void DatabaseManager::insertStudent(int id, const std::string& name, const std::string& surname, const std::string& department, const std::string& email) {
    try {
        pqxx::connection c(connectionString);
        if (c.is_open()) {
            pqxx::work w(c);

            // The SQL Command
            std::string sql = "INSERT INTO students (id, name, surname, department, email) VALUES ("
                            + w.quote(id) + ", "
                            + w.quote(name) + ", "
                            + w.quote(surname) + ", "
                            + w.quote(department) + ", "
                            + w.quote(email) + ");";

            w.exec(sql);
            w.commit();
            std::cout << "Inserted student: " << name << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Insert Failed: " << e.what() << std::endl;
    }
}

//Read Function to list students
void DatabaseManager::readStudents() {
    try {
        pqxx::connection c(connectionString);
        if (c.is_open()) {
            pqxx::work w(c);

            // SELECT all columns from  table
            std::string sql = "SELECT id, name, surname, department, email FROM students";

            // Execute query and store results
            pqxx::result R = w.exec(sql);

            std::cout << "\n--- Student List (" << R.size() << " entries) ---" << std::endl;

            // Loop through each row in the result
            for (const auto &row : R) {
                std::cout << "ID: " << row["id"].c_str()
                          << " | Name: " << row["name"].c_str()
                          << " " << row["surname"].c_str()
                          << " | Dept: " << row["department"].c_str()
                          << " | Email: " << row["email"].c_str()
                          << std::endl;
            }
            std::cout << "-----------------------------------\n" << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Read Failed: " << e.what() << std::endl;
    }
}


void DatabaseManager::updateStudent(int id, const std::string& name, const std::string& surname, const std::string& department, const std::string& email) {
    try {
        pqxx::connection c(connectionString);
        if (c.is_open()) {
            pqxx::work w(c);

            // SQL Command: Updates fields WHERE the id matches
            std::string sql = "UPDATE students SET "
                            "name = " + w.quote(name) + ", "
                            "surname = " + w.quote(surname) + ", "
                            "department = " + w.quote(department) + ", "
                            "email = " + w.quote(email) +
                            " WHERE id = " + w.quote(id) + ";";

            // Execute and store the result
            pqxx::result R = w.exec(sql);
            w.commit();

            // Checks if any rows were affected
            if (R.affected_rows() > 0) {
                std::cout << "Success: Updated info for Student ID " << id << std::endl;
            } else {
                std::cout << "Warning: No student found with ID " << id << ". Nothing updated." << std::endl;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Update Failed: " << e.what() << std::endl;
    }
}

void DatabaseManager::deleteStudent(int id) {
    try {
        pqxx::connection c(connectionString);
        if (c.is_open()) {
            pqxx::work w(c);

            // SQL Command: Delete the row where the ID matches
            std::string sql = "DELETE FROM students WHERE id = " + w.quote(id) + ";";

            // Execute the query and store the result
            pqxx::result R = w.exec(sql);
            w.commit();

            // Check if a row was deleted
            if (R.affected_rows() > 0) {
                std::cout << "Success: Deleted Student ID " << id << std::endl;
            } else {
                std::cout << "Warning: Student ID " << id << " not found. Nothing deleted." << std::endl;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Delete Failed: " << e.what() << std::endl;
    }
}
