class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string word;
        TrieNode() : word("") {
            for (auto &a : child) a = nullptr;
        }
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> res;
        for(int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j< board[0].size(); j++)
            {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }

    private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res)
    {
        char c = board[i][j];
        if (c == '#' || p->child[c - 'a'] == nullptr) return;
        p = p->child[c - 'a'];
        if (p->word != "")
        {
            res.push_back(p->word);
            p->word = "";
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, res);
        if (j > 0) dfs(board, i, j - 1, p, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, res);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, res);
        board[i][j] = c;
    }
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(string &w : words) {
            TrieNode *p = root;
            for (char c : w) {
                int i = c - 'a';
                if(p->child[i] == nullptr) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->word = w;
        }
        return root;
    }
};
