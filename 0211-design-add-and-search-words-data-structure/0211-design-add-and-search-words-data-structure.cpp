class WordDictionary {
public:
    struct TrieNode {
        std::vector<TrieNode*> children;
        bool endOfWord;
        TrieNode(): endOfWord(false), children(std::vector<TrieNode*>(26, nullptr)) {}
    };
    
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->endOfWord = true;
    }
    
    bool search(std::string word) {
        return searchInNode(word, root);
    }
    
    bool searchInNode(std::string word, TrieNode* node) {
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (c != '.') {
                if (node->children[c - 'a'] == nullptr) {
                    return false;
                }
                node = node->children[c - 'a'];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (node->children[j] != nullptr && searchInNode(word.substr(i+1), node->children[j])) {
                        return true;
                    }
                }
                return false;
            }
        }
        return node->endOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */