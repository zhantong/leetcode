class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] m1 = new int[256];
        int[] m2 = new int[256];
        for (int i = 0; i < s.length(); i++) {
            char k1 = s.charAt(i);
            char k2 = t.charAt(i);
            if (m1[k1] != m2[k2]) {
                return false;
            }
            m1[k1] = i + 1;
            m2[k2] = i + 1;
        }
        return true;
    }
}