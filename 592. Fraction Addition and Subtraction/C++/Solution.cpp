class Solution {
public:
    string fractionAddition(string expression) {
        class Utils {
        public:
            int gcd(int x, int y) {
                return x != 0 ? gcd(y % x, x) : y;
            }

            void addition(int &a, int &b, int c, int d) {
                int up = a * d + b * c;
                int down = b * d;
                a = up / gcd(abs(up), abs(down));
                b = down / gcd(abs(up), abs(down));
            }
        };
        Utils utils;
        stringstream ss(expression);
        char op;
        int a, b, c, d;
        ss >> a;
        ss >> op;
        ss >> b;
        while (ss >> c) {
            ss >> op;
            ss >> d;
            utils.addition(a, b, c, d);
        }
        return to_string(a) + "/" + to_string(b);
    }
};