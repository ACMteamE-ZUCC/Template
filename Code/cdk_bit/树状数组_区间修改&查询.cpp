#include<iostream>
#include<cstring>
using namespace std;
#define N 10005
long long c1[N];//维护delta【i】的前缀和 
long long c2[N];//维护delta[i]*i的前缀和
long long sum[N];//sum[i]=A[1]+..+A[i],记录A[i]的前缀和
long long A[N];
int n;
//long long array[N];//树状数组的引用
int lowbit(int x){
	return x&-x;
}
long long update (long long * array,int i,long long d){
	while(i<=n){
		array[i]+=d;
		i+=lowbit(i); 
	}
} 
long long get_sum(long long *array,int i){
	long long sum_;
	sum_=0;
	while(i>0){
		sum_+=array[i];
		i-=lowbit(i);
	}
	return sum_;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		char operation;
		int s,t;
		long long array[N];
		memset(array,0,sizeof(array));
		int query_times;
		cin>>n>>query_times;
		for(int i=1;i<=n;i++){
			cin>>A[i];
		}
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+A[i]; 
		}
		 while(query_times){
		 	getchar();
		 	cin>>operation>>s>>t;
		 	if(operation=='Q'){
		 		int ans=sum[t]-sum[s-1];
		 		//做更新的时候只需要像普通的区间更新
				 //这里查询的时候分成两块，一块是基数，一开始输入的数据，用sum[i]存储他的前缀和
				 //然后是区间内的累积增加量且delta[i]对sum[x]的贡献值为delta[i]*(x+1-i)
		 		//由于sum是记入了前缀和，而delta是一个树状数组，我们更新他的时候是更新到最后一个父节点
				 //所以能把sun[x]影响的delta[i]的个数就是（x+1-i）个这么多 
				 //化简后 sum[x]=sum[x](基数) + (x+1)*segma(delta[i]) - segma(delta[i]*i) 
				 ans+=(t+1)*get_sum(c1,t)-get_sum(c2,t);
			    ans-=(s)*get_sum(c1,s)-get_sum(c2,s);
			    cout<<ans;
			 }
			 else {
			 	int need_add;
			 	cin>>need_add;
			 	update(c1,s,need_add);
			 	update(c1,t+1,-need_add);
			 	update(c2,s,need_add*s);
			 	update(c2,t+1,-need_add*s);
			 }
		 }
	} 
} 
