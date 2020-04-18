/**
 * Given the root node of a binary search tree, 
 * return the sum of values of all nodes with 
 * value between L and R (inclusive).
 *
 * The binary search tree is guaranteed to have unique values.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void counter(struct TreeNode* root, int L, int R, int* C);

void counter(struct TreeNode* root, int L, int R, int* C){
    
    if (root == NULL) return NULL;
    
    if (((root->val) >= L) & ((root->val) <= R)){
        *C += root->val;
    }
    
    if (root->val >= L)
        counter(root->left, L, R, C);
    
    if (root->val <= R)
        counter(root->right, L, R, C);
}

int rangeSumBST(struct TreeNode* root, int L, int R){
    int C=0;
    counter(root, L, R, &C);    
    return C;
}
