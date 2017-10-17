class Solution:
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """

        def binary_search(array, x):
            low = 0
            high = len(array) - 1
            while low <= high:
                mid = (low + high) // 2
                if array[mid] == x:
                    return mid
                elif array[mid] < x:
                    low = mid + 1
                else:
                    high = mid - 1
            return low

        j = binary_search(arr, x)
        i = j - 1
        while k > 0:
            if i < 0 or (j < len(arr) and arr[j] - x < x - arr[i]):
                j += 1
            else:
                i -= 1
            k -= 1
        return arr[i + 1:j]
