#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

using namespace std;
const int N = 500005;

struct Node
{
    int v,order;
};

int n;
int c[N];
int aa[N];    //离散化后的数组
Node a[N];    //树状数组

int Lowbit(int x)
{
    return x & (-x);
}

void Update(int t,int val)
{
    for(int i=t; i<=n; i+=Lowbit(i))
        c[i] += val;
}

int getSum(int x)
{
    int ans=0;
    for(int i=x; i>0; i-=Lowbit(i))
        ans += c[i];
    return ans;
}

bool cmp(Node a,Node b)
{
    return a.v<b.v;
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        //离散化
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i].v);
            a[i].order=i;
        }
        sort(a+1,a+1+n,cmp);//把a数组从小到大排序，然后从最小的那个数的输入顺序开始放到aa中 
        //离散化 
        for(int i=1; i<=n; i++)
            aa[a[i].order]=i;//aa就变成了要判断逆序数的数组了
			//从a变到aa，如9 1 0 5 4 离散化之后是5 2 1 4 3 

        //树状数组求逆序数
        memset(c,0,sizeof(c));
        long long ans1=0;
        //原理就是一位位插入，然后每次寻找一个位置上的逆序数，再全部相加 
        for(int i=1; i<=n; i++)
        {
            Update(aa[i],1);//先更新这个点，用1来表示他的个数 
            //getSum得到的是比aa[i]小（包括等于）的数的个数，就是1-i区间中比aa小的个数，i-getsum就是比他大的个数，i为当前插入的个数 
           // cout<<i-getSum(aa[i])<<" "; 
            ans1+=i-getSum(aa[i]);
        }
        printf("%I64d\n",ans1);
    }
    return 0;
}

