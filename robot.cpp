#include <iostream>
#include<vector>
using namespace std;
//机器人行走问题
//一个机器人从一个矩阵的上方走到下方共有几条路径
//1.dp
int CountWays(int x,int y)
{
  if(x==0||y==0)
    return 0;
  vector<vector<int>> arr(x,vector<int>(y,0));
  for(int i=0;i<x;i++)
  {
    for(int j=0;j<y;j++)
    {
      if(i==0&&j==0)
      {
        arr[i][j]=1;
      }
      else if(i==0)
      {
        arr[i][j]=arr[i][j-1];
      }
      else if(j==0)
      {
        arr[i][j]=arr[i-1][j];
      }
      else 
      {
        arr[i][j]=arr[i-1][j]+arr[i][j-1];
      }
    }
  }
  return arr[x-1][y-1];
}
int main()
{
  int x,y;
  while(cin>>x>>y)
  {
    cout<<CountWays(x,y)<<endl;
  }
  return 0;
}
