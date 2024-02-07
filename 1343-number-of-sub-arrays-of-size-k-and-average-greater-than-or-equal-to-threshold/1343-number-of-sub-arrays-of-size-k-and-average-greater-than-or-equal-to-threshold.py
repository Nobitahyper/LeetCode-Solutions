class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        cur_sum = sum(arr[:k])
        target_sum = k * threshold
        count = 0
        
        if cur_sum >= target_sum:
            count += 1
            
        for i in range(k, len(arr)):
            cur_sum += arr[i] - arr[i - k]
            if cur_sum >= target_sum:
                count += 1
            
        return count