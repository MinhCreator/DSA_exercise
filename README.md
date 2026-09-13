# DSA_exercise

Data Structures and Algorithms coursework — C++ implementations (`assignment-*`, `lab-*`, `baiTap`) plus Java examples (`example/`, `25IT110_Bùi Võ Nhật Minh/`).

Remote: `https://github.com/MinhCreator/DSA_exercise.git`

Spec sheets (PDF/DOCX) live in `3. Assignment - Labs/` (`Assignment-01..10.pdf`, `Lab-01..08.pdf`). Code coverage is assignments 1–9 and labs 1–4.

## Repository structure

```text
DSA/
├── assignment-1/   # C++ basics: average, Roman numerals, pointer arithmetic
├── assignment-2/   # Complexity analysis (txt) + linear search sketch
├── assignment-3/   # Singly linked list: insert, set/subset ops
├── assignment-4/   # Stacks: binary conversion, string reverse, linked-list stack
├── assignment-5/   # Queues: array queue, linked-list queues
├── assignment-6/   # Searching & sorting: linear/binary search, insertion/selection/bubble/quick/merge
├── assignment-7/   # Trees: traversals, expression trees, counting, BST insert/delete
├── assignment-8/   # Heaps: build-max-heap, MinHeap / MaxHeap classes
├── assignment-9/   # Graphs: adjacency matrix, BFS/DFS, BFS/DFS trees
├── lab-01/         # Pointers/arrays, Student struct, gcd/lcm, dynamic array
├── lab-02/         # Singly linked list student manager, polynomial list
├── lab-03/         # Stack apps: infix→postfix, parenthesis checker, Josephus queue
├── lab-04/         # Sorting + searching suite, Student vector search
├── baiTap/         # File exercises: random gen, even/odd split + sort (generates *.txt)
├── example/        # Java: threads, file word-count, midterm prep (Giuaki_java)
├── 25IT110_Bùi Võ Nhật Minh/  # Java: threads, file rename, XML DOM parsing
├── 3. Assignment - Labs/      # Problem statements (PDF) + bundled zip
├── Uploading_an_Image_to_the_Database.md  # Java Swing/JDBC snippet (unrelated note)
└── .vscode/        # C/C++ VS Code config (Windows gcc path — see Notes)
```

## Contents detail

| Folder | Files | Topics |
|---|---|---|
| `assignment-1` | `pro1-assignment1.cpp`, `pro2-assignment1.cpp`, `pro3-assignment1.cpp` | Array average, Arabic→Roman, pointer-based calculator |
| `assignment-2` | `complexity-pro1.txt`, `complexity-pro2.txt`, `complexity-pro3.txt`, `pro-4.txt`, `assignment2.docx` | Big-O: nested loops, matrix add/mul/transpose, Min/linear-search analysis |
| `assignment-3` | `problem-1.cpp`, `problem-2.cpp` | `struct node` linked list, `insert_begin`/`insert_end`, set membership |
| `assignment-4` | `pro-2.cpp`, `pro-3.cpp`, `pro-4.cpp` | `std::stack` binary→decimal, stack vs recursive reverse, hand-rolled `push`/`pop` |
| `assignment-5` | `pro-1.cpp`, `pro-2.cpp`, `pro-3.cpp` | Array `myQueue` (enqueue/dequeue/overflow), linked `queue` (string/int) |
| `assignment-6` | `pro-1.cpp` … `pro-4.cpp` | Linear search, binary search, insertion/selection/bubble sort, Hoare `quick_sort` + `merge` |
| `assignment-7` | `pro-1.cpp` … `pro-4.cpp`, `pro-5-to-8.cpp` | In/pre/post-order, infix expression tree, `preToInfix`, count nodes/leaves, BST `insert`/`remove`/`levelOrder` |
| `assignment-8` | `Assignment8_1.cpp`, `Assignment8_2.cpp`, `Assignment8_3.cpp` | `heapify`/`buildMaxHeap`, `MinHeap` (insert/peek), `MaxHeap` (insert/extractMax) |
| `assignment-9` | `Assignment9_1.cpp`, `Assignment9_2.cpp`, `Assignment9_3.cpp` | Adjacency/weight matrix (7 vertices A–G), `BFS`/`DFS`, BFS/DFS tree edges |
| `lab-01` | `pro1-lab.cpp` … `pro4-lab.cpp` | Pointer array remove/removeOdd, `Student` char-array CRUD, `gcd`/`lcm`, `new[]` array |
| `lab-02` | `pro-1.cpp`, `pro-2.cpp` | Student linked list w/ file I/O (`StudentList.txt`), add/delete/search/max-avg; polynomial list |
| `lab-03` | `pro-1.cpp`, `pro-2.cpp`, `pro-3.cpp` | Infix→postfix (`operatorPrecedence`), `parentheseChecker`, Josephus via array queue |
| `lab-04` | `pro-01.cpp`, `pro-02.cpp` | Full sort/search suite (insert/selection/bubble/quick/merge, linear/binary) on `int*`; `Student` vector search |
| `baiTap` | `baitap.cpp`, `ran.cpp`, `random.cpp` + `original.txt`, `even.txt`, `odd.txt`, `merge.txt` | `rand()` gen 100 nums, split even/odd, `sort()`, write to txt |
| `example` | `calculateThread.java`, `ReadFile.java`, `Giuaki_java/Bai1..3.java` | Odd/even `Thread`s, word count via `BufferedReader`, midterm XML/file practice |
| `25IT110_Bùi Võ Nhật Minh` | `PrintConcurrent.java`, `RenameFile.java`, `xmlProcessing.java`, `student.xml` | Concurrent print 1–100, `Files.move` rename, DOM parse (`firstname/lastname/marks`) |

## Prerequisites

- `g++` with C++17 (code uses `<bits/stdc++.h>`, so GCC/MinGW recommended)
- JDK 8+ for the Java files
- Optional: VS Code + C/C++ extension (`.vscode/` provided)

Check tools:

```bash
g++ --version
java -version
```

## Build & run

### C++ (single file)

```bash
g++ -std=c++17 -g assignment-6/pro-3.cpp -o /tmp/pro-3
/tmp/pro-3
```

More examples:

```bash
g++ -std=c++17 -g lab-04/pro-01.cpp -o /tmp/lab04-pro01 && /tmp/lab04-pro01
g++ -std=c++17 -g assignment-8/Assignment8_1.cpp -o /tmp/a81 && /tmp/a81
g++ -std=c++17 -g assignment-9/Assignment9_2.cpp -o /tmp/a92 && /tmp/a92
```

> `*.exe` is git-ignored (`.gitignore`). On Linux/macOS output to a name without `.exe` as above.

### Java

```bash
# Top-level examples
javac example/ReadFile.java && java -cp example ReadFile
javac -d /tmp/classes example/calculateThread.java && java -cp /tmp/classes example.calculateThread

# Student folder (default package)
javac "25IT110_Bùi Võ Nhật Minh/RenameFile.java" && java -cp "25IT110_Bùi Võ Nhật Minh" RenameFile
javac "25IT110_Bùi Võ Nhật Minh/xmlProcessing.java" && java -cp "25IT110_Bùi Võ Nhật Minh" xmlProcessing
```

### `baiTap` file exercises

These programs create/overwrite `*.txt` in the working directory. Run them from a temp copy if you don't want to clobber the committed txt files:

```bash
mkdir -p /tmp/baitap && cp baiTap/baitap.cpp /tmp/baitap/ && cd /tmp/baitap
g++ -std=c++17 baitap.cpp -o baitap && ./baitap
```

## Notes / known issues

- `.vscode/tasks.json` hardcodes a Windows path (`C:\Users\Administrator\scoop\apps\gcc\...`). On Linux/macOS either compile manually (commands above) or update the task to `"command": "g++"`.
- Some `assignment-7` traversals take `std::vector<...> res` by value, so results are not propagated back to the caller — fine for coursework, but pass by reference for real use.
- `lab-01/pro4-lab.cpp` uses `delete arr;` on a `new[]` array; correct form is `delete[] arr;`.
- `lab-04/pro-01.cpp` `binarySearch` loops on `while (left <= size)` instead of `left <= right`; works for the demo call but is not a general binary search.
- `Uploading_an_Image_to_the_Database.md` is a standalone JDBC/Swing snippet, not part of the DSA assignments.
- Compiled artifacts present in repo (`*.class` in `example/Giuaki_java/`, `25IT110_Bùi Võ Nhật Minh/`): rebuild from source rather than running stale classes.
