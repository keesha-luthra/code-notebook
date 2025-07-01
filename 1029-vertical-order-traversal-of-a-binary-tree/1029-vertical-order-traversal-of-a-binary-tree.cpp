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
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;
        q.push({root, {0, 0}});
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            nodes[x][y].insert(temp->val);
            if(temp->left) q.push({temp->left, {x - 1, y + 1}});
            if(temp->right) q.push({temp->right, {x + 1, y + 1}});
        }
        vector<vector<int>> ans;
        for(auto it : nodes){
            vector<int> temp1;
            for(auto it1 : it.second){
                temp1.insert(temp1.end(), it1.second.begin(), it1.second.end());
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};