class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        if len(g) == 0 or len(s) == 0:
            return 0
        g = sorted(g, reverse=True)
        s = sorted(s, reverse=True)
        satisfy_count = 0
        for item in g:
            if item <= s[satisfy_count]:
                satisfy_count += 1
                if satisfy_count == len(s):
                    break
        return satisfy_count
