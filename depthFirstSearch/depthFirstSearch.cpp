/*  Created: 08/21/20
    Modified: 11/06/20
    Completed: 08/21/20

Description: 
    Depth first search, in this algorithm we use a boolean array to not visit a node twice. 
    We start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and 
    continue this loop until there is no unmarked adjacent node. Then backtrack and check for other unmarked 
    nodes and traverse them. Finally print the nodes in the path.
*/
#include "brambila.h"
class Graph {
    private: 
        int V;                                  // Numbeer of vertices 
        list<int> *adj;                         // Pointer to an array containing adjacency lists 
        void DFSUtil(int v, bool visited[]);    // A recursive function used by DFS 
    
    public: 
        Graph(int V);                           // Constructor 
        void addEdge(int v, int w);             // function to add an edge to graph
        void DFS(int v);                        // DFS traversal of the vertices reachable from v 
}; 
  
Graph::Graph(int V){                            // Declaring the constructor 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w){ 
    adj[v].push_back(w);                        // Add w to v’s list. 
} 
  
void Graph::DFSUtil(int v, bool visited[]){ 
    visited[v] = true;                          // Mark the current node as visited and print it 
    cout << v << " "; 
    list<int>::iterator i;                      // Recur for all the vertices adjacent to this vertex 
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
            DFSUtil(*i, visited);               // runing though the graph through recursion 
        }
    } 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v){ 
    bool *visited = new bool[V];                // Mark all the vertices as not visited 
    for (int i = 0; i < V; i++){
        visited[i] = false; 
    }
    DFSUtil(v, visited);                        // Call the recursive helper function to print DFS traversal  
} 
  
int main() {                                    // Driver code 
    Graph g(4);                                 // Create a graph given in the above diagram 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    cout << endl;
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
    cout << endl << endl;
    return 0; 
} 