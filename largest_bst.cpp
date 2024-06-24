// Use the postorder so that you can use the left tree size and the right tree size and root it self(+1);
int maxSize;
vector<int> postorder(Node* root){
    if(root==NULL) return {INT_MAX,INT_MIN,0};// min,max,size
    vector<int> left = postorder(root->left);
    vector<int> right = postorder(root->right);
    if(!(root->data>left[1] and root->data<right[0])){
        // not a BST
        return {INT_MIN,INT_MAX,0};
    }
    int sz = 1+left[2]+right[2];
    maxSize = max(maxSize,sz);
    int mini = min(left[0],root->data);
    int maxi = max(right[1],root->data);
    return {mini,maxi,sz};
}
int largestBst(Node *root)
{
  //Your code here
  maxSize = 0;
  postorder(root);
  return maxSize;
}
