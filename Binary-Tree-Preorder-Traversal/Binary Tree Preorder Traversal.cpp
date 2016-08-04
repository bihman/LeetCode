/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive so
*/

// 该题不能使用递归的方法，可能会超时

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
    vector<int> preorderTraversal(TreeNode* root)
    {
      vector<int> res;
      stack<TreeNode *> st;
      TreeNode *p;
      if(root == NULL)
        return NULL;
      else
      {
        st.push(root);
        while(!st.empty())
        {
          p = st.top();
          st.pop();
          res.push_back(p->val);
          if(p->right != NULL)
            st.push(p->right);
          if(p->left != NULL)
            st.push(p->left);
        }
      }
      return res;
    }
};
