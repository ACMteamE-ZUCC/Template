#include<iostream>
#include<algorithm>
using namespace std;
int n,ans[100];
int lowbit(int x){
	return x&(-x);
}
int update(int x,int number){
	while(x<=n){
		ans[x]+=number;
		x+=lowbit(x);
	}
	return 1;
}
int getsum(int x){
	 int sum=0;
	while(x>0){
		sum+=ans[x];
		x-=lowbit(x); 
	}
	return sum;
} 

int main(){
	int a[100];
	int t;
	cin>>t;
	while(t--){
		fill(ans,ans+100,0);
		//int n;
		cin>>n;
		int at[100];
		for(int i=1;i<=n;i++){
		    cin>>a[i];
	        at[a[i]]=i;//����������浽��һ�������еõ��������ݵ�λ��
			//��a[1]=5��at[5]=1�����Ǳ���5������ǵ�һ��������� 
	    }
	    int position,sum=0;
	    //��ؼ� ���� ����ÿһ���ǴӸߵ���ֻ�������Ż������� 
		for(int i=n;i>=1;i--){
	    	position=at[i];//�õ������ֵ����Сֵ�����ڵ�λ�ã���Ϊ����������ǰ�治�ܴ��ں���
			//���������Ҫ����Ǵ�������󣬵�������������˵���϶�����������
			//����������˵��5��Ӧ�������һ���������������ǵ�һ���������ʾ�϶�����������
			//getsum�Ǵӵ�ǰλ��һֱ�ӵ�λ��Ϊ1ʱ���Ƿ���ans[i]=1
			//update���Ǹ������ĸ��ڵ�
			cout<<getsum(position)<<endl; 
			sum+=getsum(position);
			update(position,1); 
		}
		cout<<sum<<endl;
	    
	}
} 
