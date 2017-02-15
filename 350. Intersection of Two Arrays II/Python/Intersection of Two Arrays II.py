class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1Dict = {}
        for num in nums1:
            if num not in nums1Dict:
                nums1Dict[num] = 0
            nums1Dict[num] += 1
        result = []
        for num in nums2:
            if num in nums1Dict and nums1Dict[num] != 0:
                result.append(num)
                nums1Dict[num] -= 1
        return result
