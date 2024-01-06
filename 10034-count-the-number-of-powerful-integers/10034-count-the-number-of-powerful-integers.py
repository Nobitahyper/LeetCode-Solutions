from functools import cache

class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        if not all(int(a) <= limit for a in s):
            return 0

        @cache
        def dp(i, mx):
            if len(mx) - i == len(s):
                return mx[-len(s):] >= s
            if len(mx) - i < len(s):
                return 0
            ans = 0
            for dig in range(limit + 1):
                if dig == 0 and i == 0:
                    continue
                if str(dig) <= mx[i]:
                    ans += dp(i + 1, 'A' * len(mx) if str(dig) < mx[i] else mx)
            return ans

        def solve(mx):
            ans = 0
            for x in range(len(str(mx))):
                ans += dp(0, "A" * x)
            ans += dp(0, str(mx))
            return ans

        return solve(finish) - solve(start - 1)


    

