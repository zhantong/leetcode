class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        result = []
        people.sort(key=lambda item: (-item[0], item[1]))
        for person in people:
            result.insert(person[1], person)
        return result
