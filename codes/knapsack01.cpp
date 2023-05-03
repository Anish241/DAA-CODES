

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_profit(vector<int>&weight,vector<int>&profit,int currprofit,int n,int w,int index)
{
     int maxProfit =0;
        if(index==n)
        {   maxProfit = max(maxProfit,currprofit);
            return maxProfit;
        }
        if(w-weight[index]>=0)
        {
            maxProfit = max(maxProfit,max_profit(weight,profit,currprofit+profit[index],n,w-weight[index],index+1));
        }
        maxProfit = max(maxProfit,max_profit(weight,profit,currprofit,n,w,index+1));
        return maxProfit;
}

int main()
{
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<int> weight(n,0);
    vector<int> profit(n,0);
    cout<<"Enter the weights and profit of the items: ";
    for(int i=0;i<n;i++)
    {
        cin>>weight[i]>>profit[i];
    }
    int w;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>w;
    cout<<"The maximum profit is: "<<max_profit(weight,profit,0,n,w,0)<<endl;
    return 0;
}