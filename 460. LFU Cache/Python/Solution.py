class LFUCache(object):
    class Node:
        def __init__(self, key, value, times):
            self.key = key
            self.value = value
            self.times = times
            self.prev = None
            self.next = None

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.init_capacity = capacity
        self.capacity = capacity
        self.memory_nodes = {}
        self.memory_times = {}
        self.head = self.Node(-1, -1, -1)
        self.tail = self.Node(-1, -1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.memory_nodes:
            return -1
        self.put(key, self.memory_nodes[key].value)
        return self.memory_nodes[key].value

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if self.init_capacity == 0:
            return
        if key in self.memory_nodes:
            node = self.memory_nodes[key]
            node.value = value

            if node.times + 1 in self.memory_times:
                if self.memory_times[node.times] != node:
                    node.prev.next = node.next
                    node.next.prev = node.prev
                else:
                    if node.next.times == node.times:
                        self.memory_times[node.times] = node.next
                        node.prev.next = node.next
                        node.next.prev = node.prev
                    else:
                        del self.memory_times[node.times]
                        node.prev.next = node.next
                        node.next.prev = node.prev
                node.prev = self.memory_times[node.times + 1].prev
                node.next = self.memory_times[node.times + 1]
                node.next.prev = node
                node.prev.next = node
                self.memory_times[node.times + 1] = node
            else:
                if self.memory_times[node.times] != node:
                    node.prev.next = node.next
                    node.next.prev = node.prev
                    node.prev = self.memory_times[node.times].prev
                    node.next = self.memory_times[node.times]
                    node.next.prev = node
                    node.prev.next = node
                    self.memory_times[node.times + 1] = node
                else:
                    if node.next.times == node.times:
                        self.memory_times[node.times] = node.next
                        self.memory_times[node.times + 1] = node
                    else:
                        del self.memory_times[node.times]
                        self.memory_times[node.times + 1] = node
            node.times += 1
        else:
            node = self.Node(key, value, 1)
            self.memory_nodes[key] = node
            if self.capacity == 0:
                node_to_remove = self.tail.prev
                if self.memory_times[node_to_remove.times] == node_to_remove:
                    del self.memory_times[node_to_remove.times]
                node_to_remove.prev.next = node_to_remove.next
                node_to_remove.next.prev = node_to_remove.prev
                del self.memory_nodes[node_to_remove.key]
                self.capacity += 1
            if 1 in self.memory_times:
                node.prev = self.memory_times[1].prev
                node.next = self.memory_times[1]
                node.next.prev = node
                node.prev.next = node
                self.memory_times[1] = node
            else:
                node.prev = self.tail.prev
                node.next = self.tail
                node.next.prev = node
                node.prev.next = node
                self.memory_times[1] = node
            self.capacity -= 1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
