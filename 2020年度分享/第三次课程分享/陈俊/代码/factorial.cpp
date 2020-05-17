#include<iostream>
using namespace std;
int fact(int);
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}
int fact(int n){//阶乘函数
    if (n == 1) 
        return 1;
    else if (n > 1)
        return n*fact(n-1);
}
