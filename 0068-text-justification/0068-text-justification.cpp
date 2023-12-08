class Solution {
public:
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int index = 0;

    while (index < n) {
        int totalChars = words[index].length();
        int last = index + 1;

        while (last < n) {
            if (totalChars + words[last].length() + (last - index) > maxWidth) break;
            totalChars += words[last].length();
            last++;
        }

        int gaps = last - index - 1;
        string currentLine;

        if (last == n || gaps == 0) {
            for (int i = index; i < last; i++) {
                currentLine += words[i];
                if (i < last - 1) currentLine += " ";
            }
            while (currentLine.length() < maxWidth) {
                currentLine += " ";
            }
        } else {
            int spaces = (maxWidth - totalChars) / gaps;
            int extraSpaces = (maxWidth - totalChars) % gaps;

            for (int i = index; i < last - 1; i++) {
                currentLine += words[i];
                currentLine += string(spaces, ' ');
                if (extraSpaces-- > 0) {
                    currentLine += " ";
                }
            }
            currentLine += words[last - 1];
        }

        result.push_back(currentLine);
        index = last;
    }

    return result;
}

};



