#include <iostream>
#include "../include/DatabaseManager.h"

int main() {
    std::cout << "Student Information System Started" << std::endl;

    DatabaseManager db("host=db port=5432 dbname=studentdb user=studentuser password=studentpass");

    // Checking the Connection
    if (db.connect()) {
        std::cout << "Connection verified. Checking database structure..." << std::endl;
        db.createTable();  // Creates the Table
    } else {
        std::cerr << "FATAL ERROR: Could not connect to database. System stopping." << std::endl;
        return 1;
    }

    //Insertion function test
    std::cout << "Adding test data..." << std::endl;
    db.insertStudent(2031424, "Umut", "Topatan", "Computer Science", "umut1@example.com");
    db.insertStudent(2031425, "Furkan", "Kaya", "Computer Science", "furkan@example.com");
    db.insertStudent(2031426, "Osman", "Selvi", "Computer Science", "Osman@example.com");

    //Read Function test
    std::cout << "Reading data from database..." << std::endl;
    db.readStudents();

    //Update function test (Updated the department and the mail)
    db.updateStudent(2031424, "Umut", "Topatan", "Computer Engineering", "umut2@example.com");

    //Reading the data again after Updating the Student information
    db.readStudents();

    //Delete function test (Deleting Umut)
    std::cout << "\n--- Deleting Student 2031424 ---" << std::endl;
    db.deleteStudent(2031424);

    //Reading the data again after Deleting Umut
    db.readStudents();


    //Disconnecting
    db.disconnect();

    return 0;
}
