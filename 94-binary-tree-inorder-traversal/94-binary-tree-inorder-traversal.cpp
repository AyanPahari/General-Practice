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
        
        vector<int> inorder;
        if(!root) return inorder;
        stack<TreeNode*> st;
        st.push(root);
        while (st.size() > 0)
        {
            TreeNode* node = st.top();
            if (node->left != NULL)
            {
                st.push(node->left);
                node->left = NULL;
            }
            else
            {
                inorder.push_back(node->val);
                st.pop();
                if (node->right != NULL)
                {
                    st.push(node->right);
                    node->right = NULL;
                }
            }
        }  
        return inorder; 
    }
};