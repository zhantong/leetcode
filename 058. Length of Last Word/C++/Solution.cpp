class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int index = s.size() - 1;
        while (index >= 0 && s[index] == ' ') {
            index--;
        }
        while (index >= 0 && s[index] != ' ') {
            index--;
            length++;
        }
        return length;
    }
};