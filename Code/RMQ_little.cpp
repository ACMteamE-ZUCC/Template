#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
//��RMQ��Ԥ���� 
int RMQ_init(int a[]){
	int d[100][100];
	//n������a�ĳ��� 
	for(int i=0;i<=n;i++){
	    d[i][0]=a[i];
	}//d[i][j]��ʾd[i]��Ԫ�ؿ�ʼ�����ǣ�1<<j)�ĳ��ȵ������ֵ��Сֵ
	//������Ԥ�����Ч����nlnn,��Ϊ����j��2^j<=n,i��n
    //Ȼ��ڶ���forѭ���Ǵ�0��ʼ��һ�����ƣ�i+��1<<j��-1<n��֤�˵��ƹ�ϵ����Ч�ԣ�
	//��һֱ��n�ĳ�������,����ʽ�ӷֳ�����һ����2^(j-1),��һ�߾���2^(j-1)+i	 
	for(int j=1;1<<j<=n;j++){
		for(int i=0;(i+1<<(j-1))<n;i++){
			d[i][j]=min(d[i][j-1],d[i+1<<(j-1)][j-1]);
		}
	} 
}
//O(1)
//��ѯ����l to r��������2^k<=(l-r+1),while ����ʵ��k+1==k����Ϊ�����ֳ�����������
//ȡl+2^��k-1��һ�Σ�r-2^��k-1�����ϵ�rһ��
 
int RMQ_search(int l,int r){
	int k=0;
	while(1<<(k+1)<=r-l+1)k++;
	return mid(d[l][k],d[r-1<<k+1][k])
}
int main(){
	
}
