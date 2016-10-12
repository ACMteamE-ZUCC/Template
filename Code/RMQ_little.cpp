#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
//对RMQ的预处理 
int RMQ_init(int a[]){
	int d[100][100];
	//n是数组a的长度 
	for(int i=0;i<=n;i++){
	    d[i][0]=a[i];
	}//d[i][j]表示d[i]个元素开始距离是（1<<j)的长度的数组的值最小值
	//这样的预处理的效率是nlnn,因为距离j是2^j<=n,i是n
    //然后第二个for循环是从0开始的一个地推（i+（1<<j）-1<n保证了递推关系的有效性，
	//即一直在n的长度里面,递推式子分成两半一个是2^(j-1),另一边就是2^(j-1)+i	 
	for(int j=1;1<<j<=n;j++){
		for(int i=0;(i+1<<(j-1))<n;i++){
			d[i][j]=min(d[i][j-1],d[i+1<<(j-1)][j-1]);
		}
	} 
}
//O(1)
//查询区间l to r，长度是2^k<=(l-r+1),while 中其实是k+1==k，因为把它分成两段来做的
//取l+2^（k-1）一段，r-2^（k-1）加上到r一段
 
int RMQ_search(int l,int r){
	int k=0;
	while(1<<(k+1)<=r-l+1)k++;
	return mid(d[l][k],d[r-1<<k+1][k])
}
int main(){
	
}
