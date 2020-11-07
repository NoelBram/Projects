/**   	Created: 08/21/20
 *  	Modified: 11/06/20
 *  	Completed: 
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

// Java program to print BFS traversal from a given source vertex. 
// BFS(int s) traverses vertices reachable from s. 
import java.io.*; 
import java.util.*; 

public class breadthFirstSearch {       // This class represents a directed graph using adjacency list representation 
	private int V;                                          // Number of vertices 
	private LinkedList<Integer> adj[];                      //Adjacency Lists 

	breadthFirstSearch(int v) {             	            // Constructor 
		V = v; 
		adj = new LinkedList[v]; 
		for (int i=0; i<v; ++i) 
			adj[i] = new LinkedList(); 
	} 

	void addEdge(int v,int w){  	                        // Function to add an edge into the graph 
		adj[v].add(w); 
	} 

	void BFS(int s){                                	    // prints BFS traversal from a given source s 
		boolean visited[] = new boolean[V];                 // Mark all the vertices as not visited(By default set as false) 

		LinkedList<Integer> queue = new LinkedList<Integer>();      // Create a queue for BFS

		visited[s]=true; 		                            // Mark the current node as visited and enqueue it 
		queue.add(s); 

		while (queue.size() != 0){ 
			s = queue.poll();                               // Dequeue a vertex from queue and print it 
			System.out.print(s+" "); 

			Iterator<Integer> i = adj[s].listIterator();    // Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it 
			while (i.hasNext()) { 
				int n = i.next(); 
				if (!visited[n]) { 
					visited[n] = true; 
					queue.add(n); 
				} 
			} 
		} 
	} 

	public static void main(String args[]){                 	// Driver method to 
		breadthFirstSearch g = new breadthFirstSearch(4); 

		g.addEdge(0, 1); 
		g.addEdge(0, 2); 
		g.addEdge(1, 2); 
		g.addEdge(2, 0); 
		g.addEdge(2, 3); 
		g.addEdge(3, 3); 

		System.out.println("Following is Breadth First Traversal "+ 
						"(starting from vertex 2)"); 

		g.BFS(2); 
	} 
} 
// This code is contributed by Aakash Hasija 

