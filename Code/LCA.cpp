#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define max 10010
#define MAX 2000005
//creat a maxrtix only one drgee
int head[max];//to act the vertix in martix
int deep[max],dis[max],father[max],visit[max];
int ans[MAX];//common ancestor 
int query_count=0,query_h[max],ver=0;
int init(){
	memset(head,-1,sizeof(head));
	memset(query_h,-1,sizeof(query_h));
	query_count=0;
	ver=0;
}
struct Node{
	int v,weight,next;
}edge[2*max];
//head[] has record the index of every elemt edeg[ver].v,head[]==ver
int addinedge(int a,int b,int c){
	  edge[ver].v=b;//v first
	  edge[ver].next=head[a];
	  edge[ver].weight=c;
	  head[a]=ver++;
	  return 0;
}
struct Query{
	int v,index,next;
}q[MAX];

void addinques(int a,int b,int index){
	q[query_count].v=b;
	q[query_count].index=index;
	q[query_count].next=query_h[a];
	query_h[a]=query_count++;
}
//beacuse of this question is not just a tree but also a senlin
//use bing chaji
int find(int x){
	int r=x;
	while(r!=father[r]){
		r=father[r];
	}
	return r;
}
void TarjanLCA(int k,int deep,int root){
	int v;
	father[k]=k;
	visit[k]=root;
	dis[k]=deep;//to record the answer
	for(int i=head[k];i!=-1;i=edge[i].next){
		v=edge[i].v;//edge[i].v store the ith vertex which is connect with it
		if(visit[1)continue;//if find  a vertex doesnnot visit,then lca
		TarjanLCA(v,deep+edge[i].weight,root);
		father[v]=k;//递归完所有子树后全部链到k(形参)上，如5==edge[2].v,现在father[5]=2，回溯; 
		}
	for(int i=query_h[k];i!=-1;i=q[i].next){
		v=q[i].v;
		if(visit[v]!=root)continue;//都属于同一个祖先的儿子才有资格 
		ans[q[i].index]=dis[v]+dis[k]-2*dis[find(v)];
		//最近的距离就是两个点到他公共祖先的点距离 
	}
 		

}
//n<=1w m<=1w c<=100w
int main(){
     int n,m,t;
	while(scanf("%d%d%d",&n,&m,&t)==3){
	 	int a,b,c;
	 	init();//to reset all elements
	while(m--){
	 		scanf("%d%d%d",&a,&b,&c);
	 		addinedge(a,b,c);
	 		addinedge(b,a,c);
		 }
		 
    for(int i=0;i<t;i++){
		 scanf("%d%d",&a,&b);
		 ans[i]=-1;
		 addinques(a,b,i);
		 addinques(b,a,i);
	}
		memset(visit,-1,sizeof(visit));
	for(int i=1;i<=n;i++)    
		if(visit[i]==-1) {
		TarjanLCA(i,0,i);  
        }
		for(int i=0;i<t;i++)  
        {  
            if(ans[i]==-1)  
			printf("Not connected\n");  
            else    
			printf("%d\n",ans[i]);  
        }  
    }  
    return 0;  
	 }	
 
