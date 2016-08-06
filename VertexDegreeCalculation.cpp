#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc,char* argv[])
{
	string str;
	int n=0,length=0,s=0;
	char arr1[500];
	ifstream fileInput(argv[1]);
	ifstream read(argv[1]);
	ifstream in (argv[1]);
	ofstream fileOutput(argv[2]);
	while(getline(fileInput,str,'\n'))
		length++;

	fileInput.close();
	for(s=0;s<3;s++)
		read>>arr1[s];
	n=arr1[0]-48;
	int adjacent[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			adjacent[i][j]=0;
		}
	}
	char vertex[2*n];
	int t=0;
	for(s=0;s<(2*n-1);s++)
	{
	 	read>>arr1[s];
		vertex[t]=arr1[s];	
		t++;
	}			
	read.close();	
	int count=0;
	while (getline(in, str, '\n'))
	{
			if(count>0 && count<length-1)
			{

				for(s=0;s<3;s++)
				{
					in>>arr1[s];
				}
				int p=(int)arr1[0]-97;
				int q=(int)arr1[2]-97;
				adjacent[p][q]=1;	
				adjacent[q][p]=1;
				
				count++;
			}
			else
			count++;

	}

	in.close();
	int y=0;

	for(int i=0;i<n;i++)
	{
		int temp=0;
		fileOutput<<vertex[y]<<" ";
		for(int j=0;j<n;j++)
		{
			temp=temp+adjacent[i][j];
		}
		y=y+2;
		fileOutput<<temp<<"\n";
	}
}
