class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        for item in range(1, n + 1):
            formatted = str(item)
            if item % 3 == 0 and item % 5 == 0:
                formatted = 'FizzBuzz'
            elif item % 3 == 0:
                formatted = 'Fizz'
            elif item % 5 == 0:
                formatted = 'Buzz'
            result.append(formatted)
        return result
