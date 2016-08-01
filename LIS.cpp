const int MAX_N=10000;
const int INF=0x7f7f7f7f;
int a[MAX_N];
int s[MAX_N];//s[i]记录长度为i的子序列的最小a[i]
int d[MAX_N];//原串第i项结尾的最长子序列长，ans为d[i].max();

int LIS(){//最长不下降子序列
//(upper_bound()返回数组中大于等于的上界）
	memset(s,INF,sizeof(s));
	int ans=0;
	for(int i=0;i<n;i++){
		int &t=a[i];
		int pos=upper_bound(s,s+n,t)-s;
		d[i]=max(pos,1);
		s[d[i]]=min(s[d[i]],t);
		ans=max(ans,d[i]);
	}
	return ans;
}
