class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        for (int i = str.length() / 2; i > 0; i--) {
            if (str.length() % i == 0) {
                bool flag = false;
                for (int offset = i; offset < str.length(); offset += i) {
                    for (int index = 0; index < i; index++) {
                        if (str[index] != str[offset + index]) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (!flag) {
                    return true;
                }
            }
        }
        return false;
    }
};