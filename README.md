# MiniSTL

MiniSTL is a **learning-focused C++ project** that reimplements core STL-like containers from scratch to understand their **internal data structures, memory management, and abstraction principles**.

Instead of using the C++ Standard Library as a black box, this project rebuilds containers step by step to study how they manage memory, maintain invariants, and expose traversal through iterators.

---

## 🎯 Project Objective

The main goal of MiniSTL is **conceptual and systems-level understanding**, not production completeness.

This project focuses on:
- manual memory management in containers,
- understanding container invariants,
- differences between contiguous and node-based storage,
- size vs capacity semantics,
- reallocation strategies,
- and the role of iterators as a common abstraction across data structures.

---

## 📁 Project Structure
include/
├── algos.h
├── iterator.h
├── list.h
└── vector.h


Each header focuses on a specific STL concept and is implemented incrementally.

---

## 🧱 Implemented Containers

### `mini::list<T>` (`list.h`)

A singly linked list implementation focusing on **node-level memory management** and structural invariants.

Key concepts explored:
- Node-based dynamic allocation
- Explicit `head` and `tail` pointers
- Ownership of nodes
- Maintaining invariants:
  - `head` points to the first node
  - `tail` points to the last node
- Correct handling of edge cases:
  - empty list
  - first insertion
- Manual destructor logic to safely free all nodes

Implemented operations:
- `push_front`
- `push_back`
- `size`
- `empty`

This container highlights how **non-contiguous data structures** manage memory and traversal differently from arrays.

---

### `mini::vector<T>` (`vector.h`)

A dynamic array implementation focusing on **contiguous memory management** and growth strategies.

Key concepts explored:
- Difference between **size** and **capacity**
- Manual dynamic allocation using raw pointers
- Reallocation strategy using capacity doubling
- Copying existing elements during growth
- Amortized `push_back` behavior
- Centralizing reallocation logic through a helper function

Implemented operations:
- `push_back`

Both a **basic, expanded version** and a **refactored version** of `push_back` are retained in comments to clearly document the evolution of the design.

---

## 🔁 Iterators (`iterator.h`)

This header is reserved for implementing **STL-style iterators** that provide a common traversal interface across different containers.

The design follows the idea that:
- iterators abstract traversal, not storage,
- different containers expose different iterator capabilities,
- algorithms should operate on iterators rather than containers.

Iterator implementations are added incrementally after container invariants are fully understood.

---

## ⚙️ Algorithms (`algos.h`)

This header is intended for implementing **generic algorithms** that operate on iterators instead of specific containers, following STL design principles.

The goal is to demonstrate how:
- algorithms remain container-agnostic,
- iterators form the bridge between data structures and algorithms.

---

## 🧠 Design Philosophy

- **Learning-first approach**  
  Code is written for clarity and traceability rather than minimalism.

- **Explicit memory ownership**  
  All allocations and deallocations are handled manually to expose internal behavior.

- **Incremental abstraction**  
  Containers are implemented before iterators, and iterators before algorithms.

- **STL-inspired, not STL-replacement**  
  Advanced features (allocators, exception guarantees, move semantics) are intentionally postponed.

---

## ⚠️ Scope and Limitations

This project does **not** aim to:
- replace the C++ Standard Library,
- provide allocator support,
- guarantee exception safety,
- fully match STL performance characteristics.

The focus remains on **understanding fundamentals**.

---

## 📌 Project Status

🚧 Under active development.  
Containers are implemented first, followed by iterators and generic algorithms.

---

## 📖 Note

This repository is intended for **academic and educational purposes**, particularly for students interested in:
- data structure internals,
- systems programming,
- and low-level C++ design.

---

## 👤 Author

**Shrishti**  
Computer Science student exploring data structure internals, systems-level C++, and STL design through hands-on implementation.
