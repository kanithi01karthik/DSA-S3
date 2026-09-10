# Data Structures & Algorithms Lab (Semester 3)

Repository containing code implementations and assignments for the Data Structures & Algorithms (DSA) Laboratory course (Semester 3) at **Dr. B. R. Ambedkar National Institute of Technology, Jalandhar (NITJ)**.

---

## 📁 Repository Structure

| Directory | Topic / Contents | Key Files |
|-----------|------------------|-----------|
| **[Lab 1](Lab1/)** | File Handling & Sorting | Merge sort (`bin.c`), file-based processing (`dsa1.c`) |
| **[Lab 2](Lab2/)** | Array Operations & Matrices | Dynamic insert/delete (`insdel.c`), array rotation (`rotatek.c`), second extrema (`secondextrema.c`), sparse matrix representation (`sparsematrix.c`) |
| **[Lab 3](Lab3/)** | Arrays & Stack Applications | Min/max bounds (`a.c`), frequency map (`b.c`), duplicate detection (`c.c`), matrix flattening (`d.c`), largest rectangle in histogram via monotonic stack (`e.c`) |
| **[Lab 4](Lab4/)** | Sparse Matrices & Linked Lists | Sparse matrix addition (`a.c`), cyclic sort/missing positive (`b.c`), array union/intersection (`c.c`), run-length encoding (`d.c`), singly linked list basics (`e.c`) |
| **[Lab 5](Lab5/)** | Linked Lists | Singly linked list reversal (`a.c`), doubly linked list operations (`b.c`) |
| **[Lab 6](Lab6/)** | Advanced Linked Lists | Circular linked list (`a.c`), polynomial arithmetic via linked list (`b.c`), doubly linked playlist manager (`c.c`), priority queue (`d.c`) |

---

## 🚀 How to Run

All programs are implemented in C. You can compile and run any program using GCC:

```bash
# Compile
gcc Lab1/dsa1.c -o dsa1

# Run
./dsa1
```

For AddressSanitizer (memory debugging):
```bash
gcc -fsanitize=address -g Lab4/a.c -o a_asan
./a_asan
```

---

## 📄 License

This repository is licensed under the [MIT License](LICENSE).
