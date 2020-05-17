#include <iostream>
using namespace std;
const int maxn = 5000;
int a[maxn];
void Merge(int A[], int l1, int r1, int l2, int r2) {
	int i = l1, j = l2;//˫ָ�룬ָ�������������и�����Сֵ
	int temp[maxn], index = 0;//tempΪ��ʱ���飬indexΪ���±�
	//���������ȡС
	while (i <= r1 && j <= r2) {
		temp[index++] = (A[i] <= A[j]) ? A[i++] : A[j++];
	}
	//���Ѿ���һ�����й鲢�ֻ꣬�����һ����ʣ��Ԫ�����η���
	while (i <= r1/*&& j>r2*/)temp[index++] = A[i++];
	while (j <= r2/*&& i>r1*/)temp[index++] = A[j++];
	//����ʱ����Ԫ�ظ��Ƶ�ԭ������
	for (int i = 0; i < index; i++) { A[l1 + i] = temp[i]; }
}
void MergeSort(int A[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;		//�е�
		MergeSort(A, l, m); 		//����
		MergeSort(A, m + 1, r);	//����
		Merge(A, l, m, m + 1, r); //�鲢
	}

}
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)cin >> a[i];
	MergeSort(a, 0, num-1);
	for (int i = 0; i < num; i++)cout << a[i]<< " " ;

}
