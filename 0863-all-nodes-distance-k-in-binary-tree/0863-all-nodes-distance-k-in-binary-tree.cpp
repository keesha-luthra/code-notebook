/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> answer;
        // if(k == 0){
        //     answer.push_back(target->val);
        //     return answer;
        // }
        unordered_map<TreeNode*, TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                mpp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                mpp[temp->right] = temp;
                q.push(temp->right);
            }
        }

        set<TreeNode*> visited;
        int currDistance = 0;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            int levelSize = q.size();
            if(currDistance == k) break;
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(mpp[node] && visited.find(mpp[node]) == visited.end()){
                    q.push(mpp[node]);
                    visited.insert(mpp[node]);
                }
            }
            currDistance += 1;
        }
        while(!q.empty()){
            answer.push_back(q.front()->val);
            q.pop();
        }
        return answer;
    }
};