class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        rows, cols = len(matrix), len(matrix[0])
        for r in range(rows):
            for c in range(1, cols):
                matrix[r][c] += matrix[r][c - 1]

        count = 0
        for c1 in range(cols):
            for c2 in range(c1, cols):
                cum_sum = {0: 1}
                cur, cur_count = 0, 0
                for r in range(rows):
                    cur += matrix[r][c2] - (matrix[r][c1 - 1] if c1 > 0 else 0)
                    cur_count += cum_sum.get(cur - target, 0)
                    cum_sum[cur] = cum_sum.get(cur, 0) + 1
                count += cur_count

        return count
        
        
        
