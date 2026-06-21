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
    unordered_map<int, int> mpp;
    int postIdx;
    TreeNode* helper(vector<int>& postorder, int inStart, int inEnd){
        if(inStart > inEnd) return NULL;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int rootPos = mpp[rootVal];

        root->right = helper(postorder, rootPos + 1, inEnd);
        root->left = helper(postorder, inStart, rootPos - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        int n = postorder.size();
        postIdx = n - 1;
        return helper(postorder, 0, inorder.size() - 1);
    }
};