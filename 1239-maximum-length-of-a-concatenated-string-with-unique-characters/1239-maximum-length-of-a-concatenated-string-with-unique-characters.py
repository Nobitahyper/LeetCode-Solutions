class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def bitmask(s):
            mask = 0
            for char in s:
                bit = 1 << (ord(char) - ord('a'))
                if mask & bit:
                    return 0
                mask |= bit
                
            return mask
        
        def backtrack(pos, current_mask):
            if pos == len(arr):
                return bin(current_mask).count('1')
            
            max_len = backtrack(pos + 1, current_mask)
            
            mask = bitmask(arr[pos])
            if mask and not (current_mask & mask):
                max_len = max(max_len, backtrack(pos + 1, current_mask | mask))
                
            return max_len
        
        return backtrack(0, 0)
        
        
        
        
