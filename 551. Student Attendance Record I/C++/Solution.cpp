class Solution {
public:
    bool checkRecord(string s) {
        bool containsA = false;
        for (int i = 0; i < s.length(); i++) {
            char letter = s[i];
            if ((letter == 'A' && containsA) || (letter == 'L' && i >= 2 && s[i - 1] == 'L' && s[i - 2] == 'L')) {
                return false;
            }
            if (letter == 'A' && !containsA) {
                containsA = true;
            }
        }
        return true;
    }
};