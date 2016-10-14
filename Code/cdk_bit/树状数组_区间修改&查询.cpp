#include<iostream>
#include<cstring>
using namespace std;
#define N 10005
long long c1[N];//ά��delta��i����ǰ׺�� 
long long c2[N];//ά��delta[i]*i��ǰ׺��
long long sum[N];//sum[i]=A[1]+..+A[i],��¼A[i]��ǰ׺��
long long A[N];
int n;
//long long array[N];//��״���������
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
		 		//�����µ�ʱ��ֻ��Ҫ����ͨ���������
				 //�����ѯ��ʱ��ֳ����飬һ���ǻ�����һ��ʼ��������ݣ���sum[i]�洢����ǰ׺��
				 //Ȼ���������ڵ��ۻ���������delta[i]��sum[x]�Ĺ���ֵΪdelta[i]*(x+1-i)
		 		//����sum�Ǽ�����ǰ׺�ͣ���delta��һ����״���飬���Ǹ�������ʱ���Ǹ��µ����һ�����ڵ�
				 //�����ܰ�sun[x]Ӱ���delta[i]�ĸ������ǣ�x+1-i������ô�� 
				 //����� sum[x]=sum[x](����) + (x+1)*segma(delta[i]) - segma(delta[i]*i) 
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
