class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";
        while (i >= 0 || j >= 0 || carry != 0) {
            int count = 0;
            if (i >= 0) {
                if (a[i] == '1') {
                    count++;
                }
                i--;
            }
            if (j >= 0) {
                if (b[j] == '1') {
                    count++;
                }
                j--;
            }
            count += carry;
            switch (count) {
            case 0:
                result.append("0");
                carry = 0;
                break;
            case 1:
                result.append("1");
                carry = 0;
                break;
            case 2:
                result.append("0");
                carry = 1;
                break;
            case 3:
                result.append("1");
                carry = 1;
                break;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};