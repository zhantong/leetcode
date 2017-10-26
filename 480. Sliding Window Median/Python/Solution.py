class Solution(object):
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        min_heap = []
        max_heap = []
        result = []

        for i, num in enumerate(nums[:k]):
            heapq.heappush(max_heap, (-num, i))
        for _ in range(k - k // 2):
            heapq.heappush(min_heap, (-max_heap[0][0], max_heap[0][1]))
            heapq.heappop(max_heap)
        for i in range(k, len(nums)):
            num = nums[i]
            result.append(min_heap[0][0] / 1.0 if k %
                          2 else (min_heap[0][0] - max_heap[0][0]) / 2.0)
            if num >= min_heap[0][0]:
                heapq.heappush(min_heap, (num, i))
                if nums[i - k] <= min_heap[0][0]:
                    heapq.heappush(max_heap, (-min_heap[0][0], min_heap[0][1]))
                    heapq.heappop(min_heap)
            else:
                heapq.heappush(max_heap, (-num, i))
                if nums[i - k] >= min_heap[0][0]:
                    heapq.heappush(min_heap, (-max_heap[0][0], max_heap[0][1]))
                    heapq.heappop(max_heap)
            while max_heap and max_heap[0][1] <= i - k:
                heapq.heappop(max_heap)
            while min_heap and min_heap[0][1] <= i - k:
                heapq.heappop(min_heap)
        result.append(min_heap[0][0] / 1.0 if k % 2 else (min_heap[0][0] - max_heap[0][0]) / 2.0)
        return result
