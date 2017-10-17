class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> factors(primes.size(), 1);
        vector<int> indexes(primes.size(), -1);
        vector<int> ugly(n);
        for (int i = 0; i < n; i++) {
            int theMin = INT_MAX;
            for (auto factor : factors) {
                theMin = min(theMin, factor);
            }
            ugly[i] = theMin;
            for (int j = 0; j < factors.size(); j++) {
                if (ugly[i] == factors[j]) {
                    indexes[j]++;
                    factors[j] = ugly[indexes[j]] * primes[j];
                }
            }
        }
        return ugly.back();
    }
};