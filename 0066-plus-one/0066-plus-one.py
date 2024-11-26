class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        number = int("".join(map(str, digits)))
        res = number + 1
        return [int(digit) for digit in str(res)]