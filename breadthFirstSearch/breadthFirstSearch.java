/**   	Created: 08/21/20
 *  	Modified: 11/24/20
 *  	Completed: 11/24/20
 * 
 * Description: 
 * 		Breadth first search, in this algorithm we use a boolean visited array. For simplicity, 
 *  	it is assumed that all vertices are reachable from the starting vertex. We start from the root or 
 *  	any arbitrary node and mark the node and move to the adjacent unmarked node and 
 *  	continue this loop until there is no unmarked adjacent node. Then backtrack and check for other unmarked 
 *  	nodes and traverse them. Finally print the nodes in the path.
 *  
 *  	@author Noel Brambila 
 */
package BFS;
import java.util.*; 

public class breadthFirstSearch {	// A directed graph using adjacency list representation 
   private int vertices;                                         
   private LinkedList<Integer> list[];                      //Adjacency Lists 

   breadthFirstSearch(int v) {             	            // Constructor 
	   vertices = v; 
	   list = new LinkedList[v]; 
	   for (int i = 0; i < v; ++i) 
		   list[i] = new LinkedList(); 
   }

   void addEdge(int root,int edge) {  	              	// Adding an edge into the graph 
	   list[root].add(edge); 
   } 

   void BFS(int root) {                               			// Outputs BFS traversal from given root 
	   boolean visited[] = new boolean[vertices];             	// Having all the vertices as not visited (By default set as false) 

	   LinkedList<Integer> queue = new LinkedList<Integer>(); 	// Create a queue for BFS

	   visited[root] = true; 		                            // Mark the current node as visited 
	   queue.add(root); 										

	   while (queue.size() != 0){ 
		   root = queue.poll();                               // Retrieve and remove a vertex from queue 
		   System.out.print(root + " "); 

		   Iterator<Integer> i = list[root].listIterator();    // Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it 
		   while (i.hasNext()) { 
			   int n = i.next(); 
			   if (!visited[n]) { 
				   visited[n] = true; 
				   queue.add(n); 
			   } 
		   } 
	   } 
   } 
} 