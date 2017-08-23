class Solution:
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        min_index_sum = sys.maxsize
        result = []
        list1_dict = {k: v for v, k in enumerate(list1)}
        for index, item in enumerate(list2):
            if index > min_index_sum:
                break
            if item in list1_dict:
                current_index_sum = index + list1_dict[item]
                if current_index_sum < min_index_sum:
                    min_index_sum = current_index_sum
                    result = []
                if current_index_sum == min_index_sum:
                    result.append(item)
        return result
