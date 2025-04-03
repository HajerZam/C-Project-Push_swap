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

# **Push_swap Operations Implementation in C**

## **1. Data Structures**

Since we are working with stacks, we define a **linked list-based stack** structure.

```c
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

// Function Prototypes
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
t_stack *init_stack();
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    print_stack(t_stack *stack, char name);

#endif

```

---

## **2. Swap Operations (`sa`, `sb`, `ss`)**

Swap the first two elements of the stack.

```c
void sa(t_stack *a)
{
    t_node *temp;

    if (a->size < 2)
        return;
    temp = a->top->next;
    a->top->next = temp->next;
    temp->next = a->top;
    a->top = temp;
    write(1, "sa\\n", 3);
}

void sb(t_stack *b)
{
    t_node *temp;

    if (b->size < 2)
        return;
    temp = b->top->next;
    b->top->next = temp->next;
    temp->next = b->top;
    b->top = temp;
    write(1, "sb\\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    write(1, "ss\\n", 3);
}

```

---

## **3. Push Operations (`pa`, `pb`)**

Move the top element from one stack to another.

```c
void pa(t_stack *a, t_stack *b)
{
    int value;

    if (b->size < 1)
        return;
    value = pop(b);
    push(a, value);
    write(1, "pa\\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    int value;

    if (a->size < 1)
        return;
    value = pop(a);
    push(b, value);
    write(1, "pb\\n", 3);
}

```

---

## **4. Rotate Operations (`ra`, `rb`, `rr`)**

Move the first element to the last position.

```c
void ra(t_stack *a)
{
    t_node *temp, *last;

    if (a->size < 2)
        return;
    temp = a->top;
    a->top = a->top->next;
    temp->next = NULL;

    last = a->top;
    while (last->next)
        last = last->next;
    last->next = temp;

    write(1, "ra\\n", 3);
}

void rb(t_stack *b)
{
    t_node *temp, *last;

    if (b->size < 2)
        return;
    temp = b->top;
    b->top = b->top->next;
    temp->next = NULL;

    last = b->top;
    while (last->next)
        last = last->next;
    last->next = temp;

    write(1, "rb\\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    write(1, "rr\\n", 3);
}

```

---

## **5. Reverse Rotate Operations (`rra`, `rrb`, `rrr`)**

Move the last element to the first position.

```c
void rra(t_stack *a)
{
    t_node *prev, *last;

    if (a->size < 2)
        return;
    prev = NULL;
    last = a->top;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = a->top;
    a->top = last;

    write(1, "rra\\n", 4);
}

void rrb(t_stack *b)
{
    t_node *prev, *last;

    if (b->size < 2)
        return;
    prev = NULL;
    last = b->top;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = b->top;
    b->top = last;

    write(1, "rrb\\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\\n", 4);
}

```

---

## **6. Stack Helper Functions**

### **Initialize Stack**

```c
t_stack *init_stack()
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

```

### **Push to Stack**

```c
void push(t_stack *stack, int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

```

### **Pop from Stack**

```c
int pop(t_stack *stack)
{
    if (stack->size == 0)
        return -1;
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return value;
}

```

### **Print Stack (Debugging)**

```c
void print_stack(t_stack *stack, char name)
{
    t_node *temp = stack->top;
    printf("Stack %c: ", name);
    while (temp)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\\n");
}

```

---

# **Testing the Implementation**

### **Example Main Function**

```c
int main()
{
    t_stack *a = init_stack();
    t_stack *b = init_stack();

    // Push values to stack A
    push(a, 3);
    push(a, 2);
    push(a, 1);

    print_stack(a, 'A');

    sa(a);
    print_stack(a, 'A');

    pb(a, b);
    pb(a, b);
    print_stack(a, 'A');
    print_stack(b, 'B');

    pa(a, b);
    print_stack(a, 'A');
    print_stack(b, 'B');

    return 0;
}

```

---

---

### **What is `checker_linux` or `checker_mac`?**

This is a **separate program** given in your project that acts as a **verifier**.

- You write your sorting algorithm using the operations above.
- Then, you **pipe** (send) the output of your program into `checker`, which will **check** if your solution actually sorts the stack correctly.
- It will print **"OK"** if sorted correctly and **"KO"** if not.

**Example usage:**

```

ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG

```

- `ARG="3 2 1"` sets a sample stack.
- `./push_swap $ARG` runs your program, which prints the sequence of operations needed to sort the stack.
- The output is **piped (`|`)** into `./checker_linux`, which verifies if it is sorted.

---

## **Algorithm Strategies**

### Hybrid Radix Sort with Chunks

### Overview

implemented sorting algorithm is a hybrid approach combining **radix sort** with **chunk-based partitioning**. The main idea is to split the stack into manageable chunks and sort them efficiently using a greedy rotation strategy.

### Step 1: Splitting Stack A into Chunks

The elements of **stack A** are divided into `chunks` based on their index ranges. Each chunk represents a subset of elements that are pushed to **stack B** in an optimal order. The number of chunks is dynamically chosen based on the size of the input list:

- **Size > 500** → `11 chunks`
- **Size > 300** → `9 chunks`

### Function: `split_and_push_chunks`

This function handles chunk partitioning and pushes elements to **stack B** using an optimized push strategy.

```
void split_and_push_chunks(t_stack *a, t_stack *b, int chunks);
```

### Step 2: Optimized Push Strategy

The `optimized_chunk_push_b` function finds elements within a chunk’s range and pushes them to **stack B** efficiently. The function applies **greedy rotation** to minimize the number of moves required.

### Function: `optimized_chunk_push_b`

```
static void optimized_chunk_push_b(t_stack *a, t_stack *b, int min, int max);
```

- Uses **greedy rotations** to minimize movements.
- Pushes values to `b`, ensuring smaller numbers are moved deeper.

### Step 3: Pushing Elements Back to Stack A

Once all chunks have been moved to **stack B**, the elements must be returned to **stack A** in sorted order. The strategy is to always bring the **maximum value** in `B` to the top before pushing it back to `A`.

### Function: `push_back_to_a`

```
void push_back_to_a(t_stack *a, t_stack *b);
```

- Finds the **maximum element** in `B` using `find_max_index`.
- Rotates `B` to bring the maximum to the top.
- Pushes it back to `A`.

### Step 4: Final Radix Sorting

Once chunks are correctly placed, **radix sort** is used to ensure full sorting. The process involves examining each bit position from least significant to most significant and redistributing elements accordingly.

### Function: `radix_sort`

```
void radix_sort(t_stack *a, t_stack *b, int chunks);
```

- Uses bitwise operations for efficient sorting.
- Calls `split_and_push_chunks` to optimize chunk placement.
- Calls `push_back_to_a` to restore order.

### Summary

### Breaking Down the Functions

### **1️⃣ `find_target_index(a, min, max)`**

- Finds the **first element** in stack `A` whose value falls within `[min, max]`.
- Returns its **index position**.

### **2️⃣ `greedy_rotate_a(a, target_index)`**

- Moves that target element to the **top** of `A` using the **fewest moves**.
- If it's in the **first half**, rotate up (`ra`).
- If it's in the **second half**, rotate down (`rra`).

### **3️⃣ `optimized_chunk_push_b(a, b, min, max)`**

- **Repeats**:
    - Finds an element in `[min, max]`
    - Moves it to the top
    - Pushes it to `B`
    - If it's **small**, rotate `B` (`rb`) so smaller numbers stay at the bottom.

### **4️⃣ `split_and_push_chunks(a, b, chunks)`**

- **Divides** the stack into `chunks` and moves each chunk to `B` using `optimized_chunk_push_b`.
- Example:
    - If `A` has 100 elements and `chunks = 5`, then each chunk has ~20 elements.

### **5️⃣ `radix_sort(a, b, chunks)`**

- Decides how many **chunks** to use based on `A`'s size.
- Calls `split_and_push_chunks` to move elements from `A → B` in chunks.
- Calls `push_back_to_a(a, b)` to bring elements back **in sorted order**.

---

## **🛠 TL;DR Summary**

- **≤3 numbers** → Use `sa`, `ra`, `rra`.
- **≤5 numbers** → Move smallest to B, sort A, push back.
- **~100 numbers** → Use **greedy sorting** (push best elements to B).
- **~500 numbers** → Use **radix sort** (bitwise sorting, very fast).

---

---

## **TEST :**

---

### **Output the Moves**

- push_swap program must print the **list of operations** needed to sort stack `A`.
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

### **AutomatBibliotecae multiple runs & average:**

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
