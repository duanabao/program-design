
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LoopQueue
{
public:
	LoopQueue(int c = 10);
	~LoopQueue();
	bool isEmpty();        //队列的判空
	int size();            //队列的大小
	bool push(T t);        //入队列
	bool pop();            //出队列
	T front();            //队首元素
 
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
bool LoopQueue<T>::isEmpty()                   //判断循环队列是否为空
{
	if (begin == end)
		return true;
	return false;
};
 
template<typename T>
int LoopQueue<T>::size()
{
	return (end - begin + capacity) % capacity; //计算循环队列的长度
};
 
template<typename T>
bool LoopQueue<T>::push(T t)
{
	if (end + 1 % capacity == begin)            //判断队列是否已满
	{
		return false;
	}
	queue[end] = t;
	end = (end + 1) % capacity;
	return true;
};
 
template <typename T>
bool LoopQueue<T>::pop()                        //判断队列是否为空
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
	cout << "队列长度" << queue.size() << endl;
	while (!queue.isEmpty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}
	return 0;
}

