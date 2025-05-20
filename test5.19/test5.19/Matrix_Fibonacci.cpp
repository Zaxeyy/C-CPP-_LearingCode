#include"head.h"

struct Matrix2_2 {
	_int64 m[2][2];
};

Matrix2_2 multiply(Matrix2_2 a, Matrix2_2 b){
	Matrix2_2 res;
	res.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0];
	res.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1];
	res.m[1][0] = a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0];
	res.m[1][1] = a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1];
	return res;
}

Matrix2_2 matrix_pow(Matrix2_2 base, int n) {
	Matrix2_2 res = { {{1,0},{0,1}} };
	while (n > 0){
		if (n & 1)res = multiply(res, base);
		base = multiply(base, base);n /= 2;
	}
	return res;
}

ll fib(int n){
	if (!n)return 0;
	Matrix2_2 base = { {{1,1},{1,0}} };
	Matrix2_2 res = matrix_pow(base, n - 1);
	return res.m[0][0];
}

int main(){
	int n = 64;
	while (n--){cout << fib(100 - n) << endl;}
	return 0;
}

class Fib {//基于动态迭代法求Fibonacci构造Fib类
private:
	int f, g;
public:
	Fib(int n){f = 1;g = 0;while (g < n)next();}//返回不小于n的最小Fibonacci项
	int get(){return g;}//获取当前Fibonacci项
	int next(){g = f + g;f = g - f;return g;}//获取下一项
	int prev(){f = g - f;g = g - f;return g;}//获取上一项
};

