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
    void mkpar(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
       

        if(root==NULL){
            return;
        }
        if(root->left){
            parent[root->left]=root;
            mkpar(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            mkpar(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        mkpar(root,parent);

        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>vis;

        vis[target]=true;

        int dis = 0;

        while(q.size()>0){
            int n = q.size();

            if(dis++==k){
                break;
            }
            for(int i =0;i<n;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left!=NULL && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right!=NULL && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }

                
            }
        }
        vector<int>ans;

        while(q.size()>0){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;




        
    }
};