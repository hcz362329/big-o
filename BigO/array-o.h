#pragma once
#include <vector>
//归纳，总结,找规律
class ClimbSolution {
public:
	/**
	*
	* @param n int整型
	* @return int整型
	*/
	int climbStairs(int n) {
		// write code here
		//a[n]=a[n-1]=a[n-2]
		int * a = new int[n + 1];
		a[0] = 0;
		a[1] = 1;
		a[2] = 2;
		for (int i = 3; i <= n; i++) {
			a[i] = a[i - 1] + a[i-2];
		}
		return a[n];
	}
};

/*
MoveSolution moveS;
int m = 10;
int n = 10;
int **k = moveS.uniquePaths(m,n);
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
printf("	%d	", k[i][j]);
}
printf("\n\n");
}
printf("	%d	", k);
*/
//固定方向移动
class MoveSolution {
public:
	/**
	*
	* @param m int整型
	* @param n int整型
	* @return int整型
	*/
	int** uniquePaths(int m, int n) {
		// write code here
		int **move = new int*[m];
		for (int i = 0; i<m; i++)
			move[i] = new int[n];
		for (int i = 0; i<m; i++) {
			move[i][0] = 1;
		}
		for (int i = 0; i<n; i++) {
			move[0][i] = 1;
		}
		for (int i = 1; i<m; i++) {
			for (int j = 1; j<n; j++) {
				move[i][j] = move[i][j - 1] + move[i - 1][j];
			}
		}
		return move;
	}
};

class RotateSolution {
public:
	void swap(int & a,int & b) {
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n - i-1; j++) {
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
			}
		}
		printf("\n\n");
		printf("\n\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("	%d	", matrix[i][j]);
			}
			printf("\n\n");
		}
		printf("\n\n");
		for (int i = 0; i<n / 2; i++) {
			for (int j = 0; j<n; j++) {
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
		printf("\n\n");
	}
};

class RemoveEleSolution {
public:
	int remoteElement(int A[], int n, int ele) {
		for (int i = 0; i < n; i++) {
			if (A[i] == ele) {
				A[i] = A[n - 1];
				i--;
				n--;
			}
		}
		return n;
	}
};

class CycleSolution {
public:
	bool isCycleInteger(int x) {
		int num1 = x, num2 = 0;
		while (num1) {
			num2 = num2 * 10 + num1 % 10;
			num1 /= 10;
		}
		return num2 == x;
	}
};