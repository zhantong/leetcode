class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for token in tokens:
            if token == '+':
                a = stack.pop()
                b = stack.pop()
                stack.append(b + a)
            elif token == '-':
                a = stack.pop()
                b = stack.pop()
                stack.append(b - a)
            elif token == '*':
                a = stack.pop()
                b = stack.pop()
                stack.append(b * a)
            elif token == '/':
                a = stack.pop()
                b = stack.pop()
                if a * b < 0 and b % a != 0:
                    stack.append(b / a + 1)
                else:
                    stack.append(b / a)
            else:
                stack.append(int(token))
        return stack.pop()
