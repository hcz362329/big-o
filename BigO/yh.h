#pragma once
class Solution {
public:
	/**
	*
	* @param A int����һά����
	* @param n int A���鳤��
	* @return int����
	*/
	int singleNumber(int* A, int n) {
		// write code here
		int ret = *A;
		for (int i = 1; i<n; i++) {
			ret ^= A[i];
		}
		return ret;
	}
};
