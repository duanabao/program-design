#include<iostream>
using namespace std;
void Hanoi(int,char,char,char);
int main()
{
    int n;
    cin>>n;
    Hanoi(n,'A','B','C');
    return 0;
}
void Hanoi(int n,char start_pos,char trans_pos,char end_pos){//
    if (n==1) 
        cout<<start_pos<<"->"<<end_pos<<endl;//递归边界
    else {
        Hanoi(n-1,start_pos,end_pos,trans_pos);//1
        cout<<start_pos<<"->"<<end_pos<<endl;//2
        Hanoi(n-1,trans_pos,start_pos,end_pos);//3
    }    
}

