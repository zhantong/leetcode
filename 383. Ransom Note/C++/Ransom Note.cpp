class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> has;
        for (char item:magazine) {
            if (has.find(item) == has.end()) {
                has[item] = 0;
            }
            has[item]++;
        }
        for (char item:ransomNote) {
            if (has.find(item) == has.end() || has[item] == 0) {
                return false;
            }
            has[item]--;
        }
        return true;
    }
};