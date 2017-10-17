class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result = "";
        int countK = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            char letter = S[i];
            if (letter != '-') {
                result += toupper(letter);
                countK++;
                if (countK == K) {
                    result += '-';
                    countK = 0;
                }
            }
        }
        if (result.length() != 0 && result[result.length() - 1] == '-') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};