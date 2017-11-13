class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> counts(26, 0);
        for (auto item : s) {
            counts[item - 'a']++;
        }
        for (char item : t) {
            counts[item - 'a']--;
        }
        for (auto count : counts) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};