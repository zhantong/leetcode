class Solution {
public:
    int myAtoi(string str) {
        int length = str.length();
        int index = 0;
        int sign = 1;
        int result = 0;
        while (index < length && str[index] == ' ') {
            index++;
        }
        if (index < length && str[index] == '-') {
            sign = -1;
            index++;
        } else if (index < length && str[index] == '+') {
            index++;
        }
        while (index < length && str[index] >= '0' && str[index] <= '9') {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[index] - '0' > 7)) {
                if (sign > 0) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            result = result * 10 + str[index] - '0';
            index++;
        }
        return sign * result;
    }
};