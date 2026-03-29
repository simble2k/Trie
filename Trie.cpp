struct Node {
    Node* children[26];
    bool isEndOfWord;

    Node() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    Node* root;
    bool isEmpty(Node* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) return false;
        }
        return true;
    }

    Node* remove(Node* curr, string word, int depth) {
        if (!curr) return nullptr;
        
        if (depth == word.size()) {

            if (curr->isEndOfWord) curr->isEndOfWord = false;

            if (isEmpty(curr)) {
                delete curr;
                curr = nullptr;
            }

            return curr;
        }

        int index = word[depth] - 'a';
        curr->children[index] = remove(curr->children[index], word, depth + 1);

        if (isEmpty(curr) && curr->isEndOfWord == false) {
            delete curr;
            curr = nullptr;
        }

        return curr;
    }

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new Node();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }

    void remove(string word) {
        root = remove(root, word, 0);
    }
};