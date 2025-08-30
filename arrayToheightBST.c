/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 
 struct TreeNode* height(int*nums, int left, int right){
    if(left>right) return NULL;
    int mid=(left+right)/2;
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val=nums[mid];
    node->left=height(nums,left,mid-1);
    node->right=height(nums,mid+1,right);
    return node;
    
 }
 

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
   return height(nums,0,numsSize-1);
}
