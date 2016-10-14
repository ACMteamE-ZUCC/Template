#include<iostream>
using namespace std;
int lowbit(int x){
	return x&-x;
}
void update(int x,int y){
      for(int i=x;i<=n;lowbit(i)){
      	for(int j=y;j<=n;lowbit(j)){
      		c[i][j]+=d;
		  }
	  }

}
long long get_sum(int x,int y){
	long long res=0;
    for(int i=x;i>0;i-=lowbit(i)){
    	for(int j=y;j>=0;j-=lowbit(j)){
    		res+=c[i][j];
		}
	}
	return res;
}
int main(){
	
}
