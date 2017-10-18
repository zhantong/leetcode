class Solution {
public:
    int maxProduct(vector<string> &words) {
        vector<int> bits(words.size());
        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            int bit = 0;
            for (auto letter : words[i]) {
                bit |= 1 << (letter - 'a');
            }
            bits[i] = bit;
        }
        for (int i = 0; i < bits.size(); i++) {
            for (int j = i + 1; j < bits.size(); j++) {
                if ((bits[i] & bits[j]) == 0 && words[i].length() * words[j].length() > result) {
                    result = words[i].length() * words[j].length();
                }
            }
        }
        return result;
    }
};