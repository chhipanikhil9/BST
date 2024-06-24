// Time: O(N*H)
// space: O(H)
// made class to do inorder iterativly
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if(reverse)pushAll(top->left);
        else pushAll(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    private:
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse) root = root->right;
            else root = root->left;
        }
    }
};

class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false);// sorted in increasing order
        BSTIterator r(root,true);// sorted in decreasing order
        // Two pointer approach
        int i = l.next();
        int j = r.next();// before;
        while(i<j){
            if(i+j==k) return true;
            if(i+j<k) i = l.next();// l++
            else j = r.next();// before r--
        }
        return false;
    }
};
