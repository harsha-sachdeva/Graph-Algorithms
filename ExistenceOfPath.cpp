#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc,char* argv[])
{
	string str;
	int n=0,length=0,s=0;
	char arr1[500];
	ifstream iff(argv[1]);
	ifstream read(argv[1]);
	ifstream fileInput (argv[1]);
	ofstream fileOutput(argv[2]);
	while(getline(iff,str,'\n'))
		length++;
	iff.close();
	for(s=0;s<3;s++)
		read>>arr1[s];
	n=arr1[0]-48;
	int adjacent[n][n];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			adjacent[i][j]=0;
		}
	}
	int p[30],j=0;
	int count=0;
	while (getline(fileInput, str, '\n'))
	{
		if(count>0 && count<length-2)
		{
			for(s=0;s<3;s++)
			{
				fileInput>>arr1[s];
			}
			int p=(int)arr1[0]-48;
			int q=(int)arr1[2]-48;				
			adjacent[p][q]=1;	
			count++;
		}
		else if(count==(length-2))
		{
			cout<<str.length();
			for(s=0;s<5;s++)
			{
				fileInput>>arr1[s];
			}
			j=0;
			for(int i=0;i<5;i=i+2)
			{
				p[j]=(int)arr1[i]-48;
				j++;
			}
		}			
		else
			count++;
	}
	fileInput.close();
	int flag=0;
	for(int i=0;i<2;i++)
	{
		int b=p[i];
		int x=p[i+1];
		flag=0;
		if(adjacent[b][x]==1)
		{
			flag=1;
		}
		if(flag==0)
		{
			break;
		}
	}
	if(flag==0)
		fileOutput<<"0";
	else
		fileOutput<<"1";
}
