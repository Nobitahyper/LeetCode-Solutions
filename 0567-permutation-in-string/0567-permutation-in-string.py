class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        len_s1, len_s2 = len(s1), len(s2)
        if len_s1 > len_s2: return False
        
        freq_s1 = Counter(s1)
        freq_window = Counter(s2[:len_s1 - 1])
        
        for i in range(len_s1 - 1, len_s2):
            freq_window[s2[i]] += 1
            
            if freq_window == freq_s1:
                return True
            
            freq_window[s2[i - len_s1 + 1]] -= 1
            
            if freq_window[s2[i - len_s1 + 1]] == 0:
                del freq_window[s2[i - len_s1 + 1]]
                
        return False
            