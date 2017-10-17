class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        i = 0
        while i < len(data):
            if data[i] & 0x80:
                if data[i] >> 6 == 0b10:
                    return False
                front = data[i]
                count = 1
                while front << count & 0x80:
                    i += 1
                    if i >= len(data) or data[i] >> 6 != 0b10:
                        return False
                    count += 1
                if count > 4:
                    return False
            i += 1
        return True
