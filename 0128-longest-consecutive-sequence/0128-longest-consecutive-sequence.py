class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        dict = {num: (num - 1, num + 1) for num in nums}
        max_len = 0
        
        for num in dict:
            if dict[num][0] in dict:
                continue
            
            cur_len = 1
            next_num = dict[num][1]
            
            while next_num in dict:
                cur_len += 1
                next_num = dict[next_num][1]
                
            max_len = max(max_len, cur_len)
            
        return max_len
            