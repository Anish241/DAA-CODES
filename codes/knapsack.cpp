#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(double &a,double &b)
{
    double temp=a;
    a=b;
    b=temp;
}
double knapsack(vector<double>&weight,vector<double>&profit,int n,int w)
{
    vector<double>pbw(n,0);
    for(int i=0;i<n;i++)
    {
        pbw[i]=((double)profit[i]/(double)weight[i]);

    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(pbw[i]<pbw[j])
            {
                swap(pbw[i],pbw[j]);
                swap(weight[i],weight[j]);
                swap(profit[i],profit[j]);
            }
        }
    }
    double ans=0;
    double remain =w;
    vector<double>currweight(n,0);
   
    for(int i=0;i<n;i++)
    {
        if(remain>=weight[i])
        {
            remain-=weight[i];
            currweight[i]=1;
        }
        else
        {
            currweight[i]=(remain/weight[i]);
            break;
        }
    }

    for(int i=0;i<n;i++)
    {
        ans+=currweight[i]*profit[i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<currweight[i]<<" ";
    }
    cout<<endl;

   return ans;
}

int main()
{
    int n,w;
    cout<<"Enter the number of items and the capacity of the knapsack: "<<endl;
    cin>>n>>w;
    vector<double>weight(n);
    vector<double>profit(n);
    for(int i=0;i<n;i++)
    {   cout<<"Enter the weight and profit of item "<<i+1<<": ";
        cin>>weight[i]>>profit[i];
    }
   
    cout<<knapsack(weight,profit,n,w);
    return 0;
}