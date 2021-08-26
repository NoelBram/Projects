/*  Description:
    Sorting projects

    Created: 08/02/20
    Modified: 08/03/20
    Completed: 
*/
#include "brambila.h"
#include "sort.h"

void sort::addEdge(int v, int w){ 
	adj[v].push_back(w);                // Add w to v’s list. 
} 

sort::sort(int verticies) { 
            this->verticies = verticies; 
            adj = new list<int>[verticies]; 
} 

void sort::BFS(int s){ 
	bool *visited = new bool[verticies];// Mark all the vertices as not visited 
	for(int i = 0; i < verticies; i++){
        visited[i] = false; 
    } 

	list<int> queue;    	            // Create a queue for BFS 

	visited[s] = true;              	// Mark the current node as visited and enqueue it 
	queue.push_back(s); 

	list<int>::iterator i;              // 'i' will be used to get all adjacent vertices of a vertex 

	while(!queue.empty()) {             // Dequeue a vertex from queue and print it 
		s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 

		                                // Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it 
		for (i = adj[s].begin(); i != adj[s].end(); ++i) { 
			if (!visited[*i]) { 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 
} 