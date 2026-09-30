# Lecture 2: Memory bugs, the Big Four, operator overloading

## Files

| File | Use |
|------|-----|
| `list_demo.cpp` | **One file** so students can read all of it: linked list broken on purpose (**no constructor**, so `head` is garbage; default shallow copy ctor/assignment; destructor calls `clear()`), then Demo 1 (build a list) and Demo 2 (copy a list) |
| `complex_bigfour.cpp` | Big Four on `Complex`, one small file. Copy ctor and `operator=` print, destructor does **not** |
| `solutions/list_demo.cpp` | Same file with the constructor, deep copy ctor and deep `operator=` added |

```bash
make            # builds listdemo and complex_bigfour
./listdemo
```

## Demo 1: uninitialized `head` (~10 min)

1. `make && ./listdemo` -> **segfault** (tested: crashes every time with `g++`/clang on macOS).
2. Ask "why did it crash?" Guesses land, then: "worse than null. Garbage."
3. LLDB: `run` -> `bt` (crash site is too late) -> `b CustomList::push_back` -> `run` -> `p head` (garbage before anything touches it) -> step into the `else`.
   In VS Code: set a breakpoint on the first line of `push_back`, run **Debug listdemo**, hover/inspect `head`.
4. Fix, one line, in `list_demo.cpp`: `CustomList() : head(nullptr) {}`

## Demo 2: shallow copy / double free (~15 min)

After the Demo 1 fix, `./listdemo` prints Demo 1 fine, then Demo 2 prints both lists, then
`leaving demo2...` and aborts (pointer being freed was not allocated / double free).

To make the double call visible, add this as the first line of `~CustomList()`
before debugging:

```cpp
cout << "~CustomList: destroying list at " << this << endl;
```

Print on entry (before freeing) so both messages appear before the abort.
Two different objects, one chain. The destructor did its job; the default copy planted the bug.
Fix: `solutions/list_demo.cpp` (deep copy ctor, `operator=` with self-check, `clear()`).


