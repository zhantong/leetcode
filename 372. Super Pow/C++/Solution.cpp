class Solution {
public:
    int superPow(int a, vector<int> &b) {
        class Utils {
        public:
            int pow(int a, int n, int base) {
                int result = 1;
                a %= base;
                for (int i = 0; i < n; i++) {
                    result = (result * a) % base;
                }
                return result;
            }
        };
        if (b.empty()) {
            return 1;
        }
        int last = b.back();
        b.pop_back();
        int base = 1337;
        Utils utils;
        return utils.pow(superPow(a, b), 10, base) * utils.pow(a, last, base) % base;
    }
};