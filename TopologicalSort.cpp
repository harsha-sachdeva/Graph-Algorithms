#include <iostream>
#include <list>
#include <stack>
#include <fstream>
using namespace std;
ofstream fileOutput; 

class Graph
{
	int V;    
	list<int> *adj;
	void topoSort(int v, bool visited[], stack<int> &Stack);
	public:
	Graph(int V);   
	void addEdge(int v, int w);
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
} 

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::topoSort(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topoSort(*i, visited, Stack);
		Stack.push(v);
}

void Graph::topologicalSort()
{
	stack<int> Stack;
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topoSort(i, visited, Stack);
		while (Stack.empty() == false)
		{
			if(Stack.size()!=1)
			{
				fileOutput << (char)((int)Stack.top()+97)<<",";
			}
			else
				fileOutput << (char)((int)Stack.top()+97);
			Stack.pop();
		}
}
 
int main(int argv,char *argc[])
{
	int n=0,length=0;
	string str;
	char arr1[50];
	ifstream read(argc[1]);
	ifstream fileInput(argc[1]);
	fileOutput.open(argc[2]);
	while(getline(fileInput,str,'\n'))
		length++;
	for(int s=0;s<3;s++)      
		read>>arr1[s];
	n=arr1[0]-48;
	Graph g(n);
	for(int s=0;s<(2*n-1);s++)  
	{
		read>>arr1[s];
	}
	int count =0;
	while(getline(read,str,'\n'))  
	{
		if(count!=length-2)
		{
			for(int i=1;i<4;i++)
			{
				read>>arr1[i];
			}
			int vertex1=(int)arr1[1]-97;
			int vertex2=(int)arr1[3]-97;
			g.addEdge(vertex1,vertex2);
			count++;
		}
	}
	g.topologicalSort();
	return 0;
}
