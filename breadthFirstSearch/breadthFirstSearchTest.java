package BFS;

public class breadthFirstSearchTest{
	public static void main(String args[]){                 	
		breadthFirstSearch list = new breadthFirstSearch(4);	// Instantiating a LinkedList with 4 vertices 

		list.addEdge(0, 1); 
		list.addEdge(0, 2); 
		list.addEdge(1, 2); 
		list.addEdge(2, 0); 
		list.addEdge(2, 3); 
		list.addEdge(3, 3); 

		System.out.println(" The following is a Breadth First Traversal that starts from vertex 2"); 

		list.BFS(2); 
	} 
}