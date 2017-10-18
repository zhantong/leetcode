class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string result = "";
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int plus = 0;
            if (i >= 0) {
                plus += num1[i] - '0';
            }
            if (j >= 0) {
                plus += num2[j] - '0';
            }
            plus += carry;
            result += (char)(plus % 10 + '0');
            carry = plus / 10;
            i--;
            j--;
        }
        if (carry == 1) {
            result += '1';
        }
        reverse(result.rbegin(), result.rend());
        return result;
    }
};