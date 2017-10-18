class Solution {
public:
    int index = 0;
    string decodeString(string s) {
        string result = "";
        while (index < s.length() && s[index] != ']') {
            char letter = s[index];
            if (isdigit(letter)) {
                int count = 0;
                while (index < s.length() && isdigit(s[index])) {
                    count = count * 10 + s[index] - '0';
                    index++;
                }
                index++;
                string subString = decodeString(s);
                index++;
                for (int i = 0; i < count; i++) {
                    result += subString;
                }
            } else {
                result += letter;
                index++;
            }
        }
        return result;
    }
};