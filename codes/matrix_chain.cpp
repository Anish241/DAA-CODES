
#include <iostream>
#include <vector>
#include <climits>

using namespace std;


void printparanthesis(int i,int j,int n,vector<vector<int>> bracket,char &name)
{
    if(i==j)
    {
        cout<<name++;
        return;
    }
    cout<<"(";
    printparanthesis(i,bracket[i][j],n,bracket,name);
    printparanthesis(bracket[i][j]+1,j,n,bracket,name);
    cout<<")";
}

vector<vector<int>> matrix_chain(vector<int> matrices)
{
    vector<vector<int>> dp(matrices.size(), vector<int>(matrices.size(), 0));
    vector<vector<int>> bracket(matrices.size(), vector<int>(matrices.size(), 0));

    for(int i = 1; i < matrices.size(); i++)
    {
        dp[i][i] = 0;
    }

    for(int l = 2; l < matrices.size(); l++)
    {
        for(int i = 1; i < matrices.size() - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++)
            {
                int q = dp[i][k] + dp[k + 1][j] + matrices[i - 1] * matrices[k] * matrices[j];
                if(q < dp[i][j])
                {
                    dp[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name = 'A';
    cout << "Optimal Parenthesization is : ";
    printparanthesis(1, matrices.size() - 1, matrices.size(),bracket, name);
    cout << endl;
    return dp;
   
    

}

int main()
{   int n;
    cout<<"Enter the number of matrices : ";
    cin>>n;
    cout<<"Enter the dimensions of the matrices : ";
    vector<int> matrices(n+1);
    for(int i=0;i<=n;i++)
    {
        cin>>matrices[i];
    }
    vector<vector<int>> dp = matrix_chain(matrices);
    cout << "Minimum number of multiplications is : " << dp[1][matrices.size() - 1] << endl;
    cout<<"The dp table is : "<<endl;
    for(int i = 1; i < matrices.size(); i++)
    {
        for(int j = 1; j < matrices.size(); j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
