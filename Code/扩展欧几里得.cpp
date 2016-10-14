int gcd(int a,int b){
	if(b==0)return a;
	else return (b,a%b);
}
int e_gcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}//最终状态
//逆推由最后的状态推出前面的
 
	int ans=e_gcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=x-(a/b)*y;
	return ans; 
}

#if 0
#include <bits/stdc++.h>

using namespace std;
#if 1
template <class T>
T gcd(const T& a, const T& b,T& x,T& y) {
    if (!b) return x = 1, y = 0, a;
    T r = gcd(b, a % b, y, x);
    return y = y - a / b * x, r;
}
#endif
#if 0
template <class T>
int gcd(int m,int n,int &x,int &y)
{
    int x1,y1,x0,y0;
    x0=1; y0=0;
    x1=0; y1=1;
    x=0; y=1;
    int r=m%n;
    int q=(m-r)/n;
    while(r)
    {
        x=x0-q*x1; y=y0-q*y1;
        x0=x1; y0=y1;
        x1=x; y1=y;
        m=n; n=r; r=m%n;
        q=(m-r)/n;
    }
    return n;
}
#endif
bool linear_equation(int a,int b,int c,int &x,int &y)
{
    int d=gcd<int>(a,b,x,y);
    if(c%d)
        return false;
    int k=c/d;
    x*=k; y*=k;    //求得的只是其中一组解
    return true;
}

bool modular_linear_equation(int a,int b,int n)
{
    int x,y,x0,i;
    int d=gcd<int>(a,n,x,y);
    if(b%d)
        return false;
    x0=x*(b/d)%n;   //特解
    for(i=1;i<=d;i++)
        printf("%d\n",(x0+i*(n/d))%n);
    return true;
}

int main(){
    int x=0,y=0;
    modular_linear_equation(5,1,3);
    cout<<x<<ends<<y;
    return 0;
}
#endif