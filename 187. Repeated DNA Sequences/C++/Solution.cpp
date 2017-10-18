class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) {
            return vector<string>();
        }
        unordered_set<int> firstGot;
        unordered_set<int> secondGot;
        unordered_map<char, int> pattern;
        pattern['A'] = 0;
        pattern['C'] = 1;
        pattern['G'] = 2;
        pattern['T'] = 3;
        vector<string> result;
        for (int i = 0; i < s.length() - 9; i++) {
            cout << "go" << endl;
            int current = 0;
            for (int j = i; j < i + 10; j++) {
                current <<= 2;
                current |= pattern[s[j]];
            }
            if (firstGot.find(current) == firstGot.end()) {
                firstGot.insert(current);
            } else if (secondGot.find(current) == secondGot.end()) {
                result.push_back(s.substr(i, 10));
                secondGot.insert(current);
            }
        }
        return result;
    }
};