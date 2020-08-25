#pragma once

//���ɣ��ܽ�,�ҹ���
class ClimbSolution {
public:
	/**
	*
	* @param n int����
	* @return int����
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

//�̶������ƶ�
class MoveSolution {
public:
	/**
	*
	* @param m int����
	* @param n int����
	* @return int����
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
