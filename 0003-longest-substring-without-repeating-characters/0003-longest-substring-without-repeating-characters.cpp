class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, max_length = 0;
        unordered_set<char> current_chars;

        while (end < s.length())
        {
            if (current_chars.find(s[end]) == current_chars.end())
            {
                current_chars.insert(s[end]);
                max_length = max(max_length, end - start + 1);
                end++;
            }
            else {
                current_chars.erase(s[start]);
                start++;
            }
        }
        return max_length;
    }
};