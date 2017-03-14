class Solution {
public:
    int longestSubstring(string s, int k) {
        class Utils {
        public:
            int substring(string &s, int k, int start, int end) {
                if (start >= end) {
                    return 0;
                }
                vector<int> counts(26);
                for (int i = start; i < end; i++) {
                    counts[s[i] - 'a']++;
                }
                int subStart = start;
                int maxLength = -1;
                for (int i = start; i < end; i++) {
                    if (counts[s[i] - 'a'] < k) {
                        int subLength = substring(s, k, subStart, i);
                        subStart = i + 1;
                        maxLength = max(maxLength, subLength);
                    }
                }
                if (subStart != start) {
                    int subLength = substring(s, k, subStart, end);
                    maxLength = max(maxLength, subLength);
                }
                if (maxLength == -1) {
                    return end - start;
                }
                return maxLength;
            }
        };
        Utils utils;
        return utils.substring(s, k, 0, s.size());
    }
};