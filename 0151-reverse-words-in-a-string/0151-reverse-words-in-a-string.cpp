class Solution {
public:
    std::string reverseWords(std::string s) {
    std::vector<std::string> words;
    std::istringstream iss(s);
    std::string word;

    // Tokenize the string
    while (iss >> word) {
        words.push_back(word);
    }

    std::string result;
    for (int i = words.size() - 1; i >= 0; --i) {
        result += words[i];
        if (i > 0) {
            result += ' ';
        }
    }

    return result;
}
};