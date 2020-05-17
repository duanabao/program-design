#include <iostream>
using namespace std;
const int maxn = 5000;
int a[maxn];
//随机选取主元并划分
int Patrtition(int A[], int l, int r) {
	//随机位置生成
	int p = round(1.0 * rand() / RAND_MAX * (r - l) + l);
	//随机位置与首位置交换 达到随机选取主元
	swap(A[p], A[l]);
	int temp = A[l];

	while (l < r)//两根指针没有相遇，说明未划分完成
	{
		while (l<r && A[r]>temp)r--;//未找到应交换元素前，左移右侧的指针
		A[l] = A[r];				//将A[l】挪入另一侧“空位”中
		while (l < r && A[l] <= temp)l++;
		A[r] = A[l];
	}
	A[r] = temp;					//将最开始选的主元放入最后一个形成的空位，完成划分
	return l;//返回双指针相遇位置
}
void QuickSort(int A[], int l, int r) {
	if (l < r)	//若当前区间不为1或空 递归执行排序
	{
		int pos = Patrtition(A, l, r);//划分并返回划分后轴点位置
		QuickSort(A, l, pos - 1);//左子区间递归快排
		QuickSort(A, pos+1, r);//右子区间递归快排
	}
}
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)cin >> a[i];
	QuickSort(a, 0, num - 1);
	for (int i = 0; i < num; i++)cout << a[i] << " ";

}
