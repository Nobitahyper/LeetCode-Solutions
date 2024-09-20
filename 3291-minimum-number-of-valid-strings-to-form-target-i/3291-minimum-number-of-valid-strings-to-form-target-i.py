class TrieNode:
    def __init__(self):
        self.children = {}

class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        # Build Trie of all prefixes
        root = TrieNode()
        for word in words:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
                # All prefixes are valid; we don't need to mark the end of word

        n = len(target)
        dp = [float('inf')] * (n + 1)
        dp[0] = 0  # Base case: empty string requires 0 valid strings

        for i in range(n):
            if dp[i] != float('inf'):
                node = root
                j = i
                while j < n and target[j] in node.children:
                    node = node.children[target[j]]
                    j += 1
                    dp[j] = min(dp[j], dp[i] + 1)
                # No need to proceed further if the character is not in Trie
        return dp[n] if dp[n] != float('inf') else -1
