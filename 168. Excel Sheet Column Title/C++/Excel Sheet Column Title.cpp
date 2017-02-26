class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            n--;
            result = (char) ('A' + n % 26) + result;
            n /= 26;
        }
        return result;
    }
};