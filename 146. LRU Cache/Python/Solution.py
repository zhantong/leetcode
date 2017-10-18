class LRUCache(object):
    class Node():
        def __init__(self, key, value):
            self.key = key
            self.val = value
            self.prev = None
            self.next = None

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.memory = {}
        self.head = self.Node(-1, -1)
        self.tail = self.Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.memory:
            return -1
        node = self.memory[key]
        self.to_head(node)
        return node.val

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.memory:
            node = self.memory[key]
            node.val = value
            self.to_head(node)
        else:
            if len(self.memory) == self.capacity:
                del self.memory[self.tail.prev.key]
                self.remove(self.tail.prev)
            node = self.Node(key, value)
            self.memory[key] = node
            self.add(node)

    def to_head(self, node):
        self.remove(node)
        self.add(node)

    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def add(self, node):
        node.next = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next.prev = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
