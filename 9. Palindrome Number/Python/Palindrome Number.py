class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x == 0:
            return True
        if x < 0 or x % 10 == 0:
            return False
        palindrome = 0
        while palindrome < x:
            palindrome = palindrome * 10 + x % 10
            x //= 10
        return x == palindrome or x == palindrome // 10
