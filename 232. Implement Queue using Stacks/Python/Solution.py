class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack_a = []
        self.stack_b = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.stack_a.append(x)

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if self.stack_b:
            return self.stack_b.pop()
        else:
            while self.stack_a:
                self.stack_b.append(self.stack_a.pop())
            return self.stack_b.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if self.stack_b:
            return self.stack_b[-1]
        else:
            while self.stack_a:
                self.stack_b.append(self.stack_a.pop())
            return self.stack_b[-1]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return not self.stack_a and not self.stack_b


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
