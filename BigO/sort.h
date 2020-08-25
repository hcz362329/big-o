#ifndef SORT_H
#define SORT_H



#include <windows.h>
#include <string>
#include <map>
#include <vector>
using namespace std;
template<typename T>
void Swap(T & a, T & b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
};

//每个循环可能出现多次值得交换
bool BubbleSort(int a[], int n) {
	bool exchange = false;
	int pos = 0;
	for (int i = 0; i < n-1;i++) {
		if (a[i] > a[i + 1]) {
			Swap(a[i], a[i + 1]);
			exchange = true;
		}
	}
	return exchange;
}

void BubbleSortList(int a[],int n) {
	for (int i = 0; i < n; i++) {
		if (!BubbleSort(a, n - i))
			break;
	}
}

//升序或者降序
//选择排序核心，记录满足条件的位置，最后将最终值写入初始位置
//每个循环只做一次交换
//位置不变，值不替换
void SelectSort(int a[], int n,bool asc) {
	int pos = 0;
	int move = 0;
	for (int i = 0; i < n; i++) {
		pos = i;
		move = i;
		for (int j = i; j < n ; j++) {
			if (asc) {
				if (a[move] > a[j]) {
					move = j;
				}
			}
			else {
				if (a[move] < a[j]) {
					move = j;
				}
			}
		}
		if (pos != move) {
			Swap(a[pos],a[move]);
		}
	}
}

//插入排序的核心思想是平移，不是交换
//比较的对象一直是插入位置的内容，出现比插入值小的对象时停止当前循环
void InsertSort(int a[], int n) {
	int tmpValue;
	for (int i = 1; i < n; i++) {
		tmpValue = a[i];
		int k = i;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > tmpValue) {
				a[j + 1] = a[j];
				k = j;
			}
			else {
				break;
			}
		}
		if (k != i) {
			a[k] = tmpValue;
		}
	}
}

//快速排序，取中间位置
//小的在左，大的在右
//快速排序（从小到大）
void quicksort(int arr[],int left, int right)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			Swap(arr[i], arr[j]);
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quicksort(arr,left, i - 1);//递归左边
	quicksort(arr,i + 1, right);//递归右边
}

//居中值排序
class SortSolution {
public:
	void sortColors(int A[], int n) {
		int lt = 0, gt = n - 1;
		for (int i = 0; i <= gt; i++) {
			if (A[i]<1) {
				A[i] = A[lt];
				A[lt] = 0;
				lt++;
			}
			else if (A[i]>1) {
				A[i] = A[gt];
				A[gt] = 2;
				gt--;
				i--;
			}
		}
	}
};


class ZeroSolution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		map<int, bool> row, col;
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				if (matrix[i][j] == 0)
					row[i] = col[j] = true;

		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
			{
				if (row[i] || col[j])
					matrix[i][j] = 0;
			}
	}
};

#endif // !SORT_H
