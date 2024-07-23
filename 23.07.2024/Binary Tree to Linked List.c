void flatten(struct TreeNode* root) {
    while (root) {
        if (root->left) {
            struct TreeNode* rightMost = root->left;
            while (rightMost->right) rightMost = rightMost->right;
            rightMost->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}
