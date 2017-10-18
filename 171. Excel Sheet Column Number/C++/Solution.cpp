class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (auto letter : s) {
            result = result * 26 + letter - 'A' + 1;
        }
        return result;
    }
};