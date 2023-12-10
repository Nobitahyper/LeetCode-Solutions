class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(result, digits, current, 0, mapping);
        return result;
        
    }
    
    void backtrack(vector<string>& result, const string& digits, string& current, int index, const vector<string>& mapping) {
        // base case
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(result, digits, current, index + 1, mapping);
            current.pop_back();
        }
    }
};


