class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        letter_dict = {}
        for letter in s:
            if letter not in letter_dict:
                letter_dict[letter] = 0
            letter_dict[letter] += 1
        nums = [0] * 10
        nums[0] = letter_dict.get('z', 0)
        nums[2] = letter_dict.get('w', 0)
        nums[4] = letter_dict.get('u', 0)
        nums[6] = letter_dict.get('x', 0)
        nums[8] = letter_dict.get('g', 0)
        nums[1] = letter_dict.get('o', 0) - nums[0] - nums[2] - nums[4]
        nums[3] = letter_dict.get('h', 0) - nums[8]
        nums[5] = letter_dict.get('f', 0) - nums[4]
        nums[7] = letter_dict.get('v', 0) - nums[5]
        nums[9] = letter_dict.get('i', 0) - nums[5] - nums[6] - nums[8]
        result = ''
        for num, times in enumerate(nums):
            result += str(num) * times
        return result
