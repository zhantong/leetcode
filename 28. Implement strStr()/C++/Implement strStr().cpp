class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < (int) haystack.size() - (int) needle.size() + 1; i++) {
            int j = 0;
            while (j < needle.size()) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
                j++;
            }
            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};