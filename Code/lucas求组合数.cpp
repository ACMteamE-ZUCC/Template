#include<iostream>  
#include<cstdio>  
#include<ctime>  
#include<cstring>  
#include<cstdlib>  
#include<vector>  
using namespace std;  
long long mod=110119;
inline long long PowMod(long long a,long long b)
{  
    long long ret=1;  
    while(b)
	{  
        if(b&1)
		ret=(ret*a)%mod;  
		
        a=(a*a)%mod;  
        b>>=1;  
    }  
    return ret;  
}  
long long fac[1000005];  
inline long long Get_Fact(long long p){  
    fac[0]=1;  
    for(int i=1;i<=p;i++)  
        fac[i]=(fac[i-1]*i)%p;  
}  
inline long long Lucas(long long n,long long m,long long p){  
    long long ret=1;  
    while(n&&m){  
        long long a=n%mod,b=m%mod;  
        if(a<b) return 0;  
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2))%p;  
        n/=p;  
        m/=p;  
    }  
    return ret;  
} 
int main()
{
	Get_Fact(mod);  
	int n,m;
	scanf("%d%d",&n,&m);//n个里选择m个 n>=m 
	printf("%I64d\n",Lucas(n,m,mod));
	return 0;
}
