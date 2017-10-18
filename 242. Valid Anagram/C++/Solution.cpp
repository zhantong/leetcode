class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        map<char, int> check;
        for (char item : s) {
            if (check.find(item) == check.end()) {
                check[item] = 0;
            }
            check[item]++;
        }
        for (char item : t) {
            if (check.find(item) == check.end()) {
                return false;
            }
            check[item]--;
        }
        for (auto &item : check) {
            if (item.second != 0) {
                return false;
            }
        }
        return true;
    }
};