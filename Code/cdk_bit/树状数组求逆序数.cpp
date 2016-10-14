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
	        at[a[i]]=i;//把输入的数存到另一个数组中得到输入数据的位置
			//如a[1]=5，at[5]=1，就是表明5这个数是第一个输进来的 
	    }
	    int position,sum=0;
	    //最关键 的是 他的每一次是从高到低只有这样才会有逆序 
		for(int i=n;i>=1;i--){
	    	position=at[i];//得到从最大值到最小值他所在的位置，因为求逆序数是前面不能大于后面
			//按道理符合要求的是大数在最后，但是如果不在最后说明肯定存在逆序数
			//根据上面所说，5本应该是最后一个数，但是现在是第一个输进来表示肯定存在逆序数
			//getsum是从当前位置一直加到位置为1时看是否有ans[i]=1
			//update就是更新他的父节点
			cout<<getsum(position)<<endl; 
			sum+=getsum(position);
			update(position,1); 
		}
		cout<<sum<<endl;
	    
	}
} 
