#include<iostream>
using namespace std;
int tailfact(int,int ans=1);
int main()
{
    int n;
    cin>>n;
    cout<<tailfact(n);
    return 0;
}
int tailfact(int n,int ans)
{
    if (n==1)
        return ans;
    else 
        return tailfact(n-1,ans*n);
}