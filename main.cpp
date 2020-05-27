#include <iostream>
#include "graphType.h"

using namespace std;

int main()
{
	string vertices[] = { "Seattle", "San Francisco", "Los Angeles", "Denver", "Kansas", "Chicago", "Boston", "New York", "Atlanta", "Miami", "Dallas", "Houston"};
	int amountOfCities = sizeof(vertices) / sizeof(vertices[0]);
	graphType graph(amountOfCities);
	int cityNumber;
	char choice = 'Y';

	//Creating graph of the city map
	//Seattle(0) connecting points
	graph.createGraph(0, 1); //connects to San Francisco(1)
	graph.createGraph(0, 3); //connects to Denver(3)
	graph.createGraph(0, 5); //connects to Chicago(5)

	//San Francisco(1) connecting points
	graph.createGraph(1, 0); //connects to Seattle(0)
	graph.createGraph(1, 2); //connects to Los Angeles(2)
	graph.createGraph(1, 3); //connects to Denver(3)

	//Los Angeles(2) connecting points
	graph.createGraph(2, 1);  //connects to San Francisco(1)
	graph.createGraph(2, 3); //connects to Denver(3)
	graph.createGraph(2, 4); //connects to Kansas(4)
	graph.createGraph(2, 10); //connects to Dallas(10)

	//Denver(3) connecting points
	graph.createGraph(3, 0); //connects to Seattle(0)
	graph.createGraph(3, 1); //connects to San Francisco(1)
	graph.createGraph(3, 2); //connects to Los Angeles(2)
	graph.createGraph(3, 4); //connects to Kansas(4)
	graph.createGraph(3, 5); //connects to Chicago(5)

	//Kansas City(4) connecting points
	graph.createGraph(4, 2); //connects to Los Angeles(2)
	graph.createGraph(4, 3); //connects to Denver(3)
	graph.createGraph(4, 5); //connects to Chicago(5)
	graph.createGraph(4, 7); //connects to New York(7)
	graph.createGraph(4, 8); //connects to Atlanta(8)
	graph.createGraph(4, 10); //connects to Dallas(10)
	
	//Chicago(5) connecting points
	graph.createGraph(5, 0); //connects to Seattle(0)
	graph.createGraph(5, 3); //connects to Denver(3)
	graph.createGraph(5, 4); //connects to Kansas(4)
	graph.createGraph(5, 6); //connects to Boston(6)
	graph.createGraph(5, 7); //connects to New York(7)
	
	//Boston(6) connecting points
	graph.createGraph(6, 5); //connects to Chicago(5)
	graph.createGraph(6, 7); //connects to New York(7)

	//New York(7) connecting points
	graph.createGraph(7, 4); //connects to Kansas(4)
	graph.createGraph(7, 5); //connects to Chicago(5)
	graph.createGraph(7, 6); //connects to Boston(6)
	graph.createGraph(7, 8); //connects to Atlanta(8)

	//Atlanta(8) connecting points
	graph.createGraph(8, 4); //connects to Kansas(4)
	graph.createGraph(8, 7); //connects to New York(7)
	graph.createGraph(8, 9); //connects to Miami(9)
	graph.createGraph(8, 10); //connects to Dallas(10)
	graph.createGraph(8, 11); //connects to Houston(11)

	//Miami(9) connecting points
	graph.createGraph(9, 8); //connects to Atlanta(8)
	graph.createGraph(9, 11); //connects to Houston(11)

	//Dallas(10) connecting points
	graph.createGraph(10, 2); //connects to Los Angeles(2)
	graph.createGraph(10, 4); //connects to Kansas(4)
	graph.createGraph(10, 8); //connects to Atlanta(8)
	graph.createGraph(10, 11); //connects to Houston(11)

	//Houston(11) connecting points
	graph.createGraph(11, 8); //connects to Atlanta(8)
	graph.createGraph(11, 9); //connects to Miami(9)
	graph.createGraph(11, 10); //connects to Dallas(10)

	cout << "Graph Traversals\n";
	do
	{
		if (choice == 'Y')
		{
			cout << "Enter starting city using number from 0 - 11: ";
			cin >> cityNumber;
			cout << "You entered city name : " << vertices[cityNumber];
			cout << "\n\nStarting at " << vertices[cityNumber] << ", " << amountOfCities << " cities are searched in this Depth-First Search order :\n";
			graph.depthFirstTraversal(cityNumber, vertices);
			cout << "\n\nStarting at " << vertices[cityNumber] << ", " << amountOfCities << " cities are searched in this Breadth-First Search order :\n";
			graph.breadthFirstTraversal(cityNumber, vertices);
		}
		
		cout << "\nTry another city(Y / N) ";
		cin >> choice;
		choice = toupper(choice);
		
	} while (choice != 'N');

	return 0;
}