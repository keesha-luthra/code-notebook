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
private:
bool isLeaf(TreeNode* root){
    if(root->left == NULL && root->right == NULL) return true;
    else return false;
}
void path(TreeNode* root, vector<string> &ans, string path1){
    if(!root) return;
    
    // Add current node's value to the path
        if (!path1.empty()) path1 += "->";
        path1 += to_string(root->val);
    
    if(isLeaf(root)){
        ans.push_back(path1);
        return;
    }
    path(root->left, ans, path1);
    path(root->right, ans, path1);
}
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp;
        vector<string> ans;
        path(root, ans, temp);
        return ans;
    }
};