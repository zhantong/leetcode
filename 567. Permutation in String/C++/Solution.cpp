class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Length = s1.length();
        int count = s1.length();
        int memory[26] = {};
        for (auto letter : s1) {
            memory[letter - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            char letter = s2[i];
            if (memory[letter - 'a'] > 0) {
                count--;
                if (count == 0) {
                    return true;
                }
            }
            memory[letter - 'a']--;
            if (i >= s1Length - 1) {
                int leftIndex = i - s1Length + 1;
                if (memory[s2[leftIndex] - 'a'] >= 0) {
                    count++;
                }
                memory[s2[leftIndex] - 'a']++;
            }
        }
        return false;
    }
};