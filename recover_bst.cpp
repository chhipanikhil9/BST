class Solution {
public:
    TreeNode* first,*second,*pre;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(pre!=NULL){
            if(pre->val >= root->val){
                if(first==NULL){
                    first = pre;
                }
                second = root;
            }
        }
        pre = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = second = pre = NULL;
        inorder(root);
        if(first!=NULL and second!=NULL)
            swap(first->val,second->val);
    }
};
