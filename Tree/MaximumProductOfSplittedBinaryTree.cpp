class Solution {
public:
long long ts=0;
long long maxP=0;
int mod=1e9+7;
    long long getTotalsum(TreeNode* root) {
        if(root==NULL)
        return 0;
        return root->val+getTotalsum(root->left)+getTotalsum(root->right);
    }
    long long dfs(TreeNode* root){
        if(root==NULL)
        return 0;
        long long leftsum=dfs(root->left);
        long long rightsum=dfs(root->right);
        long long subTreesum=root->val+leftsum+rightsum;
        long long product=subTreesum*(ts-subTreesum);
        maxP=max(maxP,product);
        return subTreesum;
    }
    int maxProduct(TreeNode* root){
        ts=getTotalsum(root);
        dfs(root);
        return maxP%mod;
    }
};
