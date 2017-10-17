public class Solution {
    public boolean validUtf8(int[] data) {
        int i = 0;
        while (i < data.length) {
            if ((data[i] & 0x80) != 0) {
                if (data[i] >> 6 == 0b10) {
                    return false;
                }
                int front = data[i];
                int count = 1;
                while ((front << count & 0x80) != 0) {
                    i++;
                    if (i >= data.length || data[i] >> 6 != 0b10) {
                        return false;
                    }
                    count++;
                }
                if (count > 4) {
                    return false;
                }
            }
            i++;
        }
        return true;
    }
}