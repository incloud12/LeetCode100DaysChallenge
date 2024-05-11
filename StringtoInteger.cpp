class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int sign = 1;
        long long out = 0;

        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i == s.length()) {
            return 0;
        }

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            out = out * 10 + (s[i] - '0');

            if (out * sign <= INT_MIN) {
                return INT_MIN;
            } else if (out * sign >= INT_MAX) {
                return INT_MAX;
            }
            i++;

        }

        return out * sign;
    }
};
