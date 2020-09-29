vector<int> Solution::postorderTraversal(TreeNode* root) {
    if(root==NULL) return {};
    vector<int>result;
    stack<TreeNode*>stk1, stk2;
    
    stk1.push(root);
    while(stk1.empty()==false){
        TreeNode* curr = stk1.top(); stk1.pop();
        stk2.push(curr);
        if(curr->left!=NULL) stk1.push(curr->left);
        if(curr->right!=NULL) stk1.push(curr->right);
    }
    while(stk2.empty()==false){
        result.push_back(stk2.top()->val); stk2.pop();
    }
    return result;
}