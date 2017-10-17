class Solution(object):
    def repeatedSubstringPattern(self, str):
        """
        :type str: str
        :rtype: bool
        """
        for i in range(len(str) // 2, 0, -1):
            if len(str) % i == 0:
                flag = False
                for offset in range(i, len(str), i):
                    for index in range(0, i):
                        if str[index] != str[offset + index]:
                            flag = True
                            break
                    if flag:
                        break
                if not flag:
                    return True
        return False
