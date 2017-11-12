class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int count = 0;
        for (auto item : g) {
            while (i < s.size() && item > s[i]) {
                i++;
            }
            if (i == s.size()) {
                break;
            }
            count++;
            i++;
        }
        return count;
    }
};