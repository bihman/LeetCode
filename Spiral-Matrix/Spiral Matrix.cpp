/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

// 螺旋矩阵问题
// 时间复杂度为(O^2)

class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix)
  {
    vector<int> res;
    if(matrix.empty())
      return res;
    int m = matrix.size()-1;        // rows
    int n = matrix[0].size()-1;     // columns
    int x = 0, y = 0;               
    int i,j;                      // i->x，j->y
    while(1)
    {
      // 从左向右
      for(j = y; j <= n; j++)
        res.push_back(matrix[x][j]);
      if(++x > m)
        break;
      // 从上向下
      for(i = x; i <= m; i++)
        res.push_back(matrix[i][n]);
      if(y > --n)
        break;
      // 从右向左
      for(j = n; j >= y; j--)
        res.push_back(matrix[m][j]);
      if(x > --m)
        break;
      // 从下向上
      for(i = m; i >= x; i--)
        res.push_back(matrix[y][i]);
      if(++y > n)
        break;
    }
    return res;
  }
};
