class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        if not nums1 or not nums2 or not k:
            return []
        queue = []
        result = []
        heapq.heappush(queue, (nums1[0] + nums2[0], 0, 0))
        while queue and len(result) < k:
            current, i, j = heapq.heappop(queue)
            result.append([nums1[i], nums2[j]])
            if j < len(nums2) - 1:
                heapq.heappush(queue, (nums1[i] + nums2[j + 1], i, j + 1))
            if j == 0 and i < len(nums1) - 1:
                heapq.heappush(queue, (nums1[i + 1] + nums2[j], i + 1, j))
        return result
