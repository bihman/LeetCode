/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

// 该题和前面“Rotate List”很相似，相同的思路

class Solution
{
public:
  void rotate(vector<int>& nums, int k)
  {
    int length = num.size();
    vector<int> res;
    if(length == 0 || k == 0)
      return;           // 该函数返回值为"void"
    k = k % length;
    if(k == 0)
      return;
    k = length - k;
    int i;
    for(i = k; k < length; i++)
      res.push_back(nums[i]);
    for(i = 0; i < k; i++)
      res.push_back(nums[i]);
    nums = res;
  }
};
