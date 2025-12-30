#include <iostream>
#include "../include/DatabaseManager.h"

int main() {
    std::cout << "Student Information System Started" << std::endl;

    DatabaseManager db("host=db port=5432 dbname=studentdb user=studentuser password=studentpass");

    // Checks the Connection
    if (db.connect()) {
        std::cout << "Connection verified. Checking database structure..." << std::endl;
        db.createTable();  // Creates the Table
    } else {
        std::cerr << "FATAL ERROR: Could not connect to database. System stopping." << std::endl;
        return 1;
    }

    std::cout << "Adding test data..." << std::endl;
    db.insertStudent("Umut Topatan", "umut@example.com");
    db.insertStudent("Test User", "test@example.com");

    return 0;
}
