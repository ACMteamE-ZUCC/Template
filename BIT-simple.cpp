/*
	Author:	YoT
	Date:	2016/07/29 @ 15:42
	处理：	需要bit_init();使得树状数组初始化.
			给定const int BIT_MAX 和 typedef BIT_c;
	1、log(n)插入单个点，log(n)统计前缀和。
	2、log(n)插入一个线段，log(n)统计单个点
		定义线段[l,r] add(l,1); add(r+1,-1);
*/
//BIT-Template Begin
typedef int BIT_c;
const int BIT_MAX=10000;
BIT_c BIT[BIT_MAX];
inline int lowbit(const int &n){
	return n&(-n);
}
inline int op_upper(const int &n){
	return n+lowbit(n);
}
inline int op_lower(const int &n){
	return n-lowbit(n);
}
int bit_add(int ith,BIT_c dlt){
	while(ith<=BIT_MAX){
		BIT[ith]+=dlt;
		ith=op_upper(ith);
	}
	return 0;
}
BIT_c bit_sum(int ith){
	BIT_c ans=0;
	while(ith>0){
		ans+=BIT[ith];
		ith=op_lower(ith);
	}
	return ans;
}
int bit_init(){
	memset(BIT,0,sizeof(BIT));
	return 0;
}
//BIT-Template End
