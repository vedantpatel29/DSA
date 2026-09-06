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
    
    void serializehelper(TreeNode* root,string& s){
        if(root==NULL){
            s += "#,";
            return;
        }
        s+= to_string(root->val)+",";

        serializehelper(root->left,s);
        serializehelper(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string s;

        serializehelper(root,s);
        return s;

    }

    TreeNode* deserializehelper(queue<string>&q){
         string value = q.front();
         q.pop();

         if(value == "#"){
            return NULL;
         }
         TreeNode* root = new TreeNode(stoi(value));

         root->left = deserializehelper(q);
         root->right = deserializehelper(q);

         return root; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;

        string temp="";

        for(char c:data){

            if(c==','){
                q.push(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        return deserializehelper(q);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));