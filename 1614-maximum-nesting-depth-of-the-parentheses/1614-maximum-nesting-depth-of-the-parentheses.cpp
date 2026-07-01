class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxs = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
                maxs = max(maxs, count);
            } else if (c == ')') {
                count--;
            }
        }
        return maxs;
    }
};