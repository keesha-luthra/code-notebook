/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) s.append("#,");
            else{
                s += to_string(node->val) + ",";
            }
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream ss(data);
        string s = " ";
        getline(ss, s, ',');

        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            getline(ss, s, ',');
            if(s != "#"){
                TreeNode* leftNode = new TreeNode(stoi(s));
                curr->left = leftNode;
                q.push(leftNode);
            }
            else curr->left = NULL;

            getline(ss, s, ',');
            if(s != "#"){
                TreeNode* rightNode = new TreeNode(stoi(s));
                curr->right = rightNode;
                q.push(rightNode);
            }
            else curr->right = NULL;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));