/*
DoubleBIT-2D
	Before Using:bit.init(N);bit_x.init(N);bit_y.init(N);bit_xy.init(N);
	统计区域和log(N)，插入区域log(N)
*/
const int MAX_N=1000 + 1;
typedef long long bit_t;
// 二维矩阵的区间和
struct BinaryIndexedTree2D
{
 
	const int  MAX_BIT=MAX_N + 1;
	bit_t data[MAX_BIT][MAX_BIT];
	int size;
	void init(int size)
	{
		memset(data, 0, sizeof(data));
		this->size = size;
	}
	// 求(0,0) 到(x,y)围成的矩形区域元素之和
	bit_t sum(int y, int x)
	{
		bit_t ret = 0;
		for (int ty = y; ty; ty -= ty&-ty)
		{
			for (int tx = x; tx; tx -= tx&-tx)
			{
				ret += data[ty][tx];
			}
		}
		return ret;
	}
	// 执行(x,y) += v
	void add(int y, int x, bit_t v)
	{
		for (int ty = y + 1; ty <= size; ty += ty&-ty)
		{
			for (int tx = x + 1; tx <= size; tx += tx&-tx)
			{
				data[ty][tx] += v;
			}
		}
	}
};
BinaryIndexedTree2D bit_xy, bit_x, bit_y, bit;
// sum(y,x)=bit_xy(y,x)*yx + bit_y(y,x)*y + bit_x(y,x)*x + bit(y,x)
 

//矩形[y1, y2) * [x1, x2)区域内每个元素增加v
void add(int y1, int y2, int x1, int x2, bit_t v)
{
	bit_xy.add(y1, x1, v);
	bit_xy.add(y1, x2, -v);
	bit_xy.add(y2, x1, -v);
	bit_xy.add(y2, x2, v);
 
	bit_x.add(y1, x1, -y1 * v);
	bit_x.add(y1, x2, y1 * v);
	bit_x.add(y2, x1, y2 * v);
	bit_x.add(y2, x2, -y2 * v);
 
	bit_y.add(y1, x1, -x1 * v);
	bit_y.add(y1, x2, x2 * v);
	bit_y.add(y2, x1, x1 * v);
	bit_y.add(y2, x2, -x2 * v);
 
	bit.add(y1, x1, y1 * x1 * v);
	bit.add(y1, x2, -x2 * y1 * v);
	bit.add(y2, x1, -y2 * x1 * v);
	bit.add(y2, x2, y2 * x2 * v);
}

// 区域和
bit_t sum(int y, int x)
{
	return bit_xy.sum(y, x) * y * x + bit_x.sum(y, x) * x + bit_y.sum(y, x) * y + bit.sum(y, x);
}
 
// 区域和，左开右闭
bit_t sum(int y1, int y2, int x1, int x2)
{
	return sum(y1, x1) + sum(y2, x2) - (sum(y1, x2) + sum(y2, x1));
}
 
///////////////////////////SubMain//////////////////////////////////