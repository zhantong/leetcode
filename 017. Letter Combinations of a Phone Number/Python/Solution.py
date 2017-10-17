class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        result = []
        result.append('')
        pattern = ['0', '1', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        for digit in digits:
            temp_result = []
            for item in result:
                for letter in pattern[ord(digit) - ord('0')]:
                    temp_result.append(item + letter)
            result = temp_result
        return result
