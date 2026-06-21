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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder){
        if(preorder.size() == 0 && inorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int leftSubtreesize = 0;
        int rootPos = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == root->val){
                rootPos = i;
                break;
            }
            leftSubtreesize++;
        }
        vector<int> preleft(preorder.begin() + 1, preorder.begin() + 1 + leftSubtreesize);
        vector<int> preright(preorder.begin() + 1 + leftSubtreesize, preorder.end());
        vector<int> inleft(inorder.begin(), inorder.begin() + rootPos);
        vector<int> inright(inorder.begin() + rootPos + 1, inorder.end());
        root->left = helper(preleft, inleft);
        root->right = helper(preright, inright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder);
    }
};