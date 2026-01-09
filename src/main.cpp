#include <iostream>
#include "../include/DatabaseManager.h"


//Menu to show options
void showMenu() {
    std::cout << "\n--- Student Information System ---" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. List All Students" << std::endl;
    std::cout << "3. Update Student" << std::endl;
    std::cout << "4. Delete Student" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Select option: ";
}

int main() {
    DatabaseManager db("host=db port=5432 dbname=studentdb user=studentuser password=studentpass");
    //Connection Check
    if (!db.connect()) {
        std::cerr << "Could not connect to database." << std::endl;
        return 1;
    }

    // Create table if it doesn't exist
    db.createTable();

    //Taking input from the user
    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            int id;
            std::string name, surname, dept, email;
            std::cout << "Enter ID: "; std::cin >> id;
            std::cout << "Enter Name: "; std::cin >> name;
            std::cout << "Enter Surname: "; std::cin >> surname;
            std::cout << "Enter Dept: "; std::cin >> dept;
            std::cout << "Enter Email: "; std::cin >> email;

            db.insertStudent(id, name, surname, dept, email);

        } else if (choice == 2) {
            db.readStudents();

        } else if (choice == 3) {
            int id;
            std::string name, surname, dept, email;
            std::cout << "Enter ID to Update: "; std::cin >> id;
            std::cout << "New Name: "; std::cin >> name;
            std::cout << "New Surname: "; std::cin >> surname;
            std::cout << "New Dept: "; std::cin >> dept;
            std::cout << "New Email: "; std::cin >> email;

            db.updateStudent(id, name, surname, dept, email);

        } else if (choice == 4) {
            int id;
            std::cout << "Enter ID to Delete: "; std::cin >> id;
            db.deleteStudent(id);

        } else {
            std::cout << "Invalid option." << std::endl;
        }
    }

    db.disconnect();
    return 0;
}
