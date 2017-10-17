class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        saw_lower = False
        saw_one_upper = False
        saw_two_upper = False
        for letter in word:
            if letter >= 'A' and letter <= 'Z':
                if saw_lower:
                    return False
                if saw_one_upper:
                    saw_two_upper = True
                else:
                    saw_one_upper = True
            if letter >= 'a' and letter <= 'z':
                if saw_two_upper:
                    return False
                saw_lower = True
        return True
