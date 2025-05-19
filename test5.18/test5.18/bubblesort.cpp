#include"head.h"

void bubblesort(int A[], int n)
{
	int temp;
	for (bool sorted = false;sorted = !sorted;n--)
	{
		for (int i = 1;i < n;i++)
		{
			if (A[i - 1] > A[i])
			{
				temp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temp;
				sorted = false;
			}
		}
	}
}

void showArr(int A[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << A[i] << " ";
	}
}
