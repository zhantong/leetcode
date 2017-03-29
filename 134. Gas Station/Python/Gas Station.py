class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        start = len(gas) - 1
        end = 0
        gain = gas[start] - cost[start]
        while start > end:
            if gain >= 0:
                gain += gas[end] - cost[end]
                end += 1
            else:
                start -= 1
                gain += gas[start] - cost[start]
        return start if gain >= 0 else -1
