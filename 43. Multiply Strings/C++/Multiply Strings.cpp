class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> result(num1.length() + num2.length(), 0);
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j = num2.length() - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j;
                int pos2 = i + j + 1;
                mul += result[pos2];
                result[pos1] += mul / 10;
                result[pos2] = mul % 10;
            }
        }
        string str = "";
        if (result[0] != 0) {
            str += to_string(result[0]);
        }
        for (int i = 1; i < result.size(); i++) {
            str += to_string(result[i]);
        }
        return str;
    }
};