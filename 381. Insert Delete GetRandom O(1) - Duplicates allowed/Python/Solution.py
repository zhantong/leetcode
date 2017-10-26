class RandomizedCollection(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.nums = []
        self.memory = {}

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        is_already_in = True
        if val not in self.memory:
            is_already_in = False
            self.memory[val] = set()
        self.memory[val].add(len(self.nums))
        self.nums.append(val)
        return not is_already_in

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.memory:
            return False
        last_index = len(self.nums) - 1
        if last_index not in self.memory[val]:
            current_index = next(iter(self.memory[val]))
            last_value = self.nums[-1]
            self.memory[last_value].remove(last_index)
            self.memory[last_value].add(current_index)
            self.memory[val].remove(current_index)
            self.nums[current_index] = last_value
        else:
            self.memory[val].remove(last_index)
        if not self.memory[val]:
            del self.memory[val]
        self.nums.pop()
        return True

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        return random.choice(self.nums)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
