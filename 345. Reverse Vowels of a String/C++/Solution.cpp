class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
        while (i < j) {
            if (vowels.find(s[i]) == vowels.end()) {
                i++;
            } else if (vowels.find(s[j]) == vowels.end()) {
                j--;
            } else {
                if (s[i] != s[j]) {
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
                i++;
                j--;
            }
        }
        return s;
    }
};