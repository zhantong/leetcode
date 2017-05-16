class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        self.result = 0

        def arrangement(index, used):
            if index == len(used):
                self.result += 1
                return
            for i in range(1, len(used)):
                if not used[i] and (i % index == 0 or index % i == 0):
                    used[i] = True
                    arrangement(index + 1, used)
                    used[i] = False

        arrangement(1, [False] * (N + 1))
        return self.result
