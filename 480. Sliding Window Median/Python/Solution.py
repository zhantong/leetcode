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

        def get_median():
            if not max_heap and not min_heap:
                return 0
            if len(max_heap) == len(min_heap):
                return (min_heap[0] - max_heap[0]) / 2.0
            else:
                return float(min_heap[0])

        def add(num):
            if num < get_median():
                heapq.heappush(max_heap, -num)
            else:
                heapq.heappush(min_heap, num)
            if len(max_heap) > len(min_heap):
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
            elif len(min_heap) > len(max_heap) + 1:
                heapq.heappush(max_heap, -heapq.heappop(min_heap))

        def remove(num):
            if num < get_median():
                max_heap.remove(-num)
                heapq.heapify(max_heap)
            else:
                min_heap.remove(num)
                heapq.heapify(min_heap)
            if len(max_heap) > len(min_heap):
                heapq.heappush(min_heap, -heapq.heappop(max_heap))
            elif len(min_heap) > len(max_heap) + 1:
                heapq.heappush(max_heap, -heapq.heappop(min_heap))

        for i in range(len(nums) + 1):
            if i >= k:
                result.append(get_median())
                remove(nums[i - k])
            if i < len(nums):
                add(nums[i])
        return result
