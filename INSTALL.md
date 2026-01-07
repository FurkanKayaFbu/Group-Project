# 🛠 Installation Guide

This guide explains how to set up and run the Student Management System. We provide two ways to get the project running: using Docker (Recommended) or manual compilation.

## 📋 Prerequisites
Before you start, make sure you have the following installed:
* **Docker & Docker Compose** (Recommended for the easiest setup)
* For Manual Build:
  * C++17 Compatible Compiler (GCC or Clang)
  * CMake 3.10 or higher
  * PostgreSQL (libpqxx library)

---

## 🚀 1. Fast Setup with Docker (Recommended)
Our project is fully containerized. You can run the entire system (App + Database) without installing any local dependencies.

1. **Clone the Repository:**
   ```bash
       git clone [https://github.com/FurkanKayaFbu/Group-Project](https://github.com/FurkanKayaFbu/Group-Project)
          cd Group-Project


🛠️**Execution Commands**

To get the system up and running, follow these specialized commands:

### 1. Start the Database Service
Run the PostgreSQL database in the background (detached mode):

          sudo docker-compose up -d db

Note: This command ensures the database is ready and listening on port 5432 before the application starts.

 ### 2.Access the Application Environment
Use this command to enter the application container with root privileges and start the interactive terminal:

         sudo docker-compose run --rm --user root app bash

**--rm**: Automatically cleans up the container after you exit.

**--user root**: Ensures you have the necessary permissions to execute the compiled C++ binary.

**bash**: Opens the command line interface inside the container.


(This command will pull the necessary images, set up the network, and connect the application to the database automatically.)


### 3.Creating Build and Gettng inside container

If 'build' doesnt exist you can  Create Build Directory:

        mkdir build && cd build

(If it already exists you can just go to  build by:)

        cd build

### 4.Configure and Run
Configure with CMake:

        cmake ..

Compile the Project:

        make

Run the application:

        ./sis-app


✅ Verification

Once the system is running, you should see the following message in the terminal: "Student information system started"
This confirms that the C++ application has successfully established a handshake with the PostgreSQL container.
  After that it will show you the Menu.

🆘 Troubleshooting

Port 5432 is Busy: If you already have PostgreSQL installed locally, it might conflict with Docker. Please stop your local PostgreSQL service before running docker-compose up.

Connection Delay: Sometimes the database takes a few seconds to initialize. If the app fails to connect on the first try, please wait 5-10 seconds and try again.


Official Docker Hub Images: You can also find our images directly on Docker Hub:

🗄️ [Database Service](https://hub.docker.com/repository/docker/fatmadoraneyfbu/sis-project-postgres)

🚀[Application Service](https://hub.docker.com/repository/docker/fatmadoraneyfbu/sis-project-app)


