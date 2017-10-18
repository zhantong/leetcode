class Solution:
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        sign = 1
        count_x = 0
        const = 0
        is_reverse = 1
        current = 0
        for i, letter in enumerate(equation):
            if '0' <= letter <= '9':
                current = current * 10 + ord(letter) - ord('0')
            elif letter == 'x':
                if current == 0 and (i == 0 or (equation[i - 1] in ['+', '-', '='])):
                    current = 1
                count_x += current * sign * is_reverse
                print(count_x)
                current = 0
            elif letter in ['+', '-', '=']:
                const += current * sign * is_reverse * -1
                current = 0
                if letter == '=':
                    is_reverse = -1
                    sign = 1
                else:
                    sign = 1 if letter == '+' else -1
        const += current * sign * is_reverse * -1
        if count_x == 0 and const == 0:
            return 'Infinite solutions'
        elif count_x == 0:
            return 'No solution'
        else:
            return 'x={}'.format(const // count_x)
