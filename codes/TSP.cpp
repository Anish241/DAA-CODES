#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

int TSP(vector<vector<int>>&dist,int currmask,int pos,int mask)
{
    if(mask==currmask)
    {
        return dist[pos][0];
    }
    int ans=INT_MAX;
    for(int i=0;i<dist.size();i++)
    {
        if((currmask&(1<<i))==0)
        {
            int temp=dist[pos][i]+TSP(dist,currmask|(1<<i),i,mask);
            ans=min(ans,temp);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>dist(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dist[i][j];
        }
    }
    int mask=(1<<n)-1;
    cout<<TSP(dist,1,0,mask);
    return 0;
}

