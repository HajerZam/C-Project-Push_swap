# C-Project-Push_swap
my fifth project in 42 common core, good god give me patience 𖦹 ´ ᯅ ` 𖦹
### **The Problem Ahead**

**Push_swap** project is simply a sorting problem where you must sort a stack (stack `a`) using a **limited set of operations** while minimizing the number of moves. You have a second stack (`b`) available as a workspace. The challenge is to find the most **optimal** sequence of operations to sort `a` efficiently.

---

## **The Key**

### Understanding the Operations

### **Swap operations (`sa`, `sb`, `ss`)**

- `sa`: Swap the **first two elements** of `A`.
    
    Example:
    
    **Before:** `A = [3, 1, 4, 2]`
    
    **After `sa` →** `A = [1, 3, 4, 2]`
    
- `sb`: Same as `sa`, but for stack `B`.
- `ss`: Does both `sa` and `sb` at the same time.

---

### **Push operations (`pa`, `pb`)**

- `pb`: Move the top element of `A` to `B`.
    
    Example:
    
    **Before:** `A = [3, 1, 4, 2]`, `B = []`
    
    **After `pb` →** `A = [1, 4, 2]`, `B = [3]`
    
- `pa`: Move the top element of `B` to `A`.
    
    (Opposite of `pb`.)
    

---

### **Rotate operations (`ra`, `rb`, `rr`)**

Shifts **all elements** up by one position.

- `ra`: Rotate `A`.
    
    Example:
    
    **Before:** `A = [3, 1, 4, 2]`
    
    **After `ra` →** `A = [1, 4, 2, 3]`
    
- `rb`: Rotate `B`.
- `rr`: Rotate both `A` and `B` at the same time.

---

### **Reverse Rotate operations (`rra`, `rrb`, `rrr`)**

Shifts **all elements** down by one position.

- `rra`: Reverse rotate `A`.
    
    Example:
    
    **Before:** `A = [3, 1, 4, 2]`
    
    **After `rra` →** `A = [2, 3, 1, 4]`
    
- `rrb`: Reverse rotate `B`.
- `rrr`: Reverse rotate both `A` and `B`.
1. **Optimization Requirement**
    - The goal is **not just sorting** but sorting with **the fewest operations**.
    - Sorting 100 numbers should take **≤ 700 operations**.
    - Sorting 500 numbers should take **≤ 5500 operations**.

---

### **What is `checker_linux` or `checker_mac`?**

This is a **separate program** given in your project that acts as a **verifier**.

- You write your sorting algorithm using the operations above.
- Then, you **pipe** (send) the output of your program into `checker`, which will **check** if your solution actually sorts the stack correctly.
- It will print **"OK"** if sorted correctly and **"KO"** if not.

**Example usage:**

```
sh
CopyEdit
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG

```

- `ARG="3 2 1"` sets a sample stack.
- `./push_swap $ARG` runs your program, which prints the sequence of operations needed to sort the stack.
- The output is **piped (`|`)** into `./checker_linux`, which verifies if it is sorted.

---

## **Algorithm Strategies**

### **Brute Force (Not Feasible)**

- Generate all possible move sequences and check which sorts the stack with the least moves.
- infeasible due to *factorial complexity (O(n!))*.

### **Naïve Sorting (Not Optimal)**

- Bubble Sort or Insertion Sort using allowed operations.
- Too slow and inefficient for large inputs.

### Best Option is :

**greedy**, **divide-and-conquer**, and **graph search techniques** to minimize the number of operations.

Greedy Algorithm

An algorithm is greedy **when the path picked is regarded as the best option based on a specific criterion without considering future consequences! But it typically evaluates feasibility before making a final decision.**

Divide-and-Conquer Algorithm

A divide-and-conquer algorithm **recursively breaks down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly**. The solutions to the sub-problems are then combined to give a solution to the original problem.

Graph Search Techniques

A graph search (or traversal) technique visits every node exactly one in a systematic fashion. Two standard graph search techniques have been widely used: **Depth-First Search (DFS)** **Breadth-First Search (BFS)**

## OR!

## like I come to discover the *Turk Algorithm.*

This method involves **splitting the stack into smaller parts, sorting them, and then merging them back** efficiently. It's often implemented in **three steps**:

### **Step 1: Pushing Elements to Stack B (Partitioning)**

- You **move elements from A to B** in a structured way.
- Typically, you use **median values** or **bitwise sorting** (Radix sort method) to determine which numbers go first.

### **Step 2: Sorting Stack B**

- Since B receives elements in a specific order, sorting it requires fewer operations.
- Often, you sort it in descending order to facilitate merging back into A.

### **Step 3: Merging Back into Stack A**

- You **push elements from B back to A** in the correct order using `pa`, `ra`, and `rra`.
- This step efficiently reconstructs the sorted sequence.

---

## **Plan so far:**

### **Parse and Validate Input**

**What to do?**

- Read command-line arguments and store them in an array (linked list or dynamic array).
- Check for **errors**:
    - Only numbers (no letters or special characters).
    - No duplicates.
    - Handle large/small integers (within `int` limits).

**Example:**

```
bash
CopyEdit
./push_swap 3 2 1

```

 If input is invalid, print `Error` and exit.

---

### **Implement Stack Operations**

**What to do?**

Write functions for each operation (`sa`, `sb`, `ss`, `pa`, `pb`, etc.).

**Example Implementation (C - `sa`)**:

```c
c
void    sa(t_stack *a)
{
    if (a->size > 1)
        swap(&a->top->value, &a->top->next->value);
    write(1, "sa\n", 3);
}
```

➡️ Repeat this for all required operations.

---

### **Implement Sorting Strategy**

Use **Turk Algorithm** (or **Radix Sort** for large sets).

**For Small Lists (≤5 numbers):**

Use **hardcoded sorting** since a simple approach is optimal.

- **2 numbers:** Use `sa` if needed.
- **3 numbers:** Use **brute-force cases** (`sa`, `rra`, `ra` combinations).
- **4-5 numbers:**
    - Push smallest elements to `B` (`pb`).
    - Sort remaining in `A`.
    - Push back from `B` (`pa`).

**For Large Lists (100+ numbers)**

Use **Radix Sort (bitwise method)** or **Chunk Sorting**:

1. **Push numbers into `B` in chunks (using median or bitwise sorting).**
    - Example: Push numbers with `bit 0` first, then `bit 1`, etc.
2. **Sort B efficiently (descending order).**
3. **Push elements back into A in the correct order.**

---

### **Output the Moves**

- Your program must print the **list of operations** needed to sort stack `A`.
- Example:

```
b
pb
sa
pa
pa

```

⚠️ **Fewer moves = better score!**

---

### **Test with `checker_linux`**

Run:

```
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```

✔️ If sorted correctly → `"OK"`

❌ If incorrect → `"KO"`

---

### **Optimize (Fewer Moves)**

Once your program works:

- **Reduce redundant operations** (e.g., avoid unnecessary swaps).
- Use `rr`/`rrr` when possible instead of `ra + rb`.
- Improve the chunking strategy for larger inputs.

---

### **Final Testing and Submission**

- Run against **edge cases**:
    - Already sorted numbers.
    - Reverse order.
    - Random large lists.
- Submit the code to **intra**!

---

## **Bonus: Checker Program**

- Reads sorting instructions and applies them to `a`.
- Validates if `a` is sorted and `b` is empty.
- Outputs `"OK"` if sorted, `"KO"` otherwise.
