class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans;
        while (n > 0) {
            ans += n % 10;
            n /=10;
        }
        return ans;
    }
};
