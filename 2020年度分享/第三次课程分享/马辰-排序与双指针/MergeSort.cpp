#include <iostream>
using namespace std;
const int maxn = 5000;
int a[maxn];
void Merge(int A[], int l1, int r1, int l2, int r2) {
	int i = l1, j = l2;//双指针，指向两个有序序列各自最小值
	int temp[maxn], index = 0;//temp为临时数组，index为其下标
	//两序列相比取小
	while (i <= r1 && j <= r2) {
		temp[index++] = (A[i] <= A[j]) ? A[i++] : A[j++];
	}
	//若已经有一个序列归并完，只需把另一序列剩余元素依次放入
	while (i <= r1/*&& j>r2*/)temp[index++] = A[i++];
	while (j <= r2/*&& i>r1*/)temp[index++] = A[j++];
	//将临时数组元素复制到原数组中
	for (int i = 0; i < index; i++) { A[l1 + i] = temp[i]; }
}
void MergeSort(int A[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;		//中点
		MergeSort(A, l, m); 		//排左
		MergeSort(A, m + 1, r);	//排右
		Merge(A, l, m, m + 1, r); //归并
	}

}
int main() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)cin >> a[i];
	MergeSort(a, 0, num-1);
	for (int i = 0; i < num; i++)cout << a[i]<< " " ;

}
