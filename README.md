# Library Book Search Management System
**DSA Task 3 – Algorithm Battle: Which Data Structure Wins?**

## Application
A small library catalogue that stores Book ID, Book Name, and Author, and supports exact Book ID search.

## Implementations
- `bst.c`: Binary Search Tree with insertion, search comparison counting, inorder traversal, and height.
- `avl.c`: AVL self-balancing tree with LL, RR, LR, and RL rotations, search comparison counting, inorder traversal, and height.
- `hashing.c`: Hash table using `BookID % 40` and Linear Probing, insertion collision counting, search probe counting, and display.
- `dataset.csv` / `dataset.txt`: Same 30 records used by all three programs.
- `results.txt`: Results from compiling and running these programs with GCC. Re-run on your own system and retain your own outputs for your submission.
- `sample_test_outputs.txt`: Captured console output for the initial search and height/collision tests.

## Compile and run (GCC)
```bash
gcc bst.c -o bst
./bst

gcc avl.c -o avl
./avl

gcc hashing.c -o hashing
./hashing
```
On Windows, run `bst.exe`, `avl.exe`, and `hashing.exe` after compilation.

## Reproduce the experiment
For each program, before inserting the extra record:
1. Search for existing ID `115`.
2. Search for missing ID `999`.
3. Record tree height (BST and AVL) or insertion collision count (hashing).
4. Then insert the same extra record: ID `250`, name `DSA Advanced`, author `John Smith`.

Search comparison counts are the number of tree nodes inspected. Hash search probes are the number of table slots inspected. Hash insertion collisions count occupied slots encountered while inserting each unique key.

## Important interpretation
The supplied IDs are inserted in ascending order. This intentionally creates a worst-case, right-skewed BST, while AVL rotations keep the AVL balanced. Hashing is efficient for exact ID lookup under a suitable table size and load factor. AVL also supports ordered traversal; a hash table does not maintain sorted order.

## Student details
Before submission, edit the report cover page and add your name, registration number, department, semester, faculty name, and any required course details. Verify the compiled output on your own system and follow faculty rules for AI assistance and originality.
