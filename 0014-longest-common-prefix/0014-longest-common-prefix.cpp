class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if (strs.empty()) return "";

        // Take the length of the first string as the potential maximum length of the prefix
        int prefixLength = strs[0].length();

        for (int i = 1; i < strs.size(); i++) {
            prefixLength = min(prefixLength, (int)strs[i].length());
            for (int j = 0; j < prefixLength; j++) {
                if (strs[i][j] != strs[0][j]) {
                    prefixLength = j;
                    break;
                }
            }
        }

        return strs[0].substr(0, prefixLength); 
    }
};