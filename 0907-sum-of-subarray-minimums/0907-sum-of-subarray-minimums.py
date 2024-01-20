class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(arr)
        stack = []
        prev_smaller = [-1]  * n
        next_smaller = [n] * n
        
        for i in range(n):
            while stack and arr[stack[-1]] > arr[i]:
                next_smaller[stack.pop()] = i
            if stack:
                prev_smaller[i] = stack[-1]
            stack.append(i)
            
        result = 0
        for i in range(n):
            result += arr[i] * (i - prev_smaller[i]) * (next_smaller[i] - i)
            result %= MOD
            
        return result
        
