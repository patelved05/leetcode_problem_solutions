/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        int maxWidth = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long leftmost = q.front().second;
            unsigned long long rightmost = q.back().second;
       
            maxWidth = max(maxWidth, (int)(rightmost - leftmost + 1));
            
            for (int i = 0; i < levelSize; i++) {
                auto [node, pos] = q.front();
                q.pop();
                
                if (node->left) {
                    q.push({node->left, pos * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, pos * 2 + 2});
                }
            }
        }
        
        return maxWidth;
    }
};