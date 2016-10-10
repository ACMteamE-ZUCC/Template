#include<iostream>
#include<cstring>
using namespace std;
struct edge{
	int to;
    int next;
};
int head[1005],count=0,sg[10005];
edge e[1005];
void init(){
	memset(head,-1,sizeof(head));
	count=0;
	memset(sg,-1,sizeof(sg));
}
void add_edge(int from,int to){
	e[count].to=to;
	e[count].next=head[from];
	head[from]=count++;
} 
int getsg(int n){
	int visit[10005];
	memset(visit,0,sizeof(visit));
	//n所用有的石子数 
	if(sg[n]!=-1)return sg[n];
	int k;
	for(int i=head[n];i!=-1;i=e[i].next){//size_method是method数组的大小 
		k=e[i].to;
		if(sg[k]==-1){//第一个大于method的就进行递归 
		   // hash[sg]
		   sg[k]=getsg(k); 
	    }   
		   visit[sg[k]]=1;//采用递归，这里无hash数组采用visit 
	}
	for(int i=0;;i++){
		//visit类似hash,mex{}的作用，取第一个最小的visit[]为0的值就是sg 
		if(!visit[i]){
				sg[n]=i;
			break;
		}
	}
	return sg[n];
} 
int main(){
	int t;
	while(cin>>t){
		init();
		int n,to;
		for(int i=0;i<t;i++){
			cin>>n;
			for(int j=1;j<=n;j++){
				cin>>to;
				add_edge(i,to);
			} 
		}
		int query,a;
		while(cin>>query&&query){
			int ans=0;
			for(int i=1;i<=query;i++){
				cin>>a;
				ans^=getsg(a);
			}
			if(ans)cout<<"WIN\n";
			else cout<<"LOSE\n";
		}
		 
	} 
}
