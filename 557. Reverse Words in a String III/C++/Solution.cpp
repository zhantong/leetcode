class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        int i = 0;
        while (i < length && s[i] == ' ') {
            i++;
        }
        int j = i;
        while (j < length) {
            while (j < length && s[j] != ' ') {
                j++;
            }
            int low = i;
            int high = j - 1;
            while (low < high) {
                char temp = s[low];
                s[low] = s[high];
                s[high] = temp;
                low++;
                high--;
            }
            while (j < length && s[j] == ' ') {
                j++;
            }
            i = j;
        }
        return s;
    }
};