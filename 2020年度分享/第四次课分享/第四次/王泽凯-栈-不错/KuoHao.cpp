#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool func(string s)
{
	char temp;
	stack<char>st;			//建立栈
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);			//如果是左括号，压入栈内
		else
		{
			if (st.empty())
				return false;	//栈为空说明无左括号了，输出错误
			temp = st.top();			//用temp记录弹出的符号
			st.pop();					//用弹出最顶部符号
			switch (s[i]) {				//根据输入的右符号判断是否符合书写规范
			case ')':
			{
				if (temp != '(')
				{
					return false;                 //如果右符号与其左侧符号不对应，输出错误
				}
				else
					break;
			}
			case '}':
			{
				if (temp != '{')
				{
					return false;
				}
				else
					break;
			}
			case ']':
			{
				if (temp != '[')
				{
					return false;
				}
				else
					break;
			}
			default:
				return false;
			}
		}
	}
	if (!st.empty()) return false;   //最后如果栈非空，说明没有两两对应，输出错误

}

int main()
{
	string s;
	cin >> s;            //输入字符串
	if (func(s))			//函数判断
		cout << "ture" << endl;
	else
		cout << "false" << endl;
	return 0;
}