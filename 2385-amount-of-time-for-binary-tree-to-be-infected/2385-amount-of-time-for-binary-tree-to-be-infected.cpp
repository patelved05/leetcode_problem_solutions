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
    int amountOfTime(TreeNode* root, int start) {
       
        unordered_map<int, vector<int>> graph;
        buildGraph(root, graph);
        
       
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        
        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            bool hasNext = false;
            
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : graph[curr]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                        hasNext = true;
                    }
                }
            }
            
            if (hasNext) minutes++;
        }
        
        return minutes;
    }
    
private:
    void buildGraph(TreeNode* node, unordered_map<int, vector<int>>& graph) {
        if (!node) return;
        
        if (node->left) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            buildGraph(node->left, graph);
        }
        
        if (node->right) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            buildGraph(node->right, graph);
        }
    }
};