#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	/**
	*
	*假设你有一个数组，其中第 i 个元素是股票在第 i 天的价格。
	*你有一次买入和卖出的机会。（只有买入了股票以后才能卖出）。
	*请你设计一个算法来计算可以获得的最大收益。
	* @param prices int整型vector
	* @return int整型
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
	*假设你有一个数组，其中第i个元素表示某只股票在第i天的价格。
	*设计一个算法来寻找最大的利润。
	*你可以完成任意数量的交易(例如，多次购买和出售股票的一股)。
	*但是，你不能同时进行多个交易(即，你必须在再次购买之前卖出之前买的股票)。
	* @param prices int整型vector
	* @return int整型
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