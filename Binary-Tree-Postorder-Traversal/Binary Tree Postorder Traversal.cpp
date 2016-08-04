/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode* root)
    {
      vector<int> res;
      stack<TreeNode *> st;
      TreeNode *p;
      int flag;   // 用于指示root的右结点是否被访问过
      if(root == NULL)
        return NULL;
      else
      {
        do
        {
          while(root != NULL)
          {
            st.push(root);
            root = root->left;
          }
          p = NULL;
          flag = 1;
          while(!st.empty() && flag)
          {
            root = st.top();
            if(root->right == p)
            {
              st.pop();
              res.push_back(root->val);
              p = root;
            }
            else
            {
              p = root->right;
              flag = 0;
            }
          }
        }while(!st.empty());
      }
      return res;
    }
};
