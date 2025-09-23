# StarletTests
A repository containing unit tests for **Starlet** libaries. Tests are written using **Google Test** (gtest) and cover basic operations, edge cases, and mathematical correctness.

## Features
- Unit tests for `Vec2`, `Vec3`, and `Vec4` operations in **StarletMath**
- Supports `int`, `float`, and `double` types

## Building and Running Tests
This project uses **CMake** and **Google Test**.

### 1. Clone the Repository
```bash
git clone https://github.com/Masonlet/StarletTests.git
cd StarletTests
```

### 2. Create a Build Directory and Generate Build Files
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### 3. Run the Tests
```bash
ctest
```
