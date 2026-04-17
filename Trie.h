#ifndef TRIE_H
#define TRIE_H

#include <string>

struct Node {
    Node* children[26];
    bool isEndOfWord;
    Node();
};

class Trie {
private:
    Node* root;
    bool isEmpty(Node* node);
    Node* remove(Node* curr, std::string word, int depth);
public:
    Trie();
    void insert(std::string word);
    bool search(std::string word);
    void remove(std::string word);
};

#endif // TRIE_H
