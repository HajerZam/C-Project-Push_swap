<h1 align="center">🔄 C-Project-Push_swap 🔄</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" />
  <img src="https://img.shields.io/github/languages/top/HajerZam/C-Project-Push_swap?style=flat-square" />
  <img src="https://img.shields.io/github/repo-size/HajerZam/C-Project-Push_swap?style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/HajerZam/C-Project-Push_swap?style=flat-square" />
  <img src="https://img.shields.io/github/issues/HajerZam/C-Project-Push_swap?style=flat-square" />
  <img src="https://img.shields.io/badge/42-Common%20Core-critical" />
  <img src="https://img.shields.io/badge/score-91-brightgreen?style=flat-square">
</p>

<p align="center">
  🧠 My fifth project in 42 Common Core — good god give me patience 𖦹 ´ ᯅ ` 𖦹  
</p>

---

## 📌 Project Overview

**push_swap** is a sorting algorithm project with a twist:

- You have **two stacks**: `A` (initial) and `B` (helper).
- Your goal is to sort `A` using **a limited set of operations**.
- You're graded by how **few operations** you use — optimization is 🔑.

---

## 🔁 Allowed Operations

| Operation | Description                    |
|----------|--------------------------------|
| `sa/sb`  | Swap top two elements of A or B |
| `ss`     | `sa` and `sb` at the same time |
| `pa/pb`  | Push top element between stacks |
| `ra/rb`  | Rotate: top → bottom            |
| `rr`     | `ra` and `rb` together          |
| `rra/rrb`| Reverse rotate: bottom → top    |
| `rrr`    | `rra` and `rrb` together        |

---

## 🧠 Key Constraints

- 🔻 Sorting 100 numbers: **≤ 700 operations**
- 🔻 Sorting 500 numbers: **≤ 5500 operations**
- ❌ No standard sort functions allowed
- ✅ Must follow 42’s Norm coding style

---

## 📂 Stack Data Structures

```c
typedef struct s_node {
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack {
    t_node  *top;
    int     size;
} t_stack;
````

Each stack is a **singly linked list**, allowing efficient rotation and push operations.

---

## 🛠️ Core Implementation Files

### 📦 `push_swap.h` includes all prototypes and structs

### 🔁 `operations.c` contains:

* `sa`, `sb`, `ss` (swap operations)
* `pa`, `pb` (push)
* `ra`, `rb`, `rr` (rotate)
* `rra`, `rrb`, `rrr` (reverse rotate)

### 📊 `sort.c` and `chunks.c` implement:

* Greedy sorting
* Chunk-based push strategy
* Radix sort fallback

---

## ⚙️ The Sorting Algorithm

### 🧩 Hybrid Strategy: Chunks + Radix

1. **Split stack A** into `chunks`
2. **Push elements** from A to B using optimal moves
3. **Rebuild A** by pushing back in sorted order

### 🧪 Key Functions

```c
void split_and_push_chunks(t_stack *a, t_stack *b, int chunks);
void optimized_chunk_push_b(t_stack *a, t_stack *b, int min, int max);
void push_back_to_a(t_stack *a, t_stack *b);
void radix_sort(t_stack *a, t_stack *b, int chunks);
```

---

## 💡 Greedy Logic Breakdown

| Function                 | Purpose                                      |
| ------------------------ | -------------------------------------------- |
| `find_target_index()`    | Finds index of number in chunk range         |
| `greedy_rotate_a()`      | Minimizes rotations to bring number to top   |
| `optimized_chunk_push_b` | Pushes number to B using best rotation path  |
| `push_back_to_a()`       | Rebuilds sorted A by pushing back max values |
| `radix_sort()`           | Efficient final sorting by binary bits       |

---

## 🧪 Example Main Function

```c
int main() {
    t_stack *a = init_stack();
    t_stack *b = init_stack();

    push(a, 3); push(a, 2); push(a, 1);
    print_stack(a, 'A');
    sa(a);
    pb(a, b); pb(a, b);
    pa(a, b);
    return 0;
}
```

---

## 📈 Optimization Examples

| Stack Size | Suggested Method     | Goal Moves |
| ---------- | -------------------- | ---------- |
| ≤ 3        | Manual sort (sa, ra) | \~2–3      |
| ≤ 5        | Selective push       | \~6–12     |
| \~100      | Chunk sort (5–7)     | ≤ 700      |
| \~500      | Radix or 11 chunks   | ≤ 5500     |

---

## ✅ Testing & Checker

### Run with Verifier

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```

* ✅ **"OK"** if sorted correctly
* ❌ **"KO"** if not

### Measure Your Move Count

```bash
ARG="3 2 1"; ./push_swap $ARG | wc -l
```

---

## 🔁 Test Script: Average Moves for 500 Numbers

```bash
total=0
for i in {1..50}; do
    ARG=$(seq 1 500 | sort -R | tr '\n' ' ');
    moves=$(./push_swap $ARG | wc -l);
    total=$((total + moves));
    echo $moves;
done
echo "Average: $((total / 50))"
```

---

## 🧪 Bonus: Checker Program

> `checker_linux` or `checker_mac` is a **verifier program** provided in the project.
> Pipe your move list into it to check if your output is valid.

---

## 📚 Resources

* 📺 [YouTube: Push\_swap Explained](https://youtu.be/WKNSzvGxyL4)
* 🔎 [Radix Sort Explanation](https://www.geeksforgeeks.org/radix-sort/)
* 🧪 [push\_swap\_tester](https://github.com/lklem/push_swap_tester)
* 🧪 [Push\_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)

---

## ✨ Final Notes

This project will:

* Teach you low-level optimization techniques
* Stretch your understanding of sorting complexity
* Make you cry a little (or a lot) 😭

But it’s worth it.

> “Make it work, then make it fast, then make it elegant.”

---

<p align="center">
🧠💻 Keep calm and rotate on! ⏬⏫
</p>
```
