class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> counts(26, 0);
        int currentMax = 0;
        for (int i = 0; i < p.length(); i++) {
            if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25)) {
                currentMax++;
            } else {
                currentMax = 1;
            }
            int index = p[i] - 'a';
            counts[index] = max(counts[index], currentMax);
        }
        int theSum = 0;
        for (int count : counts) {
            theSum += count;
        }
        return theSum;
    }
};