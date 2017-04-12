public class Solution {
    public String validIPAddress(String IP) {
        class Utils {
            boolean validIpv4Token(String token) {
                if (token.isEmpty() || (token.length() > 1 && token.charAt(0) == '0') || token.length() > 3) {
                    return false;
                }
                for (char letter : token.toCharArray()) {
                    if (!Character.isDigit(letter)) {
                        return false;
                    }
                }
                int inInt = Integer.parseInt(token);
                if (inInt > 255) {
                    return false;
                }
                return true;
            }

            boolean validIpv4Address(String ip) {
                if (ip.startsWith(".") || ip.endsWith(".")) {
                    return false;
                }
                String[] tokens = ip.split("\\.");
                if (tokens.length != 4) {
                    return false;
                }
                for (String token : tokens) {
                    if (!validIpv4Token(token)) {
                        return false;
                    }
                }
                return true;
            }

            boolean validIpv6Token(String token) {
                if (token.isEmpty() || token.length() > 4) {
                    return false;
                }
                for (char letter : token.toCharArray()) {
                    if (!((letter >= '0' && letter <= '9') || (letter >= 'a' && letter <= 'f') || (letter >= 'A' && letter <= 'F'))) {
                        return false;
                    }
                }
                return true;
            }

            boolean validIpv6Address(String ip) {
                if (ip.startsWith(":") || ip.endsWith(":")) {
                    return false;
                }
                String[] tokens = ip.split(":");
                if (tokens.length != 8) {
                    return false;
                }
                for (String token : tokens) {
                    if (!validIpv6Token(token)) {
                        return false;
                    }
                }
                return true;
            }
        }
        Utils utils = new Utils();
        if (utils.validIpv4Address(IP)) {
            return "IPv4";
        }
        if (utils.validIpv6Address(IP)) {
            return "IPv6";
        }
        return "Neither";
    }
}