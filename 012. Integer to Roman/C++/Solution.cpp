class Solution {
public:
    string intToRoman(int num) {
        vector<string> words{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            while (num >= values[i]) {
                result += words[i];
                num -= values[i];
            }
        }
        return result;
    }
};