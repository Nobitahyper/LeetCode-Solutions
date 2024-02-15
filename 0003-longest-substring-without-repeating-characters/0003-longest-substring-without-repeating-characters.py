class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = 0
        L = 0
        arr = set()
        
        for R in range(len(s)):
            while s[R] in arr:
                arr.remove(s[L])
                L += 1
            arr.add(s[R])
            length = max(R - L + 1, length)
            
        return length
                