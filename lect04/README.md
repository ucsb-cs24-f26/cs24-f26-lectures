# Lecture 4: STL tour (after the 35-min quiz)

Goal: students leave knowing the four STL containers, what each operation costs, where to read
the docs, and wanting to know how `std::set` works. No benchmarks in class: they time it themselves.

You type ~25 lines (`solutions/stl_tour.cpp`). Big-O table goes on a slide. Timing is a student
exercise (`timing_lab.cpp`, key in `solutions/timing_lab.cpp`).

## Timing box (35 min)

| Beat | Min |
|------|-----|
| Hook poll | 2 |
| `vector` | 5 |
| `list` (+ `forward_list` as one sentence) | 4 |
| `set` | 6 |
| Big-O table slide | 5 |
| Template `print` (read, don't type) | 2 |
| Docs | 3 |
| Close + tree teaser | 3 |
| Total | 30 (5 min buffer) |

If over: skip the template beat, then make Docs a screenshot.

## Hook (2 min)

"Music app, a million songs. A) add the newest to the front, B) is song X in the library?,
C) show everything sorted, no duplicates. Which container?" Poll. Don't answer yet.

## `vector` (5 min)

`push_back` three values, `v[1]` vs `v.at(1)` (`at` checks the bounds and throws, `[]` doesn't),
`v.insert(v.begin(), 5)`, then `print(v)`. Ask "who moved everything over?"
Say: resizable array, fast index, costly to insert at the front or middle.

## `list` and `forward_list` (4 min)

`push_back`, `push_front`, then insert through an iterator (`auto it = l.begin(); ++it; l.insert(it, 7);`).
Uncomment `l[2]`: **compile error**. "To reach index 2 you'd walk there, so the interface doesn't offer it."
`forward_list`, one sentence, no code: "no `push_back`, no `size()`; it's the list you built in lecture 1."

## `set` (6 min)

Insert 5, 1, 5, 3 then `print(s)` -> `[1, 3, 5]`. Ask "who sorted that? where did the second 5 go?"
`count`, `find(3) != end()`, `erase`. Uncomment `s[0]` and `s.push_back(9)`: compile errors.
"The set decides where things go." Don't explain how yet.

## Big-O table (slide, 5 min)

| Operation | vector | list | forward_list | set |
|-----------|--------|------|--------------|-----|
| Index `[i]` | O(1) | n/a | n/a | n/a |
| Add at back | O(1)* | O(1) | n/a | n/a |
| Add at front | O(n) | O(1) | O(1) | n/a |
| Insert at a position you hold | O(n) | O(1) | O(1) | n/a |
| Insert a value (keeps sorted, unique) | n/a | n/a | n/a | O(log n) |
| Find a value | O(n) | O(n) | O(n) | O(log n) |

\* amortized. Walk it with the hook: A -> `list`, B -> `set`, C -> `set`.
"Don't take my word for it" -> hand out `timing_lab.cpp`.

## Template `print` (2 min, no typing)

Show the pre-written `print` once: "one function, any container, any element type. The compiler
writes the right version for each call. `vector<int>` is the same idea: `vector` is a template, `int`
fills the blank." Stop there.

## Docs (3 min)

cppreference.com -> Containers library (comparison table). Open `std::set` -> `insert` -> **Complexity**.
"Don't guess the cost, read the Complexity line."

## Close (3 min)

`std::set` is O(log n) to find and insert. How can it stay sorted without moving anything? Draw a
3-node tree (2, with 1 and 3 hanging off it). "That's a balanced binary search tree. We'll build one."

Takeaway slide: pick the container by what you do most; the docs list the cost; `std::set` is a tree.

## Student exercise: `timing_lab.cpp` (homework / lab)

Predict from the table, then measure: insert N at the front of `vector` vs `list`; double N and
see how each grows; 1000 lookups in `vector` (`find`) vs `set`. Build with `make` (it uses `-O2`).
Key output (this Mac): at N = 20k / 40k / 80k, vector front-insert takes ~20 / ~68 / ~355 ms and
list stays around 1 ms; vector lookups ~10 / ~19 / ~39 ms (linear) vs set ~0.1-0.2 ms.
List times are tiny and noisy, so tell students to look at the trend, not exact numbers.

## Don't

Run live benchmarks. Explain iterators or templates at length. Explain red-black trees.
