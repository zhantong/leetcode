public class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int theSum = (C - A) * (D - B) + (G - E) * (H - F);
        int left = Math.max(A, E);
        int right = Math.min(C, G);
        int up = Math.min(D, H);
        int down = Math.max(B, F);
        if (right > left && up > down) {
            int overlap = (right - left) * (up - down);
            return theSum - overlap;
        }
        return theSum;
    }
}