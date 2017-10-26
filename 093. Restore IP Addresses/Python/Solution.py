class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def back_trace(s, result, current, index, count):
            if count > 4:
                return
            if count == 4 and index == len(s):
                result.append(current[:-1])
            elif count < 4:
                for i in range(3):
                    if index + i >= len(s):
                        break
                    sub = s[index:index + i + 1]
                    if int(sub) >= 256 or (sub[0] == '0' and len(sub) > 1):
                        continue
                    back_trace(s, result, current + sub + '.', index + i + 1, count + 1)

        result = []
        back_trace(s, result, '', 0, 0)
        return result
