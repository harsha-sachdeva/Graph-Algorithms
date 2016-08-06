#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
void DepthFirstSearch(int);
int adjacent[200][200],visited[200],n;
ofstream fileOutput;

void DepthFirstSearch(int i)
{
	int j;
	char c=(char)i;
	fileOutput<<c;
	visited[i]=1;
	for(j=65;j<122;j++)
        if(!visited[j]&&adjacent[i][j]==1)
        {    
		fileOutput<<",";	
		DepthFirstSearch(j);
		
	}
}

int main(int arg,char *argv[])
{	
	int length=0;
	string str;
	char arr1[50];
	ifstream read(argv[1]);
	ifstream fileInput(argv[1]);
	fileOutput.open(argv[2]);
	while(getline(fileInput,str,'\n'))
		length++;
	for(int s=0;s<3;s++)      
		read>>arr1[s];
	n=arr1[0]-48;
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<200;j++)
		{
			adjacent[i][j]=0;
		}
	}
	for(int s=0;s<(2*n-1);s++) 
	{
	 	read>>arr1[s];
	}
	int p1=arr1[0];
	int count =0;
	while(getline(read,str,'\n'))  
	{
	     if(count!=length-2)
	     {
			for(int i=0;i<3;i++)
			{
				read>>arr1[i];
			}
			int p=arr1[0];
			int q=arr1[2];			
			adjacent[p][q]=1;	
			adjacent[q][p]=1;
			count++;
	      }
	}
	for(int i=65;i<122;i++)
	        visited[i]=0;
	DepthFirstSearch(p1);
	return 0;
}
