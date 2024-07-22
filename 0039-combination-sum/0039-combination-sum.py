class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        
        def backtrack(i, cur, total):
            # base case
            if total == target:
                res.append(cur.copy())
                return
                
            # 2nd base case (out of index or sum)
            if i >= len(candidates) or total > target:
                return

            # 1st decision to include same number
            cur.append(candidates[i])
            backtrack(i, cur, total + candidates[i])
            
            # cleaning up
            cur.pop()
            # 2nd decision (to include other num)
            backtrack(i + 1, cur, total)
            
        backtrack(0, [], 0)
        return res
            