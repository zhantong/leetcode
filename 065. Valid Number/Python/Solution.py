class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.strip()
        has_dot = False
        has_e = False
        has_number = False
        has_number_after_e = False
        for i, letter in enumerate(s):
            if letter in '0123456789':
                has_number = True
                if has_e:
                    has_number_after_e = True
            elif letter == '.':
                if has_dot or has_e:
                    return False
                has_dot = True
            elif letter == 'e':
                if has_e or not has_number:
                    return False
                has_e = True
            elif letter in '+-':
                if i != 0 and s[i - 1] != 'e':
                    return False
            else:
                return False
        return (not has_e ^ has_number_after_e) and has_number
