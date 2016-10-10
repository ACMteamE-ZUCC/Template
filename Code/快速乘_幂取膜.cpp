#include<iostream>
using namespace std;
long long fast_cal(long long a,long long b,long long mod){
	long long ans=0;//快速乘从0开始
	while(b){
		if(b&1){//b%2==1也是一样的表示当前位为1，从二进制的展开来看
		ans=(ans+a)%mod;
		b--; 
		}
		a=(a+a)%mod;
		b/=2;
	} 
	return ans;
}//快速幂就是把if中的b--去掉，a*=amod；ans*=a，ans初始为1 
long long qucimod_(long long a,long long b,long long n){
 	long long ret=1;
 	long long t=a;
 	while(b){
 		if(b%2==1)ret=ret*t%n;//无论奇偶数都会到这一步，然后ret存的最后的值 
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
