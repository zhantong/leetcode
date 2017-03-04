class Solution(object):
    def __init__(self):
        self.memory = {}

    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        if input in self.memory:
            return self.memory[input]
        result = []
        for index, letter in enumerate(input):
            if letter in ['+', '-', '*']:
                left_vals = self.diffWaysToCompute(input[:index])
                right_vals = self.diffWaysToCompute(input[index + 1:])
                for left in left_vals:
                    for right in right_vals:
                        current = 0
                        if letter == '+':
                            current = left + right
                        elif letter == '-':
                            current = left - right
                        elif letter == '*':
                            current = left * right
                        result.append(current)
        if not result:
            result.append(int(input))
        self.memory[input] = result
        return result
