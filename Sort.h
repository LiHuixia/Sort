#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
void InsertSort(int *a, size_t n)
{
	assert(a);
	for (size_t i = 0; i < n - 1; i++)
	{
		size_t end = i;
		int tmp = a[end + 1];
		while ((end>=0) && (a[end] > tmp))
		{
			swap(a[end+1], a[end]);
			end--;
		}
	}
}

void ShellSort(int *a, size_t n)
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; //加1保证最后一次gap=1；
	}
	for (int i = 0; i < n - gap; ++i)
	{
		int end = i;
		int tmp = a[end + gap];
		while (end >= 0 && a[end]>tmp)
		{
			swap(a[end], a[end + gap]);
			end=end-gap;
		}
	}
}

void SelectSort(int *a, int n)  //选取一个最大的和最后一个交换
{
	for (int j = 0; j< n; j++)
	{
		int max = 0;
		for (int i = 1; i < n-j; i++)
		{
			if (a[i]>a[max])
			{
				swap(a[i], a[max]);
			}
		}
		swap(a[max], a[n-j-1]);
	}
}

void _AdjustDown(int *a, size_t n, size_t parent)
{
	size_t child = 2 * parent + 1;
	while (child < n)
	{
		if ((child+1<n)&&a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child]>a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;	
	}
}
void HeapSort(int *a, size_t n)    //建大堆，第一个和最后一个交换 O(lgN)
{
	assert(a);
	for (int i = (n - 2) / 2; i > 0; --i)
	{
		_AdjustDown(a, n, i); 
	}
	for (size_t i = 0; i < n; ++i)
	{
		swap(a[0], a[n - 1 - i]);
		_AdjustDown(a, n - 1 - i, 0);
	}
}
void print(int *a,size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << ",";
	}
	cout << endl;
}



void  test()
{
	int a[] = { 9, 4, 1, 6, 8, 5, 0, 3, 7, 2 };
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	//ShellSort(a, sizeof(a) / sizeof(a[0]));
	/*SelectSort(a, sizeof(a) / sizeof(a[0]));*/
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	print(a, sizeof(a) / sizeof(a[0]));
}