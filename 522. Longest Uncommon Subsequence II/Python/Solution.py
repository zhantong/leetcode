class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        def is_subsequence(a, b):
            i = 0
            for letter in b:
                if letter == a[i]:
                    i += 1
                if i == len(a):
                    return True
            return False

        result = -1
        for i, a in enumerate(strs):
            flag = True
            for j, b in enumerate(strs):
                if i != j and is_subsequence(a, b):
                    flag = False
                    break
            if flag:
                result = max(result, len(a))
        return result
