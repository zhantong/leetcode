class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        if (g.size() == 0 || s.size() == 0) {
            return 0;
        }
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int satisfyCount = 0;
        for (int item : g) {
            if (item <= s[satisfyCount]) {
                satisfyCount++;
                if (satisfyCount == s.size()) {
                    break;
                }
            }
        }
        return satisfyCount;
    }
};