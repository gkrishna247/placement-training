int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = malloc(2000 * sizeof(int*));
    *returnColumnSizes = malloc(2000 * sizeof(int));
    struct TreeNode* queue[2000];
    int head = 0, tail = 0, level = 0;
    queue[tail++] = root;
    *returnSize = 0;

    while (head < tail) {
        int count = tail - head;
        result[*returnSize] = malloc(count * sizeof(int));
        (*returnColumnSizes)[*returnSize] = count;
        for (int i = 0; i < count; i++) {
            struct TreeNode* node = queue[head++];
            result[*returnSize][level % 2 == 0 ? i : count - 1 - i] = node->val;
            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
        (*returnSize)++;
        level++;
    }
    return result;
}
