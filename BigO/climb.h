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

//����һ������n��������1��n^2n ��������˳������n��n�ľ���
class SpiralSolution{
public:
	vector<vector<int> > spiral(int n){
		vector<vector<int> > result(n,vector<int>(n,0));
		int left =0,right=n-1,low=0,high=n-1;
		int n =1;
		while(left<=right&&low<=high){
			for(int i=left;i<=right;i++)
				result[low][i]=x++;
			for(int i=low+1;i<=high;i++)
				result[i][right]=x++;
			for(int i=right-1;i>=left;i--)
				result[high][i]=x++;
			for(int i=high-1;i>low;i--)
				result[i][left]=x++;
			left++;
			right--;
			low++;
			high--;
		}
	}

};

class MaxSubSolution {
public:
    /**
     * 
     * @param A int����һά���� 
     * @param n int A���鳤��
     * @return int����
     */
    int maxSubArray(int* A, int n) {
        // write code here
        int max_value = A[0];
        int sum_value = 0;
        for(int i=0;i<n;i++){
            sum_value += A[i];
            max_value = max(max_value,sum_value);
            if(sum_value<0)
                sum_value = 0;
        }
        return max_value;
        
    }
};