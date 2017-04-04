class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;
        while (i < num.length() - 1 && k > 0) {
            if (num[i] > num[i + 1]) {
                num = num.substr(0, i) + num.substr(i + 1, num.length() - i - 1);
                k--;
                if (i > 0) {
                    i--;
                }
            } else {
                i++;
            }
        }
        while (!num.empty() && k > 0) {
            num = num.substr(0, num.length() - 1);
            k--;
        }
        while (!num.empty() && num[0] == '0') {
            num = num.substr(1, num.length() - 1);
        }
        if (num.empty()) {
            return "0";
        }
        return num;
    }
};