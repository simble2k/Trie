class NaiveDictionary {
private:
    vector<string> dict;
public:
    void insert(const string& word) {
        dict.push_back(word);
    }
    
    bool search(const string& word) {
        for (const string& w : dict) {
            if (w == word) return true;
        }
        return false;
    }
};