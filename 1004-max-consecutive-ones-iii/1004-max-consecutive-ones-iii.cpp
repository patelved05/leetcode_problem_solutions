class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, ans = 0, zero = 0;
        while (right < nums.size()) {
            if (nums[right] == 0)
                zero++;
            if (zero > k) {
                if (nums[left] == 0)
                    zero--;
                left++;
            }
            if (zero <= k)
                ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};