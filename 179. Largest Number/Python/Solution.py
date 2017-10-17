class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        strs = [str(num) for num in nums]
        strs.sort(lambda x, y: 1 if x + y < y + x else -1 if x + y > y + x else 0)
        if strs[0] == '0':
            return '0'
        return ''.join(strs)
