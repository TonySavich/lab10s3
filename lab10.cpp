#include <iostream>
using namespace std;
const int n = 10;
void Merge(int* A, int first, int last)
{
	int middle, start, final;
	int* mas = new int[100];
	middle = (first + last) / 2; 
	start = first; 
	final = middle + 1;
	for (int j = first; j <= last; j++) 
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}

	for (int j = first; j <= last; j++)
		A[j] = mas[j];
	delete[]mas;
};

void MergeSort(int* A, int first, int last)
{
	{
		if (first < last)
		{
			MergeSort(A, first, (first + last) / 2); 
			MergeSort(A, (first + last) / 2 + 1, last); 
			Merge(A, first, last); 
		}
	}
};


void main()
{


	int* A = new int[100];
	
	for (int i = 1; i <= n; i++)
	{
	 A[i] = rand()%10;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << A[i]<<" ";
	}
	cout << endl;
	MergeSort(A, 1, n); 
	
	for (int i = 1; i <= n; i++) 
		cout << A[i] << " ";
	delete[]A;
	
}