#include <iostream>
using namespace std;
const int maxn = 5000;
int a[maxn];
//���ѡȡ��Ԫ������
int Patrtition(int A[], int l, int r) {
	//���λ������
	int p = round(1.0 * rand() / RAND_MAX * (r - l) + l);
	//���λ������λ�ý��� �ﵽ���ѡȡ��Ԫ
	swap(A[p], A[l]);
	int temp = A[l];

	while (l < r)//����ָ��û��������˵��δ�������
	{
		while (l<r && A[r]>temp)r--;//δ�ҵ�Ӧ����Ԫ��ǰ�������Ҳ��ָ��
		A[l] = A[r];				//��A[l��Ų����һ�ࡰ��λ����
		while (l < r && A[l] <= temp)l++;
		A[r] = A[l];
	}
	A[r] = temp;					//���ʼѡ����Ԫ�������һ���γɵĿ�λ����ɻ���
	return l;//����˫ָ������λ��
}
void QuickSort(int A[], int l, int r) {
	if (l < r)	//����ǰ���䲻Ϊ1��� �ݹ�ִ������
	{
		int pos = Patrtition(A, l, r);//���ֲ����ػ��ֺ����λ��
		QuickSort(A, l, pos - 1);//��������ݹ����
		QuickSort(A, pos+1, r);//��������ݹ����
	}
}
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)cin >> a[i];
	QuickSort(a, 0, num - 1);
	for (int i = 0; i < num; i++)cout << a[i] << " ";

}
