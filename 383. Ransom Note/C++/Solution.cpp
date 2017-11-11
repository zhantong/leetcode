class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> has(26, 0);
        for (char item : magazine) {
            has[item - 'a']++;
        }
        for (char item : ransomNote) {
            if (has[item - 'a'] == 0) {
                return false;
            }
            has[item - 'a']--;
        }
        return true;
    }
};