class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        def is_palindrome(str):
            i = 0
            j = len(str) - 1
            while i < j:
                if str[i] != str[j]:
                    return False
                i += 1
                j -= 1
            return True

        def part(s, result, current):
            if not s:
                result.append(current[:])
                return
            for i in range(1, len(s) + 1):
                front = s[:i]
                if is_palindrome(front):
                    current.append(front)
                    part(s[i:], result, current)
                    current.pop()

        result = []
        part(s, result, [])
        return result
