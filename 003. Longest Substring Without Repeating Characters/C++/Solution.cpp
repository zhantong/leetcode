class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> memory;
        int result = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (memory.find(s[i]) != memory.end()) {
                j = max(j, memory[s[i]] + 1);
            }
            memory[s[i]] = i;
            result = max(result, i - j + 1);
        }
        return result;
    }
};