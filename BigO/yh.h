#pragma once
#include <vector>
using namespace std;
class SolutionSingle {
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

class Solution2Search {
public:
	/**
	 * 二分查找
	 * @param n int整型 数组长度
	 * @param v int整型 查找值
	 * @param a int整型vector 有序数组
	 * @return int整型
	 */
	int upper_bound_(int n, int v, vector<int>& a) {
		// write code here
		int ret = n + 1;
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = (right - left) / 2 + left;
			if (a[mid] > v) {
				right = mid - 1;
			}
			else if (a[mid] < v) {
				left = mid + 1;
			}
			else {
				for (int i = mid; i >= 0; i--) {
					if (a[i] == v) {
						ret = i;
					}
					else {
						break;
					}
				}
				break;
			}
		}
		return ret;
	}
};
