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

            // The SQL Commands
            std::string sql = "CREATE TABLE IF NOT EXISTS students ("
                              "id SERIAL PRIMARY KEY,"
                              "name VARCHAR(100) NOT NULL,"
                              "email VARCHAR(100) NOT NULL);";

            w.exec(sql);
            w.commit(); // Saves the changes
            std::cout << "Table 'students' ensured." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Table Creation Failed: " << e.what() << std::endl;
    }
}

void DatabaseManager::insertStudent(const std::string& name, const std::string& email) {
    try {
        pqxx::connection c(connectionString);
        if (c.is_open()) {
            pqxx::work w(c);

            // The SQL Command
            std::string sql = "INSERT INTO students (name, email) VALUES ("
                              + w.quote(name) + ", "
                              + w.quote(email) + ");";

            w.exec(sql);
            w.commit(); // Save the changes
            std::cout << "Inserted student: " << name << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Insert Failed: " << e.what() << std::endl;
    }
}
