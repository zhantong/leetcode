class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        map<char, int> pattern;
        set<char> exist;
        for (int i = 0; i < s.length(); i++) {
            bool sExist = exist.find(s[i]) != exist.end();
            bool tExist = pattern.find(t[i]) != pattern.end();
            if (sExist && tExist) {
                if (t[i] + pattern[t[i]] != s[i]) {
                    return false;
                }
            } else if (!sExist && !tExist) {
                pattern[t[i]] = s[i] - t[i];
                exist.insert(s[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};