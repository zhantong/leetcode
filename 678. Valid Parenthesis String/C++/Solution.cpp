class Solution {
public:
    bool checkValidString(string s) {
        int minClose = 0;
        int maxClose = 0;
        for (auto letter : s) {
            if (letter == '(') {
                minClose++;
                maxClose++;
            } else if (letter == ')') {
                if (minClose > 0) {
                    minClose--;
                }
                maxClose--;
                if (maxClose < 0) {
                    return false;
                }
            } else {
                if (minClose > 0) {
                    minClose--;
                }
                maxClose++;
            }
        }
        return minClose == 0;
    }
};