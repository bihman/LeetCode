/*Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

/*
1. 负数问题
2. 边界的分析
*/

class Solution
{
public:
  int reverse(int x)
  {
    long long sum = 0;
    long long t = x;
    bool sign = false;
    if(t < 0)
    {
      t = -t;
      sign = true;
    }
    
    int r;
    while(x)
    {
      r = x % 10;
      x = x / 10;
      sum = sum * 10 + r;
    }
    
    if(sign)
    {
      if(sum > 2147483648)
        return 0;
      else
        return -sum;
    }
    else
    {
      if(sum > 2147483647)
        return 0;
      else
        return sum;
    }
  }
};
