/*
Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
*/

// The time complexity you've mentioned, O(N) + O(2E), is essentially the same as O(V + E) that I mentioned earlier. Here's why:
// - O(N): This represents the time complexity for visiting all nodes (vertices) in the graph, which is similar to O(V).
// - O(2E): This represents the time complexity for visiting all edges in the graph. Each edge is connected to two nodes, hence the factor of 2. However, in Big O notation, we typically ignore constant factors, so this is equivalent to O(E).
// So, the time complexity O(N) + O(2E) simplifies to O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph. This is the standard time complexity for Breadth-First Search (BFS) using a queue.


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;  //storing the traversal
        int vis[V]={0};  //visited array for all nodes
        vis[0]=1; //mark visited
        queue<int> q;

        q.push(0);

        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it:adj[node]){
                if(!vis[it]){   //agar visited nahi hai then push in queue
                vis[it]=1;
                q.push(it);  //pushing in queue
                }
            }
        }
        return bfs;
    }
};
   
//input stuff
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[6];  //this is 2d adj list
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}



