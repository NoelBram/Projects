/**     Created: 08/21/20
 *      Modified: 11/06/20
 *      Completed: 08/21/20 
 * 
 * Description: 
 *      Depth first search, in this algorithm we use a boolean array to not visit a node twice. 
 *      We start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and 
 *      continue this loop until there is no unmarked adjacent node. Then backtrack and check for other unmarked 
 *      nodes and traverse them. Finally print the nodes in the path.
 * 
 *  @author Noel Brambila 
 */

import java.io.*; 
import java.util.*; 
  
public class depthFirstSearch{                                            // This class represents a directed graph using adjacency list representation 
    private
        int V;                                          // Number of vertices 
    private 
        LinkedList<Integer> adj[];                      // Array  of lists for Adjacency List Representation 
    
        depthFirstSearch(int v){                                   // Constructor 
            V = v; 
            adj = new LinkedList[v]; 
            for (int i=0; i<v; ++i){
                adj[i] = new LinkedList(); 
            } 
        } 
  
    void addEdge(int v, int w){                         //Function to add an edge into the graph 
        adj[v].add(w);  // Add w to v's list. 
    } 
  
    void DFSUtil(int v,boolean visited[]){              // A function used by DFS 
        visited[v] = true;                              // Mark the current node as visited and print it 
        System.out.print(v+" "); 
  
        Iterator<Integer> i = adj[v].listIterator();    // Recur for all the vertices adjacent to this vertex 
        while (i.hasNext()){ 
            int n = i.next(); 
            if (!visited[n]){
                DFSUtil(n, visited); 
            }
        } 
    } 
  
    void DFS(int v){                                    // The function to do DFS traversal. It uses recursive DFSUtil() 
        boolean visited[] = new boolean[V];             // Mark all the vertices as not visited(set as false by default in java)   
        DFSUtil(v, visited);                            // Call the recursive helper function to print DFS traversal 
    } 
  
    public static void main(String args[]) { 
        depthFirstSearch g = new depthFirstSearch(4); 

        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(1, 2); 
        g.addEdge(2, 0); 
        g.addEdge(2, 3); 
        g.addEdge(3, 3); 
  
        System.out.println("Following is Depth First Traversal "+ 
                           "(starting from vertex 2)"); 
  
        g.DFS(2); 
    } 
} 