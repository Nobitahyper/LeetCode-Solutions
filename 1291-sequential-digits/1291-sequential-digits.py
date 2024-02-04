class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        
        for start_digit in range(1, 10):
            num = start_digit
            next_digit = start_digit + 1
            
            while next_digit <= 9:
                num = num * 10 + next_digit
                if low <= num <= high:
                    res.append(num)
                next_digit += 1
                
        return sorted(res)
        