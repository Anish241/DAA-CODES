#include<iostream>
#include<vector>


using namespace std;

# define INF 1000000000

vector<int> Dijkstras(vector<vector<int>> graph,int source)
{
    int n = graph.size();
    vector<int> dist(n,INF);
    vector<bool> visited(n,false);
    dist[source] = 0;
    for(int i=0;i<n-1;i++)
    {
        int min_dist = INF;
        int min_index = -1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && dist[j]<min_dist)
            {
                min_dist = dist[j];
                min_index = j;
            }
        }
        visited[min_index] = true;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && graph[min_index][j]!=0 && dist[min_index]!=INF && dist[min_index]+graph[min_index][j]<dist[j])
            {
                dist[j] = dist[min_index]+graph[min_index][j];
            }
        }
    }
    return dist;
}

int main()
{
    int n;
    int e;
    cout<<"Enter the number of vertices and edges respectively: ";
    cin>>n>>e;

    vector<vector<int>> graph(n,vector<int>(n,0));
    cout<<"Enter the edges and their weights respectively: "<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int source;
    cout<<"Enter the source vertex: ";
    cin>>source;
    vector<int> dist = Dijkstras(graph,source);
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}

