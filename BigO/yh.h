#pragma once
class Solution {
public:
	/**
	*
	* @param A int整型一维数组
	* @param n int A数组长度
	* @return int整型
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
