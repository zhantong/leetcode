class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        index = len(digits) - 1
        while carry and index >= 0:
            if digits[index] == 9:
                digits[index] = 0
            else:
                digits[index] += 1
                carry = 0
            index -= 1
        if digits[0] == 0:
            digits = [0] * (len(digits) + 1)
            digits[0] = 1
        return digits
