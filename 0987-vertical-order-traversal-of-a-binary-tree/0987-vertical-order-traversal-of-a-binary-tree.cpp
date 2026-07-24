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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, map<int, multiset<int>>> nodes;
        
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if (root) {
            q.push({root, {0, 0}});
        }
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* temp = p.first;
            int col = p.second.first;
            int row = p.second.second;
            
            nodes[col][row].insert(temp->val);
            
            if (temp->left) {
                q.push({temp->left, {col - 1, row + 1}});
            }
            if (temp->right) {
                q.push({temp->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> res;
        for (auto& colPair : nodes) {
            vector<int> colNodes;
            for (auto& rowPair : colPair.second) {
                colNodes.insert(colNodes.end(), rowPair.second.begin(), rowPair.second.end());
            }
            res.push_back(colNodes);
        }
        
        return res;
    }
};