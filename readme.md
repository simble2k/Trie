## Trie Library Usage

This repository provides a Trie (prefix tree) implementation in both C++ and Python.

---

### C++: Trie.cpp

#### Usage
1. Include `Trie.cpp` in your project or copy the `Trie` class definition.
2. Use the `Trie` class as follows:

```cpp
#include "Trie.cpp" // or copy the class definition
#include <iostream>
using namespace std;

int main() {
	Trie trie;
	trie.insert("apple");
	cout << trie.search("apple") << endl; // 1 (true)
	trie.remove("apple");
	cout << trie.search("apple") << endl; // 0 (false)
	return 0;
}
```

#### Functions
- `void insert(string word)`: Insert a word into the trie.
- `bool search(string word)`: Return true if the word exists in the trie.
- `void remove(string word)`: Remove a word from the trie.

---

### Python: Trie.py

#### Usage
1. Import `Trie` from `Trie.py` or copy the class definition.
2. Use the `Trie` class as follows:

```python
from Trie import Trie

trie = Trie()
trie.insert("apple")
print(trie.search("apple"))  # True
trie.remove("apple")
print(trie.search("apple"))  # False
```

#### Functions
- `insert(word: str) -> None`: Insert a word into the trie.
- `search(word: str) -> bool`: Return True if the word exists in the trie.
- `remove(word: str) -> None`: Remove a word from the trie.
