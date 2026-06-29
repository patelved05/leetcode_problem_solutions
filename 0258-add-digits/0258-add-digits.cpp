class Solution {
public:
    int sums(int value) {
        int full = 0;

        while(value > 0) {
            full += value % 10;
            value /= 10;
        }

        return full;
    }

    int addDigits(int num) {
        if(num < 10)
            return num;

        return addDigits(sums(num));
    }
};