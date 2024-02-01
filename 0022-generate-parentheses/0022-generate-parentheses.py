class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def backtrack(res, cur, opn, close, size):
            if len(cur) == size * 2:
                res.append(cur)
                return
            
            if opn < size:
                backtrack(res, cur + '(', opn + 1, close, size)
                
            if close < opn:
                backtrack(res, cur + ')', opn, close + 1, size)
                
            
        result = []
        backtrack(result, '', 0, 0, n)
        return result