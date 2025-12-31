#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <string>
#include <pqxx/pqxx>

class DatabaseManager {
private:
   std::string connectionString;

public:
   DatabaseManager(const std::string& connStr);
   bool connect();
   void disconnect();
   void createTable();
   void insertStudent(int id, const std::string& name, const std::string& surname, const std::string& department, const std::string& email);
   void readStudents();
   void updateStudent(int id, const std::string& name, const std::string& surname, const std::string& department, const std::string& email);
   void deleteStudent(int id);
};

#endif

