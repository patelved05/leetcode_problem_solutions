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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, inorderMap, postIndex, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, 
                              unordered_map<int, int>& inorderMap, 
                              int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndex = inorderMap[rootVal];
        
        root->right = buildTreeHelper(inorder, postorder, inorderMap, postIndex, rootIndex + 1, inEnd);
        root->left = buildTreeHelper(inorder, postorder, inorderMap, postIndex, inStart, rootIndex - 1);
        
        return root;
    }
};