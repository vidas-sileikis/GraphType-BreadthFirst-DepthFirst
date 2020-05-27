#include <vector>

using namespace std;
class graphType
{
public:
	void createGraph(int index, int point); //To create a graph using adjacency list representation
	void depthFirstTraversal(int index, bool* isVisited, string* verticesNames); //Depth first search recursive algorithm
	void depthFirstTraversal(int index, string* verticesNames); //helper function to call depth first search
	void breadthFirstTraversal(int index, string *verticesNames); //Breadth first search
	graphType(int size); // constructor, graph is an array of pointers to adjacency list
	~graphType(); //Destructor, deallocate storage occupied by vertices
private:
	int maxSize; //maximum number of vertices
	std::vector<int>* adjList; //pointer to adjacency list
};