class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        def convert(num):
            LESS_THAN_20 = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                            "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
            TENS = ["", "Ten", "Twenty", "Thirty", "Forty",
                    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
            if num == 0:
                return ''
            if num < 20:
                return LESS_THAN_20[num] + ' '
            if num < 100:
                return TENS[num // 10] + ' ' + convert(num % 10)
            return LESS_THAN_20[num // 100] + ' Hundred ' + convert(num % 100)

        THOUSANDS = ["", "Thousand", "Million", "Billion"]
        if num == 0:
            return 'Zero'
        i = 0
        result = ''
        while num:
            slice = num % 1000
            if slice:
                result = convert(slice) + THOUSANDS[i] + ' ' + result
            num //= 1000
            i += 1
        return result.strip()
