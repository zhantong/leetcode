class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return self.majority_element(nums, 3)

    def majority_element(self, nums, k):
        counters = {}
        for num in nums:
            if num in counters:
                counters[num] += 1
            elif len(counters.keys()) < k - 1:
                counters[num] = 1
            else:
                for key, count in counters.items():
                    if count == 1:
                        del counters[key]
                    else:
                        counters[key] -= 1
        for num in counters.keys():
            counters[num] = 0
        for num in nums:
            if num in counters:
                counters[num] += 1
        target = len(nums) // k
        result = []
        for num, count in counters.items():
            if count > target:
                result.append(num)
        return result
