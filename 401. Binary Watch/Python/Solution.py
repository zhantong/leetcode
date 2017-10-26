class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def get_combination(length, num_ones, base, pool):
            if num_ones == 0:
                pool.append(base)
                return
            if length == 0 or length < num_ones:
                return
            get_combination(length - 1, num_ones - 1, base + (1 << (length - 1)), pool)
            get_combination(length - 1, num_ones, base, pool)

        result = []
        for ones_hour in range(0, num + 1):
            ones_minute = num - ones_hour
            hours = []
            minutes = []
            get_combination(4, ones_hour, 0, hours)
            get_combination(6, ones_minute, 0, minutes)
            for hour in hours:
                if hour > 11:
                    continue
                for minute in minutes:
                    if minute > 59:
                        continue
                    result.append('%d:%02d' % (hour, minute))
        return result
