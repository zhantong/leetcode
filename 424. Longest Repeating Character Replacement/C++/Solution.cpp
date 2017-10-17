class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        vector<int> counts(128, 0);
        int leftIndex = 0;
        int currentMax = 0;
        for (int rightIndex = 0; rightIndex < s.length(); rightIndex++) {
            char letter = s[rightIndex];
            counts[letter]++;
            currentMax = max(currentMax, counts[letter]);
            while (rightIndex - leftIndex + 1 - currentMax > k) {
                counts[s[leftIndex]]--;
                leftIndex++;
            }
            result = max(result, rightIndex - leftIndex + 1);
        }
        return result;
    }
};