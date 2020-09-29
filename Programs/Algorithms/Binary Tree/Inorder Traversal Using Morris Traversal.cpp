vector<int> inOrder(Node* root)
{
    vector<int>result;
    Node *curr = root, *leftNode;
    while(curr!=NULL){
        if(curr->left==NULL){
            result.push_back(curr->data);
            curr = curr->right;
        }else{
            leftNode = curr->left;
            while(leftNode->right!=NULL && leftNode->right!=curr)
                leftNode = leftNode->right;
            leftNode->right = curr;
            leftNode = curr->left;
            curr->left = NULL;
            curr = leftNode;
        }
    }
    return result;
}