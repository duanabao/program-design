#include<iostream>
#include<string.h>
using namespace std;

//�������Ĵ洢-----
struct bign
{
	int d[1000];//������ֵ�
	int length;//��¼����
	bign()//��ʼ������ 
	{
		length=0;
		memset(d,0,sizeof(d));
	} 
};

//�������ַ���ת��Ϊ���� 
bign change(char str[])
{
	bign c;
	c.length=strlen(str);
	for(int i=0;i<c.length;i++)
	{
		c.d[i]=str[c.length-i]-'0';
	}
	return c; 
}

//�Ƚ����ִ�С
bool compare(bign a,bign b)
{
	if(a.length >b.length)return true;
	if(a.length<b.length)return false;
	if(a.length==b.length)
	{
		for(int i=a.length-1;i>=0;i--)
		{
			if(a.d[i]>b.d[i])
			return true;
			
		}
		return true;
	}
} 

//�����������
bign sub(bign a,bign b)//a>b 
{
  bign c;
  for(int i=0;i<a.length||i<b.length;i++)
  {
  	if(a.d[i]<b.d[i])
  	{
  		a.d[i++]-=1;
  		a.d[i]+=10;
	}
	c.d[c.length++]=a.d[i]-b.d[i];
  }
  //0078
  while(c.d[c.length-1]==0&&c.length-1>1)
  c.length--;
  return c;
} 
//������ 
int main()
{
	
	
	return 0;
}

