#include<iostream>
using namespace std;
#define MAXN 10005
typedef struct {
	int m[MAXN][MAXN];
}Matrax;
int n,M;
Matrax a,per;
int n,M;//M is mod number

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a.m[i][j];
			a.m[i][j]%=M;
			per.m[i][j]=(i==j);//�õ���λ����,�Խ��ߵ���1 
		}
	}
}
Matrax multi(Matrax x, Matrax y){
		Matrax c;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				c.m[i][j]=0;
				for(int k=0;k<n;k++){
					c.m[i][j]=(c.m[i][j]+a.m[i][k]*y[k][j])%M;
				}
				
			}
		}
		return c;
}
Matrax power(int k){
	Matrax c,p,ans=per;
	// ans �õ�ǰ�����õĵ�λ���� 
	p=a;
	while(k){
		if(k&1){
			ans=multi(ans,p);
		}
			k/=2;
			p=multi(p,p);		
		}
	}
	return ans; 
}
int main(){
	
} 
