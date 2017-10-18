class Solution {
public:
    string validIPAddress(string IP) {
        class Utils {
        public:
            vector<string> split(const string &s, char delim) {
                vector<string> elems;
                stringstream ss;
                ss.str(s);
                string item;
                while (getline(ss, item, delim)) {
                    elems.push_back(item);
                }
                return elems;
            }

            bool validIpv4Token(string token) {
                if (token.empty() || (token.length() > 1 && token[0] == '0') || token.length() > 3) {
                    return false;
                }
                for (auto &letter : token) {
                    if (!isdigit(letter)) {
                        return false;
                    }
                }
                int inInt = stoi(token);
                if (inInt > 255) {
                    return false;
                }
                return true;
            }

            bool validIpv4Address(string ip) {
                if (ip.empty() || ip.find(".") == 0 || ip.compare(ip.length() - 1, 1, ".") == 0) {
                    return false;
                }
                vector<string> tokens = split(ip, '.');
                if (tokens.size() != 4) {
                    return false;
                }
                for (auto &token : tokens) {
                    if (!validIpv4Token(token)) {
                        return false;
                    }
                }
                return true;
            }

            bool validIpv6Token(string token) {
                if (token.empty() || token.length() > 4) {
                    return false;
                }
                for (auto &letter : token) {
                    if (!((letter >= '0' && letter <= '9') || (letter >= 'a' && letter <= 'f') ||
                          (letter >= 'A' && letter <= 'F'))) {
                        return false;
                    }
                }
                return true;
            }

            bool validIpv6Address(string ip) {
                if (ip.empty() || ip.find(":") == 0 || ip.compare(ip.length() - 1, 1, ":") == 0) {
                    return false;
                }
                vector<string> tokens = split(ip, ':');
                if (tokens.size() != 8) {
                    return false;
                }
                for (auto &token : tokens) {
                    if (!validIpv6Token(token)) {
                        return false;
                    }
                }
                return true;
            }
        };
        Utils utils;
        if (utils.validIpv4Address(IP)) {
            return "IPv4";
        }
        if (utils.validIpv6Address(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
};