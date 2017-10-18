class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (char item : s) {
            result ^= item;
        }
        for (char item : t) {
            result ^= item;
        }
        return result;
    }
};