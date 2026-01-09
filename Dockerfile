FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# 1️⃣ Install dependencies & compiler
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    libpq-dev \
    libpqxx-dev \
    && rm -rf /var/lib/apt/lists/*

# 2️⃣ Set working directory
WORKDIR /app

# 3️⃣ Copy project files
COPY . .

# 4️⃣ Build the application
RUN mkdir -p build && cd build && cmake .. && make

# 5️⃣ Expose port if needed (not mandatory but recommended)
EXPOSE 8080

# 6️⃣ Run the compiled program by default
CMD ["./build/sis-app"]

