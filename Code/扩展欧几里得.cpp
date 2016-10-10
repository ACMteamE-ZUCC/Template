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
