class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        def valid_ipv4_address(ip):
            def valid_ipv4_token(token):
                if not token or (len(token) > 1 and token[0] == '0') or not token.isdigit():
                    return False
                in_int = int(token)
                if in_int > 255:
                    return False
                return True

            tokens = ip.split('.')
            if len(tokens) != 4:
                return False
            for token in tokens:
                if not valid_ipv4_token(token):
                    return False
            return True

        def valid_ipv6_address(ip):
            def valid_ipv6_token(token):
                if not token or len(token) > 4:
                    return False
                for letter in token:
                    in_int = ord(letter)
                    if not ((in_int >= ord('0') and in_int <= ord('9')) or (
                            in_int >= ord('a') and in_int <= ord('f')) or (
                            in_int >= ord('A') and in_int <= ord('F'))):
                        return False
                return True

            tokens = ip.split(':')
            if len(tokens) != 8:
                return False
            for token in tokens:
                if not valid_ipv6_token(token):
                    return False
            return True

        if valid_ipv4_address(IP):
            return 'IPv4'
        if valid_ipv6_address(IP):
            return 'IPv6'
        return 'Neither'
