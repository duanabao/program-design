#include<iostream>
#include<string.h>
using namespace std;
//1-100
int prime[101];
int n=0;
int q[101]={0};
void find()
{
	for(int i=2;i<101;i++)
	{
		if(q[i]==0)
		prime[n++]=i;
		for(int j=i+i;j<101;j+=i)
		q[j]=-1;
	}
	
}
