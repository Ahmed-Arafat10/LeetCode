/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool solve(TreeNode *l, TreeNode *r)
    {
        if(l && r)
        {
            if(l->val != r->val) return 0;
            return solve(l->left, r->right) * solve(l->right, r->left);
        }
        else if (!l && r || l && !r ) return 0;
        return 1;
    }
    bool isSymmetric(TreeNode* root)
    {
        if(solve(root->left,root->right)) return 1;
        return 0;
    }
};


/// ---> Improved Code

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode *l , TreeNode *r)
    {
        if (!l || !r ) return l == r;
        if(l->val != r->val) return 0;
        return solve(l->left , r->right) && solve(l->right , r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return solve(root->left,root->right);
    }
};
