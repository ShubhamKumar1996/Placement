vector<int> inOrder(Node* root)
{
    vector<int>result;
    Node *curr = root;
    stack<Node *>stk;
    while(stk.empty()==false || curr!=NULL){
        while(curr!=NULL){
            stk.push(curr); curr = curr->left;
        }
        if(stk.empty()==true) break;
        curr = stk.top(); stk.pop();
        result.push_back(curr->data);
        curr = curr->right;
    }
    return result;
}