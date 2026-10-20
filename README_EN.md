# C++ Algorithms Coursework

This repository presents a curated collection of programs from an undergraduate
Algorithm Design and Analysis course.

The code is organised by algorithmic topic and uses descriptive English
filenames. It intentionally preserves the procedural, C-style C++ commonly
used in the original coursework, including native arrays, structures, global
variables, manual memory management, and both standard I/O and stream-based
I/O.

## Contents

| Chapter | Topic | Examples |
| --- | --- | --- |
| [`01-fundamentals`](01-fundamentals/) | Fundamentals | Armstrong numbers, perfect numbers |
| [`02-brute-force`](02-brute-force/) | Brute force | Target-score combinations, exhaustive travelling salesperson |
| [`03-divide-and-conquer`](03-divide-and-conquer/) | Divide and conquer | Merge sort, inversion counting, integer partitions, mode finding |
| [`04-sorting-and-heaps`](04-sorting-and-heaps/) | Sorting and heaps | Counting sort, quicksort, minimum gap, max-heap insertion |
| [`05-string-matching`](05-string-matching/) | String matching | Brute-force matching, Knuth-Morris-Pratt |
| [`06-dynamic-programming`](06-dynamic-programming/) | Dynamic programming | 0/1 knapsack, number triangle, maximum subarray, edit distance, longest common subsequence |
| [`07-greedy`](07-greedy/) | Greedy algorithms | Shortest waiting time, nearest-neighbour TSP, graph colouring |
| [`08-backtracking`](08-backtracking/) | Backtracking | N-queens, graph colouring, 0/1 knapsack, subset sum |

## Language and style

The repository contains primarily procedural C++ code. Several programs are
valid C or closely resemble C, while others use C++ features such as references,
streams, strings, and dynamic allocation. All curated source files retain the
`.cpp` extension used in the coursework.

The examples have deliberately not been rewritten as modern C++. Their original
style is part of the academic record and illustrates the progression from
basic procedural programming to classical algorithm design techniques.

## Building the programs

Each source file is a standalone program with its own `main` function. The GNU
C++17 dialect provides the best compatibility with the original coursework:

```bash
g++ -std=gnu++17 06-dynamic-programming/edit-distance.cpp -o edit-distance
./edit-distance
```

To perform a syntax check on every curated source file:

```bash
find 0[1-8]-* -name '*.cpp' -print0 | \
  xargs -0 -n1 g++ -std=gnu++17 -fsyntax-only
```

## Preservation approach

- Programs are grouped by algorithmic idea rather than by assignment date.
- Curated filenames and directory names use English `kebab-case`.
- Original procedural and C-style C++ techniques are retained.
- Legacy comments are encoded as UTF-8 for reliable display.
- Only minimal compilation repairs are applied to curated copies.
- Incomplete parser and debugging experiments are not presented as finished
  algorithms.

Some programs retain the assumptions, limitations, and compiler-dependent
constructs of their original academic context. They are provided as coursework
examples rather than as production-ready algorithm implementations.

## Topics covered

The collection demonstrates:

- exhaustive search and recursive enumeration;
- divide-and-conquer algorithms;
- comparison and counting-based sorting;
- heap construction and insertion;
- naive and prefix-based string matching;
- dynamic-programming state transitions and reconstruction;
- greedy scheduling and graph heuristics;
- constraint solving through backtracking.

## Purpose

This repository is intended to document undergraduate algorithm coursework,
preserve the original programming style, and provide a clear portfolio-friendly
overview of the algorithms studied.
