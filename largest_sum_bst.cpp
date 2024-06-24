// same as largest bst
class Solution {
public:
    int maxSum;
    vector<int> postorder(TreeNode* root){
        if(root==NULL) return {INT_MAX,INT_MIN,0};//min,max,sum
        vector<int> left = postorder(root->left);
        vector<int> right = postorder(root->right);
        // not a BST return some range that no will come in
        if(!(root->val>left[1] and root->val<right[0])){
            return {INT_MIN,INT_MAX,0};
        } 
        // BST 
        int sum = root->val + left[2] + right[2];
        maxSum = max(maxSum,sum);
        int mini = min(root->val,left[0]);
        int maxi = max(root->val,right[1]);
        return {mini,maxi,sum};
    }
    int maxSumBST(TreeNode* root) {
        maxSum=0;
        postorder(root);
        return maxSum;
    }
};
