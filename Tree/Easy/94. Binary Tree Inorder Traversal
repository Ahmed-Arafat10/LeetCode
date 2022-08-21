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
    vector<int> v1;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return v1;
        if(root->left) inorderTraversal(root->left);
        v1.push_back(root->val);
        if(root->right) inorderTraversal(root->right);
        return v1;
    }
};

//Sol 2 ------------------------------------------------------------

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

    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v1;
    if(root == NULL) return v1;
    stack<TreeNode*> st;
        TreeNode *cur = root;
        while(cur != NULL || st.size())
        {
            while(cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            v1.push_back(cur->val);
            cur = cur->right;
        }
        return v1;
    }
};
