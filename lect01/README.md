# Lecture 1: C++ Review + ADT Design

This lecture looks at the same idea, encapsulation and constructors,
through two different classes:

- `Complex` - a small ADT for numbers of the form a + jb, used to look
  at constructors: default parameters, copying, and what the compiler
  generates for you automatically.
- `CustomList` - a singly linked list ADT, built from nodes and raw
  pointers: the same plumbing that `std::list` hides from you.

## Files

- `main.cpp` - Activity 1: a flawed linked-list implementation
  ("playlist"). Find at least 3 problems with it, with a partner.
- `CustomList.h` / `CustomList.cpp` - Activity 2: the same idea, done
  well (tail pointer, encapsulated `Node`, a real destructor).
- `demo.cpp` - a small test program for `CustomList`, including a
  comparison with `std::list`.
- `Complex.h` / `Complex.cpp` - the `Complex` class.
- `complex_demo.cpp` - a small test program for `Complex`.
- `Makefile` - builds `playlist` (Activity 1), `demo`, and `complex_demo`.

## Build

```bash
make              # builds playlist, demo, and complex_demo
./playlist        # Activity 1 - the flawed version
./demo            # CustomList demo + std::list comparison
./complex_demo    # Complex demo
make clean
```
