class ListNode:
    def __init__(self, key = 0, value = 0):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.map = {}
        self.head = ListNode()
        self.tail = ListNode()
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def add_node(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
        
    def remove_node(self, node):
        prev = node.prev
        next = node.next
        prev.next = next
        next.prev = prev
        
    def move_to_head(self, node):
        self.remove_node(node)
        self.add_node(node)
        
    def pop_tail(self):
        node = self.tail.prev
        self.remove_node(node)
        return node
    
    
    def get(self, key: int) -> int:
        node = self.map.get(key, None)
        if not node:
            return -1
        
        self.move_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        node = self.map.get(key)
        
        if not node:
            newNode = ListNode(key, value)
            self.map[key] = newNode
            self.add_node(newNode)
            
            if len(self.map) > self.capacity:
                tail = self.pop_tail()
                del self.map[tail.key]
        else:
            node.value = value
            self.move_to_head(node)
            


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)