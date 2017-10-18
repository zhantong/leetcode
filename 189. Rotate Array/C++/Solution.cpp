class Solution {
public:
    void rev(int a[], int s, int e) {
        while (s < e) {
            int t = a[s];
            a[s] = a[e];
            a[e] = t;
            s++;
            e--;
        }
    }
    void rotate(int nums[], int n, int k) {
        if (k > 0) {
            if (k > n)
                k %= n;
            rev(nums, 0, n - 1);
            rev(nums, 0, k - 1);
            rev(nums, k, n - 1);
        }
    }
};