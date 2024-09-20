from typing import List
from collections import deque

class Node:
    def __init__(self):
        self.children = {}
        self.fail = None
        self.depth = 0
        self.is_word = False
        self.accepting_depth = 0

class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        # Build the trie and automaton
        root = Node()
        for word in words:
            node = root
            for ch in word:
                if ch not in node.children:
                    child = Node()
                    child.depth = node.depth + 1
                    node.children[ch] = child
                node = node.children[ch]
                node.is_word = True  # All prefixes are valid

        # Build failure links and precompute accepting depths
        queue = deque()
        for node in root.children.values():
            node.fail = root
            node.accepting_depth = node.depth if node.is_word else 0
            queue.append(node)

        while queue:
            current_node = queue.popleft()
            for ch, child in current_node.children.items():
                fail_node = current_node.fail
                while fail_node != root and ch not in fail_node.children:
                    fail_node = fail_node.fail
                child.fail = fail_node.children[ch] if ch in fail_node.children else root
                # Update accepting_depth
                child.accepting_depth = child.depth if child.is_word else child.fail.accepting_depth
                queue.append(child)

        # Process the target string
        n = len(target)
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        node = root
        for i in range(n):
            ch = target[i]
            # Move to the next state
            while node != root and ch not in node.children:
                node = node.fail
            node = node.children[ch] if ch in node.children else root
            # Update dp[i + 1] using accepting_depth
            if node.accepting_depth > 0:
                idx = i + 1 - node.accepting_depth
                if dp[idx] + 1 < dp[i + 1]:
                    dp[i + 1] = dp[idx] + 1
        return dp[n] if dp[n] != float('inf') else -1
