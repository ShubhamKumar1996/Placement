vector<int> Solution::preorderTraversal(TreeNode* root) {
    stack<TreeNode*>stk;
    vector<int>result;
    if(root==NULL) return result;
    TreeNode *curr = root;
    while(stk.empty()==false || curr!=NULL){
        while(curr!=NULL){
            stk.push(curr); result.push_back(curr->val); curr = curr->left;
        }
        curr = stk.top(); stk.pop();
        curr = curr->right;
    }
    return result;
}