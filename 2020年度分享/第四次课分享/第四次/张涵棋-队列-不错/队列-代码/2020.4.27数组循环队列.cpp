
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LoopQueue
{
public:
	LoopQueue(int c = 10);
	~LoopQueue();
	bool isEmpty();        //���е��п�
	int size();            //���еĴ�С
	bool push(T t);        //�����
	bool pop();            //������
	T front();            //����Ԫ��
 
private:
	int capacity;
	int begin;
	int end;
	T*  queue;
};
 
 
template<typename T>
LoopQueue<T>::LoopQueue(int c)
	:capacity(c), begin(0), end(0), queue(NULL)
{
	queue = new T[capacity];
};
 
template<typename T>
LoopQueue<T>::~LoopQueue()
{
	delete[]queue;
}
 
template <typename T>
bool LoopQueue<T>::isEmpty()                   //�ж�ѭ�������Ƿ�Ϊ��
{
	if (begin == end)
		return true;
	return false;
};
 
template<typename T>
int LoopQueue<T>::size()
{
	return (end - begin + capacity) % capacity; //����ѭ�����еĳ���
};
 
template<typename T>
bool LoopQueue<T>::push(T t)
{
	if (end + 1 % capacity == begin)            //�ж϶����Ƿ�����
	{
		return false;
	}
	queue[end] = t;
	end = (end + 1) % capacity;
	return true;
};
 
template <typename T>
bool LoopQueue<T>::pop()                        //�ж϶����Ƿ�Ϊ��
{
	if (end == begin) 
	{
		return false;
	}
	begin = (begin + 1) % capacity;
	return true;
};
 
template <typename T>
T LoopQueue<T>::front()
{
	if (end == begin)
	{
		return false;
	}
	return queue[begin];
};
 
int main()
{
	LoopQueue<string> queue(6);
	queue.push("one");
	queue.push("two");
	queue.push("three");
	queue.push("four");
	queue.push("five");
	cout << "���г���" << queue.size() << endl;
	while (!queue.isEmpty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}
	return 0;
}

