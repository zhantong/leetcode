class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string symbols = "0123456789abcdef";
        string result = "";
        while (num) {
            int value = num & 0xf;
            result += symbols[value];
            num = (int)((unsigned int) num >> 4);
        }
        reverse(result.rbegin(), result.rend());
        return result;
    }
};