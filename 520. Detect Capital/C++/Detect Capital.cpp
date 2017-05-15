class Solution {
public:
    bool detectCapitalUse(string word) {
        bool sawLower = false;
        bool sawOneUpper = false;
        bool sawTwoUpper = false;
        for (auto letter : word) {
            if (letter >= 'A' && letter <= 'Z') {
                if (sawLower) {
                    return false;
                }
                if (sawOneUpper) {
                    sawTwoUpper = true;
                } else {
                    sawOneUpper = true;
                }
            }
            if (letter >= 'a' && letter <= 'z') {
                if (sawTwoUpper) {
                    return false;
                }
                sawLower = true;
            }
        }
        return true;
    }
};