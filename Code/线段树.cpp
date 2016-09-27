//单点替换、单点增减、区间求和、区间最值
#include <cstdio>
#include <algorithm>
using namespace std;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 222222;

int MAX[maxn<<2];
int MIN[maxn<<2];
int SUM[maxn<<2];
int max(int a,int b){if(a>b)return a;else return b;}
int min(int a,int b){if(a<b)return a;else return b;}

void PushUP(int rt)
{
  MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
  MIN[rt] = min(MIN[rt<<1] , MIN[rt<<1|1]);
  SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];
}

void build(int l,int r,int rt) {
  if (l == r)
    {
    scanf("%d",&MAX[rt]);
    MIN[rt] = MAX[rt];
    SUM[rt] = MAX[rt];
    //printf("mi = %d\n",MIN[rt]);
  //    printf("ma = %d\n",MAX[rt]);
    return ;
  }
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
  PushUP(rt);
}

void update(int p,int tihuan,int l,int r,int rt)
{
  if (l == r) {
    MAX[rt] = tihuan;
    MIN[rt] = tihuan;
    SUM[rt] = tihuan;
    return ;
  }
  int m = (l + r) >> 1;
  if (p <= m) update(p , tihuan ,lson);
  else update(p , tihuan , rson);
  PushUP(rt);
}

void update1(int p,int add,int l,int r,int rt)
{
  if (l == r) {
    SUM[rt] = SUM[rt] + add;
    return ;
  }
  int m = (l + r) >> 1;
  if (p <= m) update1(p , add ,lson);
  else update1(p , add , rson);
  PushUP(rt);
}

int query(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return MAX[rt];
  }
  int m = (l + r) >> 1;
  int ret = -1;
  if (L <= m) ret = max(ret , query(L , R , lson));
  if (R > m)  ret =  max(ret , query(L , R , rson));
  return ret;
}

int query1(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return MIN[rt];
  }
  int m = (l + r) >> 1;
  int ret = 99999;
  if (L <= m) ret = min(ret , query1(L , R , lson));
  if (R > m)  ret =  min(ret , query1(L , R , rson));
  return ret;
}

int queryhe(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return SUM[rt];
  }
  int m = (l + r) >> 1;
  int ret = 0;
  if (L <= m) ret += queryhe(L , R , lson);
  if (R > m)  ret +=  queryhe(L , R , rson);
  return ret;
}

int main()
{
  int n , m;
  while (~scanf("%d%d",&n,&m))
  {
    build(1 , n , 1);
    while (m --) {
      char op[2];
      int a , b;
      scanf("%s%d%d",op,&a,&b);
      if (op[0] == 'Q') //区间求最大
      {
         /* for(int i = 1;i<=10;i++)
          printf("%d ",MAX[i]);
        puts("");*/
        printf("%d\n",query(a , b , 1 , n , 1));
      }
      else if(op[0]=='U') //单点替换
        update(a , b , 1 , n , 1);
      else if(op[0]=='M')//区间求最小
      {
        /*for(int i = 1;i<=10;i++)
          printf("%d ",MIN[i]);
        puts("");*/
        printf("%d\n",query1(a , b , 1 , n , 1));
      }
      else if(op[0]=='H')//区间求和
      {
        printf("%d\n",queryhe(a , b , 1 , n , 1));
      }
      else if(op[0]=='S')//单点增加
      {
        scanf("%d%d",&a,&b);
        update1(a , b , 1 , n , 1);
      }
       else if(op[0]=='E')//单点减少
      {
        scanf("%d%d",&a,&b);
        update1(a , -b , 1 , n , 1);
      }
    }
  }
  return 0;
}

//区间替换
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL long long
const int maxn = 100100;
using namespace std;

int lazy[maxn<<2];
int sum[maxn<<2];

void PushUp(int rt)//由左孩子、右孩子向上更新父节点
{
  sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown(int rt,int m) //向下更新
{
  if (lazy[rt]) //懒惰标记
  {
    lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
    sum[rt<<1] = (m - (m >> 1)) * lazy[rt];
    sum[rt<<1|1] = ((m >> 1)) * lazy[rt];
    lazy[rt] = 0;
  }
}

void build(int l,int r,int rt)//建树
{
  lazy[rt] = 0;

  if (l== r)
  {
    scanf("%d",&sum[rt]);
    return ;
  }
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
  PushUp(rt);
}

void update(int L,int R,int c,int l,int r,int rt)//更新
{
  //if(L>l||R>r) return;
  if (L <= l && r <= R)
  {
    lazy[rt] = c;
    sum[rt] = c * (r - l + 1);
    //printf("%d %d %d %d %d\n", rt, sum[rt], c, l, r);
    return ;
  }
  PushDown(rt , r - l + 1);
  int m = (l + r) >> 1;
  if (L <= m) update(L , R , c , lson);
  if (R > m) update(L , R , c , rson);
  PushUp(rt);
}

LL query(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    //printf("%d\n", sum[rt]);
    return sum[rt];
  }
  PushDown(rt , r - l + 1);
  int m = (l + r) >> 1;
  LL ret = 0;
  if (L <= m) ret += query(L , R , lson);
  if (m < R) ret += query(L , R , rson);
  return ret;
}

int main()
{
  int  n , m;
  char str[5];

  while(scanf("%d%d",&n,&m))
  {
    build(1 , n , 1);
    while (m--)
    {
      scanf("%s",str);
      int a , b , c;
      if(str[0]=='T')
      {
        scanf("%d%d%d",&a,&b,&c);
        update(a , b , c , 1 , n , 1);
      }
      else if(str[0]=='Q')
      {
        scanf("%d%d",&a,&b);
        cout<<query(a,b,1,n,1)<<endl;
      }
    }
  }

  return 0;
}

//区间增减
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define max(a,b) (a>b)?a:b
#define min(a,b) (a>b)?b:a
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL __int64
const int maxn = 100100;
using namespace std;

LL lazy[maxn<<2];
LL sum[maxn<<2];

void putup(int rt)
{
  sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void putdown(int rt,int m)
{
  if (lazy[rt])
  {
    lazy[rt<<1] += lazy[rt];
    lazy[rt<<1|1] += lazy[rt];
    sum[rt<<1] += lazy[rt] * (m - (m >> 1));
    sum[rt<<1|1] += lazy[rt] * (m >> 1);
    lazy[rt] = 0;
  }
}

void build(int l,int r,int rt) {
  lazy[rt] = 0;
  if (l == r)
  {
    scanf("%I64d",&sum[rt]);
    return ;
  }
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
  putup(rt);
}

void update(int L,int R,int c,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    lazy[rt] += c;
    sum[rt] += (LL)c * (r - l + 1);
    return ;
  }
  putdown(rt , r - l + 1);
  int m = (l + r) >> 1;
  if (L <= m) update(L , R , c , lson);
  if (m < R) update(L , R , c , rson);
  putup(rt);
}

LL query(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return sum[rt];
  }
  putdown(rt , r - l + 1);
  int m = (l + r) >> 1;
  LL ret = 0;
  if (L <= m) ret += query(L , R , lson);
  if (m < R) ret += query(L , R , rson);
  return ret;
}

int main()
{
  int n , m;int a , b , c;
  char str[5];
  scanf("%d%d",&n,&m);
  build(1 , n , 1);
  while (m--)
  {
    scanf("%s",str);
    if (str[0] == 'Q')
    {
      scanf("%d%d",&a,&b);
      printf("%I64d\n",query(a , b , 1 , n , 1));
    }
    else if(str[0]=='C')
    {
      scanf("%d%d%d",&a,&b,&c);
      update(a , b , c , 1 , n , 1);
    }
  }
  return 0;
}
