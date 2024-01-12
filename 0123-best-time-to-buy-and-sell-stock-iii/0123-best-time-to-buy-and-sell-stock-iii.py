from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        firstBuy, firstSell = float('-inf'), 0
        secondBuy, secondSell = float('-inf'), 0

        for price in prices:
            firstBuy = max(firstBuy, -price)
            firstSell = max(firstSell, firstBuy + price)
            secondBuy = max(secondBuy, firstSell - price)
            secondSell = max(secondSell, secondBuy + price)

        return secondSell

# Example usage
sol = Solution()
print(sol.maxProfit([3,3,5,0,0,3,1,4]))  # Output: 6
print(sol.maxProfit([1,2,3,4,5]))        # Output: 4
print(sol.maxProfit([7,6,4,3,1]))        # Output: 0
