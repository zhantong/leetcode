class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        result = []
        count_char = 0
        row = []
        for word in words:
            if len(word) + count_char + len(row) > maxWidth:
                print(row)
                if len(row) == 1:
                    result.append(row[0] + ' ' * (maxWidth - len(row[0])))
                else:
                    count_space = (maxWidth - count_char) // (len(row) - 1)
                    count_extra = (maxWidth - count_char) % (len(row) - 1)
                    for i in range(count_extra):
                        row[i] += ' '
                    result.append((' ' * count_space).join(row))
                count_char = 0
                row = []
            count_char += len(word)
            row.append(word)
        last = ' '.join(row)
        result.append(last + ' ' * (maxWidth - len(last)))
        return result
