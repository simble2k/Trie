class Node:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        curr = self.root
        for char in word:
            if char not in curr.children:
                curr.children[char] = Node()
            curr = curr.children[char]
        curr.is_end_of_word = True

    def search(self, word: str) -> bool:
        curr = self.root
        for char in word:
            if char not in curr.children:
                return False
            curr = curr.children[char]
        return curr.is_end_of_word

    def remove(self, word: str) -> None:
        self._remove_recursive(self.root, word, 0)

    def _remove_recursive(self, curr: Node, word: str, depth: int) -> Node:
        if not curr:
            return None

        if depth == len(word):
            if curr.is_end_of_word:
                curr.is_end_of_word = False

            return None if not curr.children else curr

        char = word[depth]
        if char not in curr.children:
            return curr

        curr.children[char] = self._remove_recursive(curr.children[char], word, depth + 1)

        if curr.children[char] is None:
            del curr.children[char]

        if not curr.children and not curr.is_end_of_word:
            return None

        return curr