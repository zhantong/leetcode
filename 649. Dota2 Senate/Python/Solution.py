class Solution:
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """
        r = 0
        d = 0
        current = 0
        senates = list(senate)
        length = len(senates)
        for s in senates:
            if s == 'R':
                r += 1
            else:
                d += 1
        while r > 0 and d > 0:
            while senates[current] == ' ':
                current = (current + 1) % length
            if senates[current] == 'R':
                to_ban = 'D'
                d -= 1
            else:
                to_ban = 'R'
                r -= 1
            temp = current
            while senates[temp] != to_ban:
                temp = (temp + 1) % length
            senates[temp] = ' '
            current = (current + 1) % length
        return 'Radiant' if d == 0 else 'Dire'
