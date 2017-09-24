class Solution:
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        stack = []
        result = [0] * n
        current = 0
        for log in logs:
            splits = log.split(':')
            time = int(splits[2])
            if splits[1] == 'start':
                if stack:
                    result[stack[-1]] += time - current
                current = time
                stack.append(int(splits[0]))
            else:
                result[stack[-1]] += time - current + 1
                current = time + 1
                stack.pop()
        return result
