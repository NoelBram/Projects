/*  Description:
    Sorting projects

    Created: 07/03/20
    Modified: 08/03/20
    Completed: 
*/
#include "brambila.h"
class sort {                              // Breadth First Search                            
    private:
        int verticies;                  // Number of vertices 
        list<int> *adj;                 // Pointer to an array containing adjacency lists 
    public: 
        sort(int verticies);
        void addEdge(int v, int w);     // function to add an edge to graph 
        void BFS(int s);                // prints BFS traversal from a given source s 
}; 
