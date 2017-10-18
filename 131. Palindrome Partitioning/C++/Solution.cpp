class Solution {
public:
    vector<vector<string>> partition(string s) {
        class Utils {
        public:
            bool isPalindrome(string s) {
                int i = 0;
                int j = s.length() - 1;
                while (i < j) {
                    if (s[i] != s[j]) {
                        return false;
                    }
                    i++;
                    j--;
                }
                return true;
            }

            void part(string s, vector<vector<string>> &result, vector<string> &current) {
                if (s.empty()) {
                    result.push_back(current);
                    return;
                }
                for (int i = 1; i <= s.length(); i++) {
                    string front = s.substr(0, i);
                    if (isPalindrome(front)) {
                        current.push_back(front);
                        part(s.substr(i), result, current);
                        current.pop_back();
                    }
                }
            }
        };
        vector<vector<string>> result;
        Utils utils;
        vector<string> temp;
        utils.part(s, result, temp);
        return result;
    }
};