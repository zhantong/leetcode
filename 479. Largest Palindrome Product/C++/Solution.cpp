class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int max = (int) pow(10, n) - 1;
        for (int i = max; i > max / 10; i--) {
            string iInStr = to_string(i);
            reverse(iInStr.rbegin(), iInStr.rend());
            long current = stol(to_string(i) + iInStr);
            for (long item = max; item * item >= current; item--) {
                if (current % item == 0) {
                    return (int)(current % 1337);
                }
            }
        }
        return 0;
    }
};