#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool func(string s)
{
	char temp;
	stack<char>st;			//����ջ
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);			//����������ţ�ѹ��ջ��
		else
		{
			if (st.empty())
				return false;	//ջΪ��˵�����������ˣ��������
			temp = st.top();			//��temp��¼�����ķ���
			st.pop();					//�õ����������
			switch (s[i]) {				//����������ҷ����ж��Ƿ������д�淶
			case ')':
			{
				if (temp != '(')
				{
					return false;                 //����ҷ������������Ų���Ӧ���������
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
	if (!st.empty()) return false;   //������ջ�ǿգ�˵��û��������Ӧ���������

}

int main()
{
	string s;
	cin >> s;            //�����ַ���
	if (func(s))			//�����ж�
		cout << "ture" << endl;
	else
		cout << "false" << endl;
	return 0;
}