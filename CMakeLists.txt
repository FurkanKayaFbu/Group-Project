cmake_minimum_required(VERSION 3.10)

project(StudentInfoSystem)

#Using c++17 for easier use

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Fin PostgreSQL and libpqxx Libraries
find_package(PostgreSQL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

# Include directory setup
include_directories(include)
include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories(${PQXX_INCLUDE_DIRS})

#create executable file from sources
add_executable(sis-app
   src/main.cpp
   src/DatabaseManager.cpp
)

target_include_directories(sis-app PUBLIC include)

#Linking the libraries
target_link_libraries(sis-app PUBLIC ${PostgreSQL_LIBRARIES} ${PQXX_LIBRARIES})


