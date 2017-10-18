class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int i = 0;
        while (i < data.size()) {
            if ((data[i] & 0x80) != 0) {
                if (data[i] >> 6 == 0b10) {
                    return false;
                }
                int front = data[i];
                int count = 1;
                while ((front << count & 0x80) != 0) {
                    i++;
                    if (i >= data.size() || data[i] >> 6 != 0b10) {
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
};