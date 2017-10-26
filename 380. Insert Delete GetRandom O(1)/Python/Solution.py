class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.val_dict = {}
        self.vals = []

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.val_dict:
            return False
        self.val_dict[val] = len(self.vals)
        self.vals.append(val)
        return True

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.val_dict:
            return False
        index = self.val_dict[val]
        self.vals[index] = self.vals[-1]
        self.val_dict[self.vals[index]] = index
        del self.val_dict[val]
        self.vals.pop()
        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        return random.choice(self.vals)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
