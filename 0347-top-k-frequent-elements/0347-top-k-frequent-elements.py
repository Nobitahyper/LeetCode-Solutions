from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ele_freq = Counter(nums)
        k_most = [e for e, count in ele_freq.most_common(k)]
        return k_most