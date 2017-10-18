class AllOne(object):
    class Node:
        def __init__(self):
            self.prev = None
            self.next = None
            self.keys = set()

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.keys = {}
        self.times = {}
        self.max_time = 0
        self.min_time = sys.maxsize
        self.head = self.Node()
        self.tail = self.Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        if key in self.keys:
            time = self.keys[key]
            self.times[time].keys.remove(key)
            new_time = time + 1
            if new_time not in self.times:
                node = self.Node()
                node.prev = self.times[time].prev
                node.next = self.times[time]
                node.prev.next = node
                node.next.prev = node
                self.times[new_time] = node
            self.times[new_time].keys.add(key)
            self.keys[key] = new_time
            if not self.times[time].keys:
                node = self.times[time]
                node.prev.next = node.next
                node.next.prev = node.prev
                del self.times[time]
        else:
            if 1 not in self.times:
                node = self.Node()
                node.prev = self.tail.prev
                node.next = self.tail
                node.prev.next = node
                node.next.prev = node
                self.times[1] = node
            self.times[1].keys.add(key)
            self.keys[key] = 1

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        if key not in self.keys:
            return
        time = self.keys[key]
        self.times[time].keys.remove(key)
        new_time = time - 1
        if new_time > 0:
            if new_time not in self.times:
                node = self.Node()
                node.prev = self.times[time]
                node.next = self.times[time].next
                node.prev.next = node
                node.next.prev = node
                self.times[new_time] = node
            self.times[new_time].keys.add(key)
            self.keys[key] = new_time
        else:
            del self.keys[key]
        if not self.times[time].keys:
            node = self.times[time]
            node.prev.next = node.next
            node.next.prev = node.prev
            del self.times[time]

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        if self.head.next == self.tail:
            return ''
        return next(iter(self.head.next.keys))

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        if self.tail.prev == self.head:
            return ''
        return next(iter(self.tail.prev.keys))


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
