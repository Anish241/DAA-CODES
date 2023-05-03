#include<iostream>
#include<vector>
using namespace std;
void solveNQueen(vector<vector<int>>&solutions,vector<int>&current,int n,int row)
{
    if(row==n)
    {
        solutions.push_back(current);
        return ;
    }

    for(int col=0;col<n;col++)
    {   bool isValid = true;
        for(int i=0;i<row;i++ )
        {
            if(current[i]==col || abs(col-current[i])==abs(row-i)){
                isValid=false;
            }
        }
        if(isValid)
        {
            current[row]=col;
            solveNQueen(solutions,current,n,row+1);
        }
    }

    
}

int main() {
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;
    vector<vector<int>> solutions;
    vector<int> current(n);
    solveNQueen(solutions, current, n, 0);
    int numSolutions = solutions.size();
    cout << "Found " << numSolutions << " solutions.\n";
    // Print all solutions
    for (int i = 0; i < numSolutions; i++) {
        cout << "Solution " << i+1 << ":\n";
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (solutions[i][j] == k) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
