#include <iostream>
#include <cstdlib>
using namespace std;
//头结点（无数据）-第一个结点-尾结点 
struct QNode    //定义队列结点的数据结构
{
	QNode *next; //指针域,指向下一个结点
	double data;    //数据域，存储队列信息
};
 
struct LinkQueue    //定义队列的数据结构
{
	QNode *front;      //队首指针,指向第一个结点的前一个结点 
	QNode *rear;       //队尾指针，指向尾结点 
};
 
void InitQueue(LinkQueue &Q)     //构造一个空的队列
{
	QNode *q;
	q = new QNode;    //申请一个结点的空间
	q->next = NULL;   //当作头结点
	//队首与队尾指针都指向这个结点，指针域为NULL
	Q.front = q;
	Q.rear = q;
}
 
int IsEmpty(LinkQueue &Q)    //判断队列是否为空
{
	if (Q.rear == Q.front)
		return 0;
	else
		return 1;
}
 
void EnQueue(LinkQueue &Q, double e)     //从队列尾部插入元素
{
	QNode *p;    //新创建一个结点
	p = new QNode;
	p->next = NULL;
	p->data = e;  //输入数据信息
	//将新结点插入队列尾部
	Q.rear->next = p;
	Q.rear = p;       //设置新的尾结点.
}
 
void DeQueue(LinkQueue &Q, double &e)   //访问第一个结点，并删除它 
{
	QNode *p;
	p = Q.front->next;//front指向的是第一个结点的前一个位置。所以，这行代码让p指向第一个结点。 
	e = p->data;  //保存第一个结点的数据
	if (Q.rear == p) //如果要删除的元素即为尾结点，则将头指针赋予尾指针，一同指向头结点，表示队列为空
		Q.rear = Q.front;
	Q.front->next = p->next;//将第二个结点当作新的第一个结点
	delete p;
}
 
void DestoryQueue(LinkQueue &Q)       //销毁一个队列
{
	while (!IsEmpty(Q))
	{
		double value;
		DeQueue(Q,value);
	}
}
int main()
{
	LinkQueue *Q;  //定义一个队列Q
	Q = new LinkQueue;
	InitQueue(*Q);
	cout << "开始往队列里输入数据，以-1作为结束符" << endl;
	cout << "请输入一个数：" << endl;
	double a, x;
	cin >> a;
	while (a != -1)
	{
		EnQueue(*Q, a);
		cout << "请输入一个数：" << endl;
		cin >> a;
	}
	//输出队列元素,队首->队尾
	QNode *p;
	p = Q->front->next;
	if (p == NULL)     //如果为空表，直接退出
	{
		cout << "队列为空！" << endl;
		return 0;
	}
	cout << "队列数据依次为：" << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	//删除队列元素
	while (!IsEmpty(*Q))
	{
		DeQueue(*Q, x);
		cout << x << " ";
	}
	//释放内存空间
	delete Q->front;
	delete Q;
	system("pause");
	return 0;
}

