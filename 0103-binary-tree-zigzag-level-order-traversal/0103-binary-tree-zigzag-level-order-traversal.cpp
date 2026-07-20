/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> st;
        st.push(root);
        bool flag = true;
        while (!st.empty()) {
            int size = st.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = st.front();
                st.pop();
                int index = (flag) ? i : (size - 1 - i);
                row[index] = node->val;
                if (node->left) {
                    st.push(node->left);
                }
                if (node->right) {
                    st.push(node->right);
                }
            }
            flag = !flag;
            ans.push_back(row);
        }
        return ans;
    }
};