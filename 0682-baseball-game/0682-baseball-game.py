class Solution:
    def calPoints(self, operations: List[str]) -> int:
        res = []
        
        for op in operations:
            if op == '+':
                new_score = res[-1] + res[-2]
                res.append(new_score)
            
            elif op == 'D':
                res.append(2 * res[-1])
                
            elif op == 'C':
                res.pop()
                
            else:
                res.append(int(op))
                
        return sum(res)