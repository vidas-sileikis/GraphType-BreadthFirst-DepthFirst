#include <iostream>
#include <vector>
#include <queue>
#include "graphType.h"

using namespace std;

void graphType::depthFirstTraversal(int index, string *verticesNames)
{
	bool *isVisited = new bool[maxSize]; //Create an array of bool maxSize for already visited points
	for (int i = 0; i < maxSize; i++)
	{
		isVisited[i] = false; //Set all bool values to false
	}
	depthFirstTraversal(index, isVisited, verticesNames); //Call recursive function
	delete[] isVisited; //Deallocate memory
}
void graphType::depthFirstTraversal(int index, bool *isVisited, string* verticesNames) //Depth first search recursive algorithm
{
	cout << verticesNames[index] << ", "; //If function called, print out name of visited vertex
	isVisited[index] = true; //Set visited bool value to true

	for (auto i = adjList[index].begin(); i < adjList[index].end(); i++) //Iterate the vector from the beginning of the vector[index] to the end of the vector[index]
	{
		if (isVisited[*i] == false) //If vertex has not been visited
		{
			depthFirstTraversal(*i, isVisited, verticesNames); //Recursive call function again
		}
	}
}

void graphType::breadthFirstTraversal(int index, string *verticesNames) //Breadth first search
{
	bool* isVisited = new bool[maxSize]; //Create an array of bool maxSize for already visited points
	for (int i = 0; i < maxSize; i++)
	{
		isVisited[i] = false; //Set all bool values to false
	}

	queue<int> queue; //Create a queue to keep track of adjacent vertices visited

	isVisited[index] = true; //set first visited vertex to true
	//queue.push_back(index);
	queue.push(index); //add to the back of the queue the visited index

	while (queue.empty() == false) //As long as queue is not empty
	{
		index = queue.front(); //set index to be the front of queue
		queue.pop(); //get rid of the element in front of the queue

		cout << verticesNames[index] << ", "; //print out the vertex in front of the queue

		for (auto i = adjList[index].begin(); i < adjList[index].end(); i++) //Iterate the vector from the beginning of the vector[index] to the end of the vector[index]
		{
			if (isVisited[*i] == false) //If we did not visit the adjacent vertices
			{
				isVisited[*i] = true; //Set visited to be true
				queue.push(*i); //Insert iterative vector element into back of the queue
			}
		}
	}
}

void graphType::createGraph(int index, int point) //To create a graph using adjacency list representation
{
	adjList[index].push_back(point); //connect adjacency list[index] to point(drawing a line from vertices[index] to vertices[point]
}
graphType::graphType(int size) //Constructor for graph
{
	maxSize = size;
	adjList = new vector<int>[maxSize]; //Adjacency list is represented as vector of maxSize
}
graphType::~graphType()
{
	delete[] adjList; //Deallocate the memory occupied by the vertices
}