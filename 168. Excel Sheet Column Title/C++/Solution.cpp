class Solution {
public:
    string convertToTitle(int n) {
        int i = 0;
        char c;
        string s;
        while (n) {
            n--;
            int t;
            t = n % 26;
            n = n / 26;
            c = 'A' + t;
            s = c + s;
        }
        return s;
    }
};