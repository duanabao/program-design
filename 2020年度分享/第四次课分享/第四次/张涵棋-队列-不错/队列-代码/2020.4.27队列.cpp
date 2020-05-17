#include <iostream>
#include <queue>
using namespace std;
int main(){
queue<int> q1;
    for(int i=0;i<5;i++){
    	q1.push(i);
    	cout<<"push:"<<i<<endl;
    }
       
    cout<<"----size:"<<q1.size()<<endl;
    
    while(!q1.empty()){ 
    	cout<<"front:"<<q1.front()<<",back:"<<q1.back()<<endl; 
   		q1.pop();} 

return 0;} 
