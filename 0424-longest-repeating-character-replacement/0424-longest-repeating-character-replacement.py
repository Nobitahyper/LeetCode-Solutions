class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count_map = {}
        L, most_freq, res = 0, 0, 0
        
        for R in range(len(s)):
            count_map[s[R]] = count_map.get(s[R], 0) + 1
            most_freq = max(most_freq, count_map[s[R]])
            
            if (R - L + 1) - most_freq > k:
                count_map[s[L]] -= 1
                L += 1
                
            res = max(res, R - L + 1)
            
        return res
        