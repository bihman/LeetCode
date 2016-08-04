/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
      vector<int> res;
      stack<TreeNode *> st;
      if(root == NULL)
        return NULL;
      else
      {
        TreeNode *p = root;
        while(!st.empty() || p)
        {
          while(p != NULL)
          {
            st.push(p);
            p = p->left;
          }
          if(!st.empty())
          {
            p = st.top();
            st.pop();
            res.push_back(p->val);
            p = p->right;
          }
        }
      }
      return res;
    }
};
