class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        def back_trace(stones, current, length, memory):
            key = (current << 32) | length
            if key in memory:
                return memory[key]
            if current == 0 and length == 1:
                memory[key] = True
                return True
            if current == 0:
                memory[key] = False
                return False
            for i in range(current - 1, -1, -1):
                temp_length = stones[current] - stones[i]
                if temp_length < length - 1:
                    continue
                if temp_length > length + 1:
                    memory[key] = False
                    return False
                if back_trace(stones, i, temp_length, memory):
                    memory[key] = True
                    return True
            memory[key] = False
            return False

        last = stones[-1]
        memory = {}
        for i in range(len(stones) - 2, -1, -1):
            if back_trace(stones, i, last - stones[i], memory):
                return True
        return False
