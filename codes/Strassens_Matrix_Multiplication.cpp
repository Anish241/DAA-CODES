#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> addMatrices(vector<vector<int>>A,vector<vector<int>> B)
{   int n = A.size();
    vector<vector<int>> C;
    C.resize(n, vector<int>(n, 0));

    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    return C;
}
vector<vector<int>> subtractMatrices(vector<vector<int>>A,vector<vector<int>> B)
{   int n = A.size();
     vector<vector<int>> C;
    C.resize(n, vector<int>(n, 0));

    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            C[i][j]=A[i][j]-B[i][j];
        }
    }
    return C;
}

vector<vector<int>> strassenMultiplication(vector<vector<int>>A,vector<vector<int>>B)
{
    int n = A.size();
    vector<vector<int>> C;
    C.resize(n, vector<int>(n, 0));

    if (n==1)
    {
       C[0][0]=A[0][0]*B[0][0];
    }
    else{
        int halfN = n/2;
        vector<vector<int>> A11(halfN,vector<int>(halfN,0));
        vector<vector<int>> A12(halfN,vector<int>(halfN,0));
        vector<vector<int>> A21(halfN,vector<int>(halfN,0));
        vector<vector<int>> A22(halfN,vector<int>(halfN,0));
        vector<vector<int>> B11(halfN,vector<int>(halfN,0));
        vector<vector<int>> B12(halfN,vector<int>(halfN,0));
        vector<vector<int>> B21(halfN,vector<int>(halfN,0));
        vector<vector<int>> B22(halfN,vector<int>(halfN,0));

        for(int i=0;i<halfN;i++)
        {
            for(int j=0;j<halfN;j++)
            {
                A11[i][j]=A[i][j];
                A12[i][j]=A[i][j+halfN];
                A21[i][j]=A[i+halfN][j];
                A22[i][j]=A[i+halfN][j+halfN];
                B11[i][j]=B[i][j];
                B12[i][j]=B[i][j+halfN];
                B21[i][j]=B[i+halfN][j];
                B22[i][j]=B[i+halfN][j+halfN];
            }
        }
       vector<vector<int>> P = strassenMultiplication(addMatrices(A11,A22),addMatrices(B11,B22));
       vector<vector<int>> Q = strassenMultiplication(B11,addMatrices(A11,A22));
       vector<vector<int>> R = strassenMultiplication(A11,subtractMatrices(B12,B22));
       vector<vector<int>> S = strassenMultiplication(A22,subtractMatrices(B21,B11));
       vector<vector<int>> T = strassenMultiplication(B22,addMatrices(A11,A12));
       vector<vector<int>> U = strassenMultiplication(subtractMatrices(A21,A11),addMatrices(B11,B12));
       vector<vector<int>> V = strassenMultiplication(addMatrices(B21,B22),subtractMatrices(A12,A22)); 

       vector<vector<int>> C11 = addMatrices(subtractMatrices(addMatrices(P,S),T),V);
       vector<vector<int>> C12 = addMatrices(R,T);
       vector<vector<int>> C21 = addMatrices(Q,S);
       vector<vector<int>> C22 = addMatrices(subtractMatrices(addMatrices(P,R),Q),U);

       for (int i=0;i<halfN;i++)
       {
        for (int j=0;j<halfN;j++)
        {
            C[i][j]=C11[i][j];
            C[i][j+halfN]=C12[i][j];
            C[i+halfN][j]=C21[i][j];
            C[i+halfN][j+halfN]=C22[i][j];
        }
       }


    }

    return C;
}

void printMatrix(vector<vector<int>>A)
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A.size();j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
 //take input of matrix A and B
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    vector<vector<int>> A(n,vector<int>(n,0));
    vector<vector<int>> B(n,vector<int>(n,0));
    vector<vector<int>> C(n,vector<int>(n,0));
    cout<<"Enter the elements of matrix A: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"Enter the elements of matrix B: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>B[i][j];
        }
    }
    C = strassenMultiplication(A,B);
    cout<<"The resultant matrix is: "<<endl;
    printMatrix(C);

return 0;
}