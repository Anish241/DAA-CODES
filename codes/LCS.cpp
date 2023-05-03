#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int maxx(int a,int b)
{
    if (a>b)
    {
        return a;
    }
    else if(a==b)
    {
        return a;
    }
    else{
        return b;
    }
}
string LCS(string str1,string str2)
{
   int m = str1.size();
   int n= str2.size();

   vector<vector<int>> dp(m+1,vector<int>(n+1,0));

   for(int i=1;i<=m;i++)
   {
    for(int j=1;j<=n;j++)
    {
        if(str1[i-1]==str2[j-1])
        {
            dp[i][j]= dp[i-1][j-1]+1;
        }
        else{
            dp[i][j]=maxx(dp[i][j-1],dp[i-1][j]);
        }
    }
   }
  
  // Printing the dp table
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
   int len = dp[m][n];
   vector<char> lcs(len);
   int i=m;int j=n;

   while(i>0 && j>0)
   {
         if(str1[i-1]==str2[j-1])
         {
              lcs[len-1]=str1[i-1];
              i--;j--;len--;
         }
         else if(dp[i-1][j]>dp[i][j-1])
         {
              i--;
         }
         else{
              j--;
         }
   }

   return string(lcs.begin(),lcs.end());

}

int main()
{
    string str1,str2;
    cout<<"Enter the first string"<<endl;
    cin>>str1;
    cout<<"Enter the second string"<<endl;
    cin>>str2;
    string ans = LCS(str1,str2);
    cout<<"The length of longest common subsequence is :"<<endl;
    cout<<ans.size()<<endl;
    cout<<"The longest common subsequence is :"<<endl;
    cout<<ans<<endl;

    
    return 0;
}
