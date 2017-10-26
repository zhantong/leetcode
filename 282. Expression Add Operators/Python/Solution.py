class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        def back_trace(num, target, i, current, result, value, prev):
            if i == len(num):
                if value == target:
                    result.append(current)
                return
            for j in range(i, len(num)):
                if j != i and num[i] == '0':
                    break
                now_in_str = num[i:j + 1]
                now_in_int = int(now_in_str)
                if i == 0:
                    back_trace(num, target, j + 1, now_in_str, result, now_in_int, now_in_int)
                else:
                    back_trace(num, target, j + 1, current + '+' + now_in_str,
                               result, value + now_in_int, now_in_int)
                    back_trace(num, target, j + 1, current + '-' + now_in_str,
                               result, value - now_in_int, -now_in_int)
                    back_trace(num, target, j + 1, current + '*' + now_in_str, result, value - prev + prev * now_in_int,
                               prev * now_in_int)

        result = []
        back_trace(num, target, 0, '', result, 0, 0)
        return result
