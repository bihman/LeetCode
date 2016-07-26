/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/


// v1.0，暴力解决

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> res;
      int i,j;
      for(i = 0; i < nums.size() - 1; i++)
      {
        for(j = i + 1; j < nums.size(); j++)
        {
          if(nums[i] + nums[j] == target)
          {
            res.push_back(i);
            res.push_back(j);
            break;
          }
        }
      }
      return res;
    }
};
