class Solution {
    public int repeatedStringMatch(String A, String B) {
        StringBuilder builder = new StringBuilder();
        int result = 0;
        while (builder.length() < B.length()) {
            builder.append(A);
            result++;
        }
        if (builder.toString().contains(B)) {
            return result;
        }
        builder.append(A);
        result++;
        if (builder.toString().contains(B)) {
            return result;
        }
        return -1;
    }
}