class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) {
            return 3;
        }
        if (n == 0) {
            return 0;
        }
        vector<long> counts(n + 1);
        counts[0] = 1;
        counts[1] = 2;
        counts[2] = 4;
        int MOD = 1000000007;
        for (int i = 3; i <= n; i++) {
            counts[i] = (counts[i - 1] + counts[i - 2] + counts[i - 3]) % MOD;
        }
        long result = counts[n];
        for (int i = 1; i <= n; i++) {
            result += (counts[i - 1] * counts[n - i]) % MOD;
            result %= MOD;
        }
        return (int) result;
    }
};