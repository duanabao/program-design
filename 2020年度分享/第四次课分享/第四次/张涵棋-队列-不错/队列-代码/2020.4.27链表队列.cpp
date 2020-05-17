#include <iostream>
#include <cstdlib>
using namespace std;
//ͷ��㣨�����ݣ�-��һ�����-β��� 
struct QNode    //������н������ݽṹ
{
	QNode *next; //ָ����,ָ����һ�����
	double data;    //�����򣬴洢������Ϣ
};
 
struct LinkQueue    //������е����ݽṹ
{
	QNode *front;      //����ָ��,ָ���һ������ǰһ����� 
	QNode *rear;       //��βָ�룬ָ��β��� 
};
 
void InitQueue(LinkQueue &Q)     //����һ���յĶ���
{
	QNode *q;
	q = new QNode;    //����һ�����Ŀռ�
	q->next = NULL;   //����ͷ���
	//�������βָ�붼ָ�������㣬ָ����ΪNULL
	Q.front = q;
	Q.rear = q;
}
 
int IsEmpty(LinkQueue &Q)    //�ж϶����Ƿ�Ϊ��
{
	if (Q.rear == Q.front)
		return 0;
	else
		return 1;
}
 
void EnQueue(LinkQueue &Q, double e)     //�Ӷ���β������Ԫ��
{
	QNode *p;    //�´���һ�����
	p = new QNode;
	p->next = NULL;
	p->data = e;  //����������Ϣ
	//���½��������β��
	Q.rear->next = p;
	Q.rear = p;       //�����µ�β���.
}
 
void DeQueue(LinkQueue &Q, double &e)   //���ʵ�һ����㣬��ɾ���� 
{
	QNode *p;
	p = Q.front->next;//frontָ����ǵ�һ������ǰһ��λ�á����ԣ����д�����pָ���һ����㡣 
	e = p->data;  //�����һ����������
	if (Q.rear == p) //���Ҫɾ����Ԫ�ؼ�Ϊβ��㣬��ͷָ�븳��βָ�룬һָͬ��ͷ��㣬��ʾ����Ϊ��
		Q.rear = Q.front;
	Q.front->next = p->next;//���ڶ�����㵱���µĵ�һ�����
	delete p;
}
 
void DestoryQueue(LinkQueue &Q)       //����һ������
{
	while (!IsEmpty(Q))
	{
		double value;
		DeQueue(Q,value);
	}
}
int main()
{
	LinkQueue *Q;  //����һ������Q
	Q = new LinkQueue;
	InitQueue(*Q);
	cout << "��ʼ���������������ݣ���-1��Ϊ������" << endl;
	cout << "������һ������" << endl;
	double a, x;
	cin >> a;
	while (a != -1)
	{
		EnQueue(*Q, a);
		cout << "������һ������" << endl;
		cin >> a;
	}
	//�������Ԫ��,����->��β
	QNode *p;
	p = Q->front->next;
	if (p == NULL)     //���Ϊ�ձ�ֱ���˳�
	{
		cout << "����Ϊ�գ�" << endl;
		return 0;
	}
	cout << "������������Ϊ��" << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	//ɾ������Ԫ��
	while (!IsEmpty(*Q))
	{
		DeQueue(*Q, x);
		cout << x << " ";
	}
	//�ͷ��ڴ�ռ�
	delete Q->front;
	delete Q;
	system("pause");
	return 0;
}

