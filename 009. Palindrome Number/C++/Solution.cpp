class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0 || x % 10 == 0) {
            return false;
        }
        int palindrome = 0;
        while (palindrome < x) {
            palindrome = palindrome * 10 + x % 10;
            x /= 10;
        }
        return (x == palindrome) || (x == palindrome / 10);
    }
};