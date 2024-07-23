struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0) return NULL;
    int rootVal = postorder[postorderSize - 1];
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    int i;
    for (i = 0; inorder[i] != rootVal; i++);
    root->left = buildTree(inorder, i, postorder, i);
    root->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, postorderSize - i - 1);
    return root;
}
