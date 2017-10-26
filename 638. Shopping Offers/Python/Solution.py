class Solution:
    def shoppingOffers(self, price, special, needs):
        """
        :type price: List[int]
        :type special: List[List[int]]
        :type needs: List[int]
        :rtype: int
        """

        def to_key(array):
            key = ''
            for item in array:
                key += str(item)
            return key

        def to_array(key):
            array = []
            for letter in key:
                array.append(int(letter))
            return array

        def trace(prices, specials, needs_key, memory):
            if needs_key in memory:
                return memory[needs_key]
            needs_array = to_array(needs_key)
            result = 0
            for price, need in zip(prices, needs_array):
                result += price * need
            for special in specials:
                new_needs_array = needs_array[:]
                can_fit = True
                for i in range(len(needs_array)):
                    if needs_array[i] < special[i]:
                        can_fit = False
                        break
                    new_needs_array[i] -= special[i]
                if can_fit:
                    result = min(result, special[-1] + trace(prices,
                                                             specials, to_key(new_needs_array), memory))
            memory[needs_key] = result
            return result

        return trace(price, special, to_key(needs), {})
