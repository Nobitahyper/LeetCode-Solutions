class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_count, window_count;
        for( char c : t)
        {
            t_count[c]++;
        }

        int left = 0, right = 0;
        int required = t_count.size();
        int formed = 0;
        int min_len = INT_MAX;
        int min_left = 0;
        while (right < s.size())
        {
            char c = s[right];
            window_count[c]++;
            if (t_count.count(c) && window_count[c] == t_count[c])
            {
                formed++;
            }

            while (left <= right && formed == required)
            {
                if (right - left + 1 < min_len)
                {
                    min_len = right - left + 1;
                    min_left = left;
                }
                char d = s[left];
                window_count[d]--;
                if (t_count.count(d) && window_count[d] < t_count[d])
                {formed--; }
                left++;
            }
            right++;
        }
        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};