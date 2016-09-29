#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
TODO const int MAX_VECTOR = 210;
const int MAX = 1<<26;
struct Edge{
    int from,to,c;
    int next;
}edges[20*MAX_VECTOR];
int n,m;
int edge_num;//边数
int parent[MAX_VECTOR];//父亲
int d[MAX_VECTOR];
int source_point,sink_point;//原点，汇点

void add_edge(int from, int to, int c)
{
    edges[edge_num].from=from; edges[edge_num].to=to; edges[edge_num].c=c;
    edges[edge_num].next=parent[from]; parent[from]=edge_num++;

    edges[edge_num].from=to; edges[edge_num].to=from; edges[edge_num].c=0;
    edges[edge_num].next=parent[to]; parent[to]=edge_num++;
}
int bfs()
{
    queue <int> q;
    memset(d,-1,sizeof(d));
    d[source_point]=0;
    q.push(source_point);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(int i=parent[cur];i!=-1;i=edges[i].next)
        {
            int u=edges[i].to;
            if(d[u]==-1 && edges[i].c>0)
            {
                d[u]=d[cur]+1;
                q.push(u);
            }
        }
    }
    return d[sink_point] != -1;
}
int dfs(int a,int b)
{
    int r=0;
    if(a==sink_point)return b;
    for(int i=parent[a];i!=-1 && r<b;i=edges[i].next)
    {
        int u=edges[i].to;
        if(edges[i].c>0 && d[u]==d[a]+1)
        {
            int x=min(edges[i].c,b-r);
            x=dfs(u,x);
            r+=x;
            edges[i].c-=x;
            edges[i^1].c+=x;
        }
    }
    if(!r)d[a]=-2;
    return r;
}

int dinic(int sp,int tp)
{
    int total=0,t;
    while(bfs())
    {
        while(t=dfs(sp,MAX))
            total+=t;
    }
    return total;
}
int init(){
    edge_num=0;//初始化
    memset(parent,-1,sizeof(parent));
    source_point=1;sink_point=n;
}
int main()
{
    int i,u,v,c;
    while(~scanf("%d%d",&m,&n))
    {
        init();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            add_edge(u, v, c);
        }
        printf("%d\n",dinic(source_point,sink_point));
    }
    return 0;
}