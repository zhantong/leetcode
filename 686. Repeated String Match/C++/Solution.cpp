class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string temp = "";
        int result = 0;
        while (temp.length() < B.length()) {
            temp += A;
            result++;
        }
        if (temp.find(B) != string::npos) {
            return result;
        }
        temp += A;
        result++;
        if (temp.find(B) != string::npos) {
            return result;
        }
        return -1;
    }
};