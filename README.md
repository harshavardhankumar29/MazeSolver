# 🧩 Maze Solver

A visual **Breadth-First Search (BFS)** maze solver built with **C++** and **SFML**. The program animates the BFS traversal step-by-step on a 10×10 grid and highlights the shortest path from start to end in yellow.

---

## 📸 Demo

| Color | Meaning |
|-------|---------|
| 🟩 Green | Start cell `(0,0)` |
| 🟥 Red | End cell `(9,9)` |
| ⬛ Black | Wall |
| 🟦 Blue | Visited cells (BFS frontier) |
| 🟨 Yellow | Shortest path (once solved) |
| ⬜ White | Unvisited open cells |

---

## 🚀 Features

- 10×10 grid maze with predefined walls
- Step-by-step **BFS animation** at 50ms intervals
- Visual path tracing from end back to start using a parent map
- Built with **SFML** for real-time rendering

---

## 🛠️ Prerequisites

- **C++17** or later
- **SFML 2.x** library

### Install SFML

**macOS (Homebrew):**
```bash
brew install sfml
```

**Ubuntu/Debian:**
```bash
sudo apt-get install libsfml-dev
```

---

## 🔧 Build & Run

```bash
# Compile
g++ -std=c++17 main.cpp -o maze -lsfml-graphics -lsfml-window -lsfml-system

# Run
./maze
```

---

## 🗂️ Project Structure

```
MazeSolver/
├── main.cpp      # Source code
└── README.md     # Project documentation
```

---

## 🧠 How It Works

1. A 10×10 grid is initialized with hardcoded wall positions.
2. BFS starts from `(0,0)` and explores all reachable cells layer by layer.
3. Each frame, one BFS step is processed and the grid is redrawn.
4. Once `(9,9)` is reached, the shortest path is reconstructed using the parent map and drawn in **yellow**.

---

## 👤 Author

**Harsha Vardhan Kumar**  
[GitHub](https://github.com/harshavardhankumar29)
