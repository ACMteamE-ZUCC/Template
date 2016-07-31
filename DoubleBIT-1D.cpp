typedef long long ll;
struct BIT {
	typedef int BIT_c;
	int BIT_MAX = 10000;
	BIT_c *BIT;
	BIT(BIT_c size) {
		BIT_MAX = size + 5;
		BIT=new BIT_c[BIT_MAX];
		memset(BIT,0,sizeof(BIT_c*BIT_MAX));
	}
	~BIT(){
		delete []BIT;
	}
	inline int lowbit(const int &n) {
		return n & (-n);
	}
	inline int upper(const int &n) {
		return n + lowbit(n);
	}
	inline int lower(const int &n) {
		return n - lowbit(n);
	}
	int add(int ith, BIT_c dlt) {
		while (ith <= BIT_MAX) {
			BIT[ith] += dlt;
			ith = upper(ith);
		}
		return 0;
	}
	BIT_c sum(int ith) {
		BIT_c ans = 0;
		while (ith > 0) {
			ans += BIT[ith];
			ith = lower(ith);
		}
		return ans;
	}
};
BIT bit0(MAX_N);
BIT bit1(MAX_N);
// 双BIT实现O(logn)区间加

// 双BIT
LL sum(int i)//[0,n]左闭右闭
{
	return bit1.sum(i) * i + bit0.sum(i);
}

LL sum(int from, int to)//(from, to]左开右闭
{
	return sum(to) - sum(from);
}

void add(int from, int to, LL x)// [from, to]左闭右闭
{
	add(bit0, from, -x * (from - 1));
	add(bit1, from, x);
	add(bit0, to, x * to);
	add(bit1, to, -x);
}