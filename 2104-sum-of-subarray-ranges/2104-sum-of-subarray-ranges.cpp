class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        

        vector<int> nextGreater(n, n), prevGreater(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                prevGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        
        vector<int> nextSmaller(n, n), prevSmaller(n, -1);
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        long long maxSum = 0, minSum = 0;
        
        for (int i = 0; i < n; i++) {
            long long leftGreater = i - prevGreater[i];
            long long rightGreater = nextGreater[i] - i;
            maxSum += (long long)nums[i] * leftGreater * rightGreater;
            
            long long leftSmaller = i - prevSmaller[i];
            long long rightSmaller = nextSmaller[i] - i;
            minSum += (long long)nums[i] * leftSmaller * rightSmaller;
        }
        
        return maxSum - minSum;
    }
};