class Solution:
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        heap = []
        end = -sys.maxsize
        for index, num in enumerate(nums):
            end = max(end, num[0])
            heapq.heappush(heap, (num[0], index, 0))
        start = heap[0][0]
        temp_end = end
        while len(heap) == len(nums):
            current = heapq.heappop(heap)
            if current[2] + 1 < len(nums[current[1]]):
                temp_end = max(temp_end, nums[current[1]][current[2] + 1])
                heapq.heappush(heap, (nums[current[1]][current[2] + 1],
                                      current[1], current[2] + 1))
                if temp_end - heap[0][0] < end - start:
                    start = heap[0][0]
                    end = temp_end
        return [start, end]
