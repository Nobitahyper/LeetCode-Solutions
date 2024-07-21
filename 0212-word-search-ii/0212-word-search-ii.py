class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False
        self.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        
        # Build the Trie
        for word in words:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.is_end_of_word = True
            node.word = word
        
        def dfs(x, y, node):
            char = board[x][y]
            if char not in node.children:
                return
            node = node.children[char]
            if node.is_end_of_word:
                found_words.add(node.word)
            
            board[x][y] = '#'  # Mark the cell as visited
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:  # Up, down, left, right
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and board[nx][ny] != '#':
                    dfs(nx, ny, node)
            board[x][y] = char  # Unmark the cell
            
        m, n = len(board), len(board[0])
        found_words = set()
        
        # Start DFS from each cell
        for i in range(m):
            for j in range(n):
                dfs(i, j, root)
        
        return list(found_words)


