class Solution {
    public int[] constructArray(int n, int k) {
        int[] result = new int[n];
        int i = 1;
        int j = n;
        int index = 0;
        while (i <= j) {
            if (k > 0) {
                if (k % 2 != 0) {
                    result[index] = i;
                    i++;
                } else {
                    result[index] = j;
                    j--;
                }
                k--;
            } else {
                result[index] = i;
                i++;
            }
            index++;
        }
        return result;
    }
}