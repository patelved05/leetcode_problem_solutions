class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }
            ans = max(ans, maxHistogram(height));
        }
        return ans;
    }
    
    int maxHistogram(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int ans = 0;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || height[st.top()] >= height[i])) {
                int h = height[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        return ans;
    }
};