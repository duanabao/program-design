#include<iostream>
#include<cmath>
using namespace std;
void Nqueen(int);
int N;
int count=0;//用于计算排法总数
int queenPos[100];//用于存放皇后所放位置
int main()
{
    cin>>N;
    Nqueen(1);//从第1行开始摆
    cout<<count;
    return 0;
}
void Nqueen(int k){//1~k-1行已摆好，现摆第k行
    int i=0;
    if (k==N+1) {
        count++;
        return;
    }//递归边界
    for (i=1;i<N+1;i++){//遍历第k行皇后可能放的所有位置
        int j;
        bool flag=true;
        if (k==1) {
            queenPos[k-1]=i;
            Nqueen(k+1);
        }//k==1的特殊情况另外讨论
        else {
            for (j=1;j<k;j++){
                if (abs(queenPos[j-1]-i)==abs(k-j)||queenPos[j-1]==i){
                    flag=false;//和前k-1行有冲突
                    break;
                }
            }
            if (flag==true){//和前k-1行无冲突
                queenPos[k-1]=i;
                Nqueen(k+1);//继续摆放第k+1行    
            }        
        }
    }    
}
