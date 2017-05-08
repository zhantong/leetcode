class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> memory(128, 0);
        for (auto letter : t) {
            memory[letter]++;
        }
        int count = t.length();
        int minLength = INT_MAX;
        int minStart = 0;
        int start = 0;
        int i = 0;
        while (i < s.length()) {
            char letter = s[i];
            if (memory[letter] > 0) {
                count--;
            }
            memory[letter]--;
            i++;
            while (count == 0) {
                if (i - start < minLength) {
                    minStart = start;
                    minLength = i - start;
                }
                memory[s[start]]++;
                if (memory[s[start]] > 0) {
                    count++;
                }
                start++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(minStart, minLength);
    }
};