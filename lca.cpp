// if both are left go left, else if both are right go right, else just return the root because this root is 
// partitioning both node in left and right and this is BST so this root gonna be the LCA;
// Time: O(H)
// space: O(H) recursion

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(root==NULL) return root;
  if(root->val>p->val and root->val>q->val){
      return lowestCommonAncestor(root->left,p,q);
  }
  else if(root->val < p->val and root->val < q->val){
      return lowestCommonAncestor(root->right,p,q);
  }
  else return root;
}
