# Learn C/C++ With Me 🚀

> A personal hands-on repository for learning **C/C++, Object-Oriented Programming, Data Structures, Algorithms, and problem solving**.

[![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-blue.svg)](https://isocpp.org/)
[![Editor](https://img.shields.io/badge/Editor-VS%20Code-007ACC.svg)](https://code.visualstudio.com/)
[![GitHub](https://img.shields.io/badge/GitHub-Zackik-181717.svg)](https://github.com/Zackik)

## 📖 About

**Learn C/C++ With Me** is a learning-by-doing repository.

The main idea is simple:

> **Don't just make the code work — understand how and why it works.**

The repository contains exercises, implementations, experiments, and coursework related to C/C++ programming. It is organized as a progressive learning journey, from basic programming and array manipulation to **ADT, algorithms, and OOP**.

This is a **learning repository**, not a production-ready library. Code may be refactored or improved as new concepts are learned.

## 🎯 Goals

- Build a strong foundation in C/C++.
- Practice writing programs from scratch.
- Understand arrays, memory, pointers, functions, and classes.
- Learn how Abstract Data Types (ADT) work.
- Practice common problem-solving patterns.
- Understand algorithm complexity and Big-O.
- Learn Object-Oriented Programming through practical examples.
- Gradually build a foundation for Data Structures & Algorithms.

## 📚 Main Topics

### 1. C/C++ Fundamentals

Practice with:

- Variables and data types
- Input / output
- Conditions and loops
- Functions
- Strings
- Arrays
- Pointers
- Basic memory concepts
- Problem solving

### 2. Array ADT

The repository currently contains many exercises around **Array ADT**, including:

- Display
- Append
- Insert
- Delete
- Get / Set
- Search
- Maximum / Minimum
- Sum / Average
- Reverse
- Shift / Circular Shift
- Sorted-array operations
- Merge arrays
- Rearranging elements

### 3. Array Problems

Examples include:

- Find missing elements
- Find duplicate elements
- Find maximum and minimum values
- Pair Sum / Two Sum
- Array transformation
- Array merging
- Combining multiple array operations

### 4. Searching & Algorithms

Current practice includes:

- Linear Search
- Binary Search
- Recursive Binary Search
- Move-to-Front style search
- Recursion
- Algorithm tracing

### 5. Algorithm Analysis

The repository also focuses on understanding **why an algorithm has a particular complexity**.

| Complexity | Meaning |
|---|---|
| `O(1)` | Constant |
| `O(log n)` | Logarithmic |
| `O(n)` | Linear |
| `O(n log n)` | Linearithmic |
| `O(n²)` | Quadratic |

Also practiced:

- Best Case
- Average Case
- Worst Case
- Time Complexity
- Space Complexity
- Operation counting
- Basic recursion analysis

### 6. Object-Oriented Programming

The repository also contains dedicated OOP practice:

- Classes and objects
- Attributes and methods
- Constructors
- Encapsulation
- Student / Product class exercises
- Practical class-based programming

OOP material is organized mainly under:

`OOP/`

and

`OOP_2026/`

## 🗂️ Repository Structure

```text
learnc-_withme/
│
├── .vscode/
│   └── VS Code configuration
│
├── ADT ARRAY/
│   ├── Find_duplicates.cpp
│   ├── find_missing_elements.cpp
│   ├── finding_max_and_min.cpp
│   ├── pair_sum_two_sum.cpp
│   ├── homework.cpp
│   ├── test3.cpp
│   └── ...
│
├── OOP/
│   └── OOP exercises
│
├── OOP_2026/
│   ├── Bai1.cpp
│   ├── Product_Class.cpp
│   ├── Sinh_Vien.cpp
│   ├── Student_class.cpp
│   └── ...
│
└── README.md
```

## 🧠 Learning Workflow

Each topic is approached using the following process:

```text
Learn the concept
       ↓
Implement it
       ↓
Test it
       ↓
Trace the algorithm
       ↓
Analyze complexity
       ↓
Find edge cases
       ↓
Improve the solution
```

The goal is to develop **understanding and problem-solving ability**, rather than simply collecting solutions.

## ▶️ How to Run

### Requirements

Install a C++ compiler such as **G++**.

Check your installation:

```bash
g++ --version
```

### Compile a program

Because the repository contains many independent exercises, compile the file you want to study.

Example:

```bash
g++ "ADT ARRAY/pair_sum_two_sum.cpp" -o pair_sum
```

Run on Linux/macOS:

```bash
./pair_sum
```

Run on Windows:

```powershell
.\pair_sum.exe
```

Another example:

```bash
g++ "OOP_2026/Student_class.cpp" -o student
./student
```

## 🛠️ Tools

- **C / C++**
- **GCC / G++**
- **Visual Studio Code**
- **Git**
- **GitHub**

## 📈 Learning Roadmap

### Foundations

- [x] C/C++ basics
- [x] Arrays
- [x] Functions
- [x] Array ADT
- [x] Searching
- [x] Recursion
- [x] Basic Big-O analysis
- [x] OOP fundamentals

### Data Structures

- [ ] Linked List
- [ ] Doubly Linked List
- [ ] Circular Linked List
- [ ] Stack
- [ ] Queue
- [ ] Deque
- [ ] Hash Table
- [ ] Tree
- [ ] Binary Search Tree
- [ ] Heap
- [ ] Graph

### Algorithms

- [ ] Bubble Sort
- [ ] Selection Sort
- [ ] Insertion Sort
- [ ] Merge Sort
- [ ] Quick Sort
- [ ] Heap Sort
- [ ] BFS
- [ ] DFS
- [ ] Shortest Path
- [ ] Greedy Algorithms
- [ ] Dynamic Programming

### Projects

- [ ] Data Structures mini-project
- [ ] Algorithm visualizer
- [ ] C++ CLI application
- [ ] Problem-solving collection
- [ ] Larger DSA project

## 🔬 Example: Thinking About Complexity

Instead of only asking:

```text
"Does the program work?"
```

also ask:

```text
How many operations does it perform?
What happens when n becomes larger?
What is the best case?
What is the worst case?
How much memory does it use?
Can the algorithm be improved?
```

For example, a simple linear search can have:

```text
Best Case:   O(1)
Worst Case:  O(n)
Space:       O(1)
```

This way of thinking is an important part of the learning process in this repository.

## 🚧 Status

This repository is **actively evolving**.

New exercises, algorithms, OOP examples, and data structures will be added as the learning journey continues.

```text
C/C++ Fundamentals
        ↓
Array ADT
        ↓
Searching & Recursion
        ↓
Big-O Analysis
        ↓
OOP
        ↓
Linear Data Structures
        ↓
Trees & Hash Tables
        ↓
Sorting & Graphs
        ↓
Projects
```

## 🤝 Contributing

This is primarily a personal learning repository, but suggestions and alternative solutions are welcome.

If you notice a bug or have a better approach:

1. Open an **Issue**, or
2. Submit a **Pull Request**.

Learning together is encouraged. 💻

## 👤 Author

**Zackik**

GitHub: https://github.com/Zackik

Repository: https://github.com/Zackik/learnc-_withme

---

> **Learn by coding. Understand by tracing. Improve by analyzing.** 🧠💻
