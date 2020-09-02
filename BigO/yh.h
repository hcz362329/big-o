#pragma once
#include <vector>
using namespace std;
class SolutionSingle {
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

class Solution2Search {
public:
	/**
	 * ���ֲ���
	 * @param n int���� ���鳤��
	 * @param v int���� ����ֵ
	 * @param a int����vector ��������
	 * @return int����
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
