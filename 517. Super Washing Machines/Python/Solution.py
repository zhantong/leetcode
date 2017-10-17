class Solution(object):
    def findMinMoves(self, machines):
        """
        :type machines: List[int]
        :rtype: int
        """
        sum_up = sum(machines)
        if sum_up % len(machines):
            return -1
        average = sum_up / len(machines)
        ending_here = 0
        result = 0
        for machine in machines:
            current = machine - average
            ending_here += current
            result = max(result, abs(ending_here), current)
        return result
