class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == '0' or num2 == '0':
            return '0'
        result = [0] * (len(num1) + len(num2))
        for i in range(len(num1) - 1, -1, -1):
            for j in range(len(num2) - 1, -1, -1):
                mul = int(num1[i]) * int(num2[j])
                pos_1 = i + j
                pos_2 = i + j + 1
                mul += result[pos_2]
                result[pos_1] += mul // 10
                result[pos_2] = mul % 10
        result = ''.join(str(item) for item in result)
        if result[0] == '0':
            result = result[1:]
        return result
