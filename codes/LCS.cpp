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

program for Prim's Minimum

// Spanning Tree (MST) algorithm. The program is

// for adjacency matrix representation of the graph

 

#include <bits/stdc++.h>

using namespace std;

 

// Number of vertices in the graph

#define V 5

 

// A utility function to find the vertex with

// minimum key value, from the set of vertices

// not yet included in MST

int minKey(int key[], bool mstSet[])

{

    // Initialize min value

    int min = INT_MAX, min_index;

 

    for (int v = 0; v < V; v++)

        if (mstSet[v] == false && key[v] < min)

            min = key[v], min_index = v;

 

    return min_index;

}

 

// A utility function to print the

// constructed MST stored in parent[]

void printMST(int parent[], int graph[V][V])

{

    cout << "Edge \tWeight\n";

    for (int i = 1; i < V; i++)

        cout << parent[i] << " - " << i << " \t"

             << graph[i][parent[i]] << " \n";

}

 

// Function to construct and print MST for

// a graph represented using adjacency

// matrix representation

void primMST(int graph[V][V])

{

    // Array to store constructed MST

    int parent[V];

 

    // Key values used to pick minimum weight edge in cut

    int key[V];

 

    // To represent set of vertices included in MST

    bool mstSet[V];

 

    // Initialize all keys as INFINITE

    for (int i = 0; i < V; i++)

        key[i] = INT_MAX, mstSet[i] = false;

 

    // Always include first 1st vertex in MST.

    // Make key 0 so that this vertex is picked as first

    // vertex.

    key[0] = 0;

   

    // First node is always root of MST

    parent[0] = -1;

 

    // The MST will have V vertices

    for (int count = 0; count < V - 1; count++) {

         

        // Pick the minimum key vertex from the

        // set of vertices not yet included in MST

        int u = minKey(key, mstSet);

 

        // Add the picked vertex to the MST Set

        mstSet[u] =  true;

 

        // Update key value and parent index of

        // the adjacent vertices of the picked vertex.

        // Consider only those vertices which are not

        // yet included in MST

        for (int v = 0; v < V; v++)

 

            // graph[u][v] is non zero only for adjacent

            // vertices of m mstSet[v] is false for vertices

            // not yet included in MST Update the key only

            // if graph[u][v] is smaller than key[v]

            if (graph[u][v] && mstSet[v] == false

                && graph[u][v] < key[v])

                parent[v] = u, key[v] = graph[u][v];

    }

 

    // Print the constructed MST

    printMST(parent, graph);

}

 

// Driver's code

int main()

{

    int graph[V][V] = { { 0, 2, 0, 6, 0 },

                        { 2, 0, 3, 8, 5 },

                        { 0, 3, 0, 0, 7 },

                        { 6, 8, 0, 0, 9 },

                        { 0, 5, 7, 9, 0 } };

 

    // Print the solution

    primMST(graph);

 

    return 0;

}



