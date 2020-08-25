#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	*��������һ�����飬���е� i ��Ԫ���ǹ�Ʊ�ڵ� i ��ļ۸�
	*����һ������������Ļ��ᡣ��ֻ�������˹�Ʊ�Ժ������������
	*�������һ���㷨��������Ի�õ�������档
	* @param prices int����vector
	* @return int����
	*/
	int maxProfit(vector<int>& prices) {
		// write code here
		if (prices.size()<2)
			return 0;
		int min_value = prices[0];
		int maxProfit = prices[1] - prices[0];
		//max value -min value
		//7 6 5 4 9 10 11 3 12
		for (int i = 1; i<prices.size(); i++) {
			if (min_value>prices[i]) {
				min_value = prices[i];
			}
			else {
				maxProfit = max(maxProfit, prices[i] - min_value);
			}
		}
		return maxProfit < 0 ? 0 : maxProfit;
	}
};

class Solution2 {
public:
	/**
	*
	*��������һ�����飬���е�i��Ԫ�ر�ʾĳֻ��Ʊ�ڵ�i��ļ۸�
	*���һ���㷨��Ѱ����������
	*�����������������Ľ���(���磬��ι���ͳ��۹�Ʊ��һ��)��
	*���ǣ��㲻��ͬʱ���ж������(������������ٴι���֮ǰ����֮ǰ��Ĺ�Ʊ)��
	* @param prices int����vector
	* @return int����
	*/
	int maxProfit(vector<int>& prices) {
		// write code here
		int max = 0;
		if (prices.empty())
			return max;
		for (int i = 0; i<prices.size() - 1; i++) {
			if (prices[i]<prices[i + 1])
				max += prices[i + 1] - prices[i];
		}
		return max;
	}
};