class Solution(object):
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        plus_index = a.find('+')
        a_real = int(a[:plus_index])
        a_image = int(a[plus_index + 1:-1])
        plus_index = b.find('+')
        b_real = int(b[:plus_index])
        b_image = int(b[plus_index + 1:-1])
        real = a_real * b_real - a_image * b_image
        image = b_real * a_image + a_real * b_image
        return str(real) + '+' + str(image) + 'i'
