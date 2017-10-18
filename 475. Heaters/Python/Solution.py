class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses = sorted(houses)
        heaters = sorted(heaters)
        heater_index = 0
        result = 0
        for house in houses:
            while heater_index + 1 < len(heaters) and abs(house - heaters[heater_index]) >= abs(
                    heaters[heater_index + 1] - house):
                heater_index += 1
            result = max(result, abs(house - heaters[heater_index]))
        return result
