class Solution {
public:
    int reverse(int x) {
        int result = 0;
        bool neg = false;
        if (x < 0) {
            x = -x;
            neg = true;;
        }
        while (x != 0) {
            int remain = x % 10;
            x = x/10;
            if ((INT_MAX - remain) / 10 < result) {
                return 0;
            }
            result = result * 10 + remain;
        }
        if (neg == true) {
            result = -result;
        }
        return result;
    }
};
