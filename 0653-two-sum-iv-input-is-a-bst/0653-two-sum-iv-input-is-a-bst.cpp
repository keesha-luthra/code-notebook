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
class BSTIterator{
    stack<TreeNode*> st;
    bool dir;
    public:
        BSTIterator(TreeNode* root, bool dir){
            this->dir = dir;
            pushALL(root);
        }
        void pushALL(TreeNode* root){
            while(root){
                st.push(root);
                if(dir) root = root->left;
                else root = root->right;
            }
        }
        int next(){
            TreeNode* node = st.top();
            st.pop();
            if(dir) pushALL(node->right);
            else pushALL(node->left);
            return node->val;
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        // forward
        BSTIterator left(root, true); 
        // backward
        BSTIterator right(root, false); 
        int i = left.next();
        int j = right.next();
        while(i < j){
            if(i + j == k) return true;
            else if (i + j < k) i = left.next();
            else j = right.next();
        }
        return false;
    }
};