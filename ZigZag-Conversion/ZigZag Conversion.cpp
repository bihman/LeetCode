/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/************************************************
 * 分析：第1行和最后一行，每隔2*(numRows-1)打印一个字符
 * 中间斜对角线处，每隔2*(numRows-1-i)打印一个字符
 * **********************************************/
 
class Solution {
public:
    string convert(string s, int numRows) {
      int i,j;
      string res;
      if(numRows == 1 || s.size() = 1)
      {
        return res;
      }
      for(i = 0; i < numRows-1; i++)
      {
        for(j = i; j < s.size(); j = j+2*(numRows-1))
        {
          res = res+s[j];   // 垂直线上的元素
          if(i != 0 && i != numRows - 1 && j + 2*(numRows - i - 1) < s.size())
          {
            res = res + s[j + 2*(numRows - i - 1)];   // 对角线上的元素
          }
        }
      }
      return res;
