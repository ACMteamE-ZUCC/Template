#include<iostream>
using namespace std;
long long fast_cal(long long a,long long b,long long mod){
	long long ans=0;//���ٳ˴�0��ʼ
	while(b){
		if(b&1){//b%2==1Ҳ��һ���ı�ʾ��ǰλΪ1���Ӷ����Ƶ�չ������
		ans=(ans+a)%mod;
		b--; 
		}
		a=(a+a)%mod;
		b/=2;
	} 
	return ans;
}//�����ݾ��ǰ�if�е�b--ȥ����a*=amod��ans*=a��ans��ʼΪ1 
long long qucimod_(long long a,long long b,long long n){
 	long long ret=1;
 	long long t=a;
 	while(b){
 		if(b%2==1)ret=ret*t%n;//������ż�����ᵽ��һ����Ȼ��ret�������ֵ 
 		t=t*t%n;
 		b/=2;
 	}
 }
int main(){
	int t;
	cin>>t;
	while(t--){
		
	}
} 
