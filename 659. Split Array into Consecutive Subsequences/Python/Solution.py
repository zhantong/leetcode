class Solution:
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        counts = {}
        for num in nums:
            if num not in counts:
                counts[num] = 0
            counts[num] += 1
        needs = {}
        for num in nums:
            if counts[num] == 0:
                continue
            if num in needs and needs[num] > 0:
                needs[num] -= 1
                if num + 1 not in needs:
                    needs[num + 1] = 0
                needs[num + 1] += 1
            elif num + 1 in counts and counts[num + 1] > 0 and num + 2 in counts and counts[num + 2] > 0:
                counts[num + 1] -= 1
                counts[num + 2] -= 1
                if num + 3 not in needs:
                    needs[num + 3] = 0
                needs[num + 3] += 1
            else:
                return False
            counts[num] -= 1
        return True
