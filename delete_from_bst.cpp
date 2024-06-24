class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            if(root->left==NULL and root->right==NULL) return NULL;
            else if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            else{
                TreeNode* cur = root->right;
                while(cur and cur->left){
                    cur = cur->left;
                }
                root->val = cur->val;
                root->right = deleteNode(root->right,cur->val);
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else root->right = deleteNode(root->right,key);
        return root;
    }
};
