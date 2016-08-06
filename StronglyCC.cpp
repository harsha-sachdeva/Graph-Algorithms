#include <iostream>
#include <list>
#include <stack>
#include <fstream>
using namespace std;

ofstream fileOutput;
char m[20];
int b=0;

class Graph
{
	int V;   
	list<int> *adj;    
	void fillOrder(int v, bool visited[], stack<int> &Stack);
	void DFS(int v, bool visited[]);
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void printStronglyCC();
		Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
 
void Graph::DFS(int v, bool visited[])
{
	visited[v] = true;
	m[b++]=(char)((int)v+97);
	m[b++]=',';
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
        	if (!visited[*i])
        		DFS(*i, visited);
}
 
Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
        	list<int>::iterator i;
        	for(i = adj[v].begin(); i != adj[v].end(); ++i)
        	{
        		g.adj[*i].push_back(v);
        	}
    	}
	return g;
}
 
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}
 
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
	        if(!visited[*i])
		        fillOrder(*i, visited, Stack);
		Stack.push(v);
}
 
void Graph::printStronglyCC()
{
	stack<int> Stack;
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
        visited[i] = false;
	for(int i = 0; i < V; i++)
	        if(visited[i] == false)
		        fillOrder(i, visited, Stack);
		Graph gr = getTranspose();
		for(int i = 0; i < V; i++)
       			visited[i] = false;
    		while (Stack.empty() == false)
    		{
        		int v = Stack.top();
        		Stack.pop();
        		if (visited[v] == false)
        		{
            			gr.DFS(v, visited);
				char a;
				for (int x = 0; x < b; ++x)
				{
					for (int r = x + 1; r < b; ++r)
					{
						if (m[x] > m[r] && m[x]!=',' && m[r]!=',')
						{
							a =  m[x];
						        m[x] = m[r];
							m[r] = a;
						}
					}
				}   
				for(int y=0;y<b-1;y++)
					fileOutput<<m[y];
		    		fileOutput<< endl;
				b=0;
        		}
    		}
}

int main(int arg,char* argc[])
{
	int n=0,length=0;
	string str;
	char a[50];
	ifstream read(argc[1]);
	ifstream fileInput(argc[1]);
	fileOutput.open(argc[2]);
	while(getline(fileInput,str,'\n'))
		length++;
	for(int s=0;s<3;s++)      
		read>>a[s];
	n=a[0]-48;
	Graph g(n);
	for(int s=0;s<(2*n-1);s++)  
	{
		read>>a[s];
	}
	int count =0;
	while(getline(read,str,'\n'))  
	{
		if(count!=length-2)
		{
			for(int i=1;i<4;i++)
			{
				read>>a[i];
			}
			int vertex1=(int)a[1]-97;
			int vertex2=(int)a[3]-97;
			g.addEdge(vertex1,vertex2);
			count++;
		}
	}
	g.printStronglyCC();
	return 0;
}
