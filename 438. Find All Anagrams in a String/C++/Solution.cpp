class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        map<char, int> patternDict;
        for (char item : p) {
            if (patternDict.find(item) == patternDict.end()) {
                patternDict[item] = 0;
            }
            patternDict[item]++;
        }
        int pLength = p.length();
        int falseAlarm = 0;
        int matchCount = p.length();
        for (int right = 0; right < s.length(); right++) {
            int left = right - pLength;
            if (left >= 0 && patternDict.find(s[left]) != patternDict.end()) {
                if (patternDict[s[left]] == -1) {
                    falseAlarm--;
                }
                patternDict[s[left]]++;
                matchCount++;
            }
            if (patternDict.find(s[right]) != patternDict.end()) {
                if (patternDict[s[right]] == 0) {
                    falseAlarm++;
                }
                patternDict[s[right]]--;
                matchCount--;
                if (matchCount == 0 && falseAlarm == 0) {
                    result.push_back(left + 1);
                }
            }
        }
        return result;
    }
};