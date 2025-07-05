# C++ Module 09

This repository contains solutions for **Module 09** of the 42 C++ curriculum. It includes three exercises demonstrating file parsing, data structures, and algorithmic problem solving in C++.

## Exercises Overview

1. **ex00: BitcoinExchange**

   * Reads a historical exchange rate database (`data.csv`).
   * Parses user input (`input.csv`) containing dates and values.
   * Calculates and displays the equivalent Bitcoin value for each entry.

2. **ex01: RPN**

   * Implements a Reverse Polish Notation (RPN) calculator.
   * Supports basic arithmetic operations: `+`, `-`, `*`, `/`, `%`.
   * Parses and evaluates expressions from command-line arguments.

3. **ex02: PmergeMe**

   * Implements a hybrid sorting algorithm combining insertion sort and merge sort.
   * Accepts a list of integers as input.
   * Demonstrates performance benefits on large datasets.

## File Structure

```
cpp_module_09-main/
└── cpp_module_09-main/
    ├── ex00/         # BitcoinExchange
    │   ├── BitcoinExchange.cpp
    │   ├── BitcoinExchange.hpp
    │   ├── data.csv
    │   ├── input.csv
    │   ├── main.cpp
    │   └── Makefile
    ├── ex01/         # RPN Calculator
    │   ├── RPN.cpp
    │   ├── RPN.hpp
    │   ├── main.cpp
    │   └── Makefile
    └── ex02/         # PmergeMe
        ├── PmergeMe.cpp
        ├── PmergeMe.hpp
        ├── main.cpp
        └── Makefile
```

## Compilation

Each exercise has its own `Makefile`. To build an exercise:

```bash
cd cpp_module_09-main/ex00  # or ex01, ex02
make
test/<executable> ...      # see Usage below
```

To clean up:

```bash
make clean    # remove object files
make fclean   # remove objects and executables
make re       # full rebuild
```

## Usage

### ex00: BitcoinExchange

```bash
# Build
cd ex00 && make

# Run with default input
./BitcoinExchange

# Or provide custom input file
./BitcoinExchange input.csv
```

### ex01: RPN Calculator

```bash
# Build
cd ex01 && make

# Evaluate expression
./RPN "3 4 + 2 * 7 /"
```

### ex02: PmergeMe

```bash
# Build
cd ex02 && make

# Sort numbers
./PmergeMe 3 5 9 1 4 8 2
```

## Author

* **Alparslan Aslan** ([alparslanaslan504@gmail.com](mailto:alparslanaslan504@gmail.com))

## License

No explicit license provided. Use, modify, and distribute at your own risk.
