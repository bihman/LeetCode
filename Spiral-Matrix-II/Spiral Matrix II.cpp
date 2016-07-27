/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

// 比第一题简单多了,时间复杂度(O^2);
// 1.
class Solution
{
public:
  vector<vector<int> > generateMatrix(int n)
  {
    vector<vector<int> > matrix(n, vector<int> (n));
    int i,j;
    int m = 1;
    for(i = 0; i < n / 2; i++)
    {
      // 从左向右
      for(j = i; j < n-i-1; j++)
        matrix[i][j] = m++;
      // 从上向下
      for(j = i; j < n-i-1; j++)
        matrix[j][n-1-i] = m++;
      // 从右向左
      for(j = n-1-i; j > i; j--)
        matrix[n-1-i][j] = m++:
      // 从下向上
      for(j = n-1-i; j > i; j--)
        matrix[j][i] = m++;
    }
    if(n % 2 == 1)
      matrix[n/2][n/2] = m;
    return matrix;
  }
};


// 2.
class Solution
{
public:
  vector<vector<int> > generatematrix(int n)
  {
    vector<vector<int> > matrix(n, vector<int> (n));
    int mm = 0, nn = n-1;
    int count = 1;
    int i;
    while(mm < nn)
    {
      // 从左向右
      for(i = mm; i < nn; i++)
        matrix[mm][i] = count++;
      // 从上向下
      for(i = mm; i < nn; i++)
        matrix[i][nn] = count++;
      // 从右向左
      for(i = nn; i > mm; i--)
        matrix[nn][i] = count++;
      // 从下向上
      for(i = nn; i > mm; i--)
        matrix[i][mm] = count++;
      mm++;
      nn--;
    }
    if(mm == nn)
      matrix[mm][mm] = count;
    return matrix;
    
  }
};
