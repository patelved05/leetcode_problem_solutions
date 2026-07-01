class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int al = 0;
        int maxal = 0;
        for (int i : gain) {
            al += i;
            maxal = max(maxal, al);
        }
        return maxal;
    }
};