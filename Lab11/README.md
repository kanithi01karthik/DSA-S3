# Lab 11

Karthik Kanithi · 25117029

Compile each file on its own, for example `gcc -std=c11 Lab11/b.c -o /tmp/lab11b`. Keep `tree.h` in the same folder as the source files.

| File | Input |
| --- | --- |
| `a.c` | `n`, then `n` integers. |
| `b.c` | One level-order line. |
| `c.c` | One level-order line, then `S` and `K` on separate lines. |
| `d.c` | One BST level-order line, then one line of ranks. |
| `e.c` | `BUILD [scores]`, then `CONVERT` and one command per line, such as `NEXT 30`, `PREV 30`, `RANGE 25 60`, or `KTH 5`. |

Level-order lists use `-1` for a missing child and may omit trailing missing children. Lists accept commas or whitespace. A missing score, neighbor, or rank prints `NULL`.

## Complexity

- **Heap sort.** Building the max heap takes O(n) time. Sorting takes O(n log n) time and O(1) auxiliary space.
- **Threaded tree.** Conversion uses temporary return links during the inorder walk and fills the missing child pointers in place. Conversion and threaded inorder traversal each take O(n) time and O(1) auxiliary space after the input tree is built.
- **Rooms at distance K.** Breadth-first search uses a separate parent array. It takes O(n) time and O(n) auxiliary space.
- **Product catalogue.** A single inorder query takes O(h + k) time for a valid rank, O(n) time in the worst case, and O(h) auxiliary space, where h is the tree height. Repeating it for q ranks can take O(nq). Caching the inorder values takes O(n + q) time for all ranks and O(n) auxiliary space, excluding the input queries. An O(h)-space inorder walk can also answer a batch in O(n + q) time if the ranks already arrive sorted. Subtree sizes stored in the nodes would support online queries in O(h) time and O(1) working space after preprocessing.
- **Autocomplete.** Ordinary insertion can take O(nh) time and becomes quadratic on sorted input. This implementation sorts the node pointers by score, then uses insertion order to build the same BST in O(n log n) time and O(n) auxiliary space regardless of height. Conversion takes O(n) time and O(1) auxiliary space. After an O(log n) score lookup, `NEXT` and `PREV` follow a thread when present. On a side with a child, the adjacent index entry avoids an O(h) subtree descent. Reporting r scores takes O(log n + r) time. The same index answers `KTH` in O(1) time. With threads alone, finding the k-th score can take O(h + k) time and O(1) auxiliary space.
