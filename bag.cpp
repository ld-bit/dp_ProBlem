//背包问题
//给定两个数组分别代表各个物品所需要的空间和所创造的价值,给定m空间大小的背包,求如何安排使得背包里边所放物品的值最大
#include<iostream>
#include<vector>
using namespace std;
int MaxMoney(vector<int>& key,vector<int>& val,int m)
{
//状态: 开辟一个二维的矩阵dp[i][j],i代表要对第几个物品进行操作,j代表当前背包的最大值是多少,dp[i][j]代表的是当前大小的背包所能存放物品的最大值
//转移方程: 如果当前大小的背包放不下当前大小的物品,则当前背包的大小所能装的价值为上一个物品所对应的价值
//          如果当前大小的背包的物品能放下物品,则要考虑要不要把当前的物品放进去,判断的方法是去判断当前物品的价值+需要移除物品未放置 的物品价值之和与未放置当前物品之前,当前背包容纳量
//          的较小值
  //初始条件: 当背包数目为0或者还未尝试防止一个任何一个物品的时候,当前背包容量对应的价值大小势必为0
   vector<vector<int>>dp(key.size()+1,vector<int>(m+1,0));
   for(size_t i=1;i<=key.size();i++)  //迭代能放置的物品
   {
    for(int j=1;j<=m;++j)  //迭代所能放置背包的所有可能大小
    {
     if(key[i-1]>j) //放不下
     {
      dp[i][j]=dp[i-1][j];
     }
     else  //能放下
     {
      dp[i][j]= max(dp[i-1][j],dp[i-1][j-key[i-1]]+val[i-1]);
     }
    }
   }
   return  dp[key.size()][m];
}
int main()
{
  int size;
  cout<<"please cin size"<<endl;
  while(cin>>size)
  {
  vector<int>key(size,0);
  vector<int>val(size,0);
  cout<<"please cin key"<<endl;
  for(auto& e: key)
  {
    cin>>e;
  }
  cout<< "please cin val" <<endl;
  for(auto& e: val)
  {
    cin>>e;
  }
  int m=0;
  cout<<"please cin m"<<endl;
  cin>>m;
  cout<<MaxMoney(key,val,m)<<endl;
  cout<<"please cin size"<<endl;
  }
  return 0;
}
