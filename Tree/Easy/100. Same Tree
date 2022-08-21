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
    bool flag = 0;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        //cout<<p->val<<"-"<<q->val<<"\n"; 
        if(!p && q || p && !q){flag = 1;return 0;}
        if(!p->left && q->left || p->left && !q->left) flag = 1;
        if(p->left && q->left) isSameTree(p->left,q->left);
        if(p->val != q->val) flag = 1;
        if(p->right && q->right) isSameTree(p->right,q->right);
        if(!p->right && q->right || p->right && !q->right) flag = 1;
        if(flag) return 0;
        return 1;
    }
};
