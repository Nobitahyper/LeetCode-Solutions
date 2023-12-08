class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }
        
        int word_len = words[0].size();
        int all_words_len = word_len * words.size();
        vector<int> result;
        
        for (int i = 0; i < word_len; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen;
            while (right + word_len <= s.size()) {
                string word = s.substr(right, word_len);
                right += word_len;
                if (word_count.find(word) != word_count.end()) {
                    seen[word]++;
                    if (seen[word] <= word_count[word]) {
                        count++;
                    }
                    while (seen[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        left += word_len;
                        if (seen[left_word] <= word_count[left_word]) {
                            count--;
                        }
                        seen[left_word]--;
                    }
                    if (count == words.size()) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};
