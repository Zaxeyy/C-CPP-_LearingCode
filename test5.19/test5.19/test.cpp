#include"head.h"

void move(int len, char x, char y, int& opr){
	cout << setw(4) << len << "  " << x << "---->" << y << endl;opr++;
}

void hanoi(int n, char A, char B, char C, int& opr){
	if (n == 1){move(n, A, C, opr);return;}
	hanoi(n - 1, A, C, B, opr);move(n, A, C, opr);hanoi(n - 1, B, A, C, opr);
}

template<typename T>
T abs(T x) { return x > 0 ? x : (-x); }

int Gcd(int a, int b){
	while (1) {
		if (a < b) { a += b;b = a - b;a = a - b; }
		a = a - b;
		if(!a||!b)return a ? a : b;
	}
}
uint Gcd1(uint a, uint b) { uint c = 0;while (c = a % b) { a = b;b = c; }return b; }

int main(){
	int a=1, b=1;
	while (a||b) { 
		cin >> a >> b; 
		cout << Gcd(a, b) << endl;
		cout << Gcd1(a, b) << endl;
	}
	return 0;
}