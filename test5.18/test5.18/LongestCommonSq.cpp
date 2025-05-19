#include"head.h"

int LCS(char const A[], int n, char const B[], int m)
{
	if (n == -1 || m == -1)return 0;
	if (A[n] == B[m])return LCS(A, n - 1, B, m - 1) + 1;
	return LCS(A, n, B, m - 1) > LCS(A, n - 1, B, m) ? LCS(A, n, B, m - 1) : LCS(A, n - 1, B, m);
}

void swap(char*& A, char*& B);
void swap(int& n, int& m);
int max(int x, int y);
unsigned int lcsIteration(char* A, int n, char* B, int m)
{
	if (n < m) { swap(A, B);swap(n, m); }
	unsigned int* lcs1 = new unsigned int[m + 1];
	unsigned int* lcs2 = new unsigned int[m + 1];
	memset(lcs1, 0x00, sizeof(unsigned int) * (m + 1));lcs2[0] = 0;
	for (int i = 0;i < n;swap(lcs1, lcs2), i++)
		for (int j = 0;j < m;j++)
			lcs2[j + 1] = (A[i] == B[j]) ? 1 + lcs1[j] : max(lcs1[j + 1], lcs2[j]);
	unsigned int solu = lcs2[m];
	delete[]lcs1;delete[]lcs2;
	return 0;

}
