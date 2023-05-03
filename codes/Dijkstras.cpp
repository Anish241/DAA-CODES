//The program takes a graph as an input along with source and destination vertices and prints the shortest path between them using Dijkstra's algorithm.


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>


using namespace std;

struct Edge
{
    int src;
    int dest;
    int weight;
};

struct Node
{
    int vertex;
    int weight;
};

struct CompareNode
{
    bool operator()(const Node &n1, const Node &n2)
    {
        return n1.weight > n2.weight;
    }
};

// Function to print shortest path from source to all other vertices using Dijkstra's algorithm

void printPath(vector<int> const &prev, int i)
{
    if (i < 0)
        return;

    printPath(prev, prev[i]);
    cout << i << " ";
}

void shortestPath(vector<vector<Edge>> const &edges, int source, int N)
{
    
    priority_queue<Node, vector<Node>, CompareNode> minHeap;
    minHeap.push({source, 0});


    vector<int> dist(N, INT_MAX);

    
    dist[source] = 0;

    
    vector<bool> done(N, false);
    done[source] = true;

 
    vector<int> prev(N, -1);


    while (!minHeap.empty())
    {
        
        Node node = minHeap.top();
        minHeap.pop();


        int u = node.vertex;

   
        for (auto i : edges[u])
        {
            int v = i.dest;
            int weight = i.weight;

           
            if (!done[v] && (dist[u] + weight) < dist[v])
            {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                minHeap.push({v, dist[v]});
            }
        }


        done[u] = true;
    }

    for (int i = 1; i < N; ++i)
    {
        if (i != source && dist[i] != INT_MAX)
        {
            cout << "Path (" << source << " —> " << i << "): Minimum cost = "
                 << dist[i] << " and ";
            cout << "Shortest path is ";
            printPath(prev, i);
            cout << endl;
        }
    }
}


int main()
{

}

