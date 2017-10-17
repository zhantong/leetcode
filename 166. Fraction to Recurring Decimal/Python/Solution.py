class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0:
            return '0'
        result = ''
        if (numerator > 0) != (denominator > 0):
            result = '-'
        numerator = abs(numerator)
        denominator = abs(denominator)
        result += str(numerator // denominator)
        numerator %= denominator
        if numerator == 0:
            return result
        result += '.'
        memory = {}
        memory[numerator] = len(result)
        while numerator:
            numerator *= 10
            result += str(numerator // denominator)
            numerator %= denominator
            if numerator in memory:
                start_index = memory[numerator]
                result = result[:start_index] + '(' + result[start_index:] + ')'
                break
            memory[numerator] = len(result)
        return result
