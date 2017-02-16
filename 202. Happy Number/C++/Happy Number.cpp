class Solution {
public:
    bool isHappy(int n) {
        set<int> got;
        while (n != 1 && got.find(n) == got.end()) {
            got.insert(n);
            int sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};