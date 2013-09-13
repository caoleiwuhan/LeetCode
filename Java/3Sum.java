package com.lei.cao;

import java.util.*;



public class Solution {
	
	public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
		ArrayList< ArrayList<Integer> > ans = new ArrayList<ArrayList<Integer>>();
		
		Arrays.sort(num);
		
		int size = num.length;
		for (int i = 0; i < size - 2; ++i) {
			if (i > 0 && num[i] == num[i-1])
				continue;
			int left = i + 1;
			int right = size - 1;
			while (left < right) {
				int sum = num[i] + num[left] + num[right];
				if (sum == 0) {
					if (left != i + 1 && num[left] == num[left - 1]) {
						++left;
						continue;
					}
					if (right != size - 1 && num[right] == num[right + 1]) {
						--right;
						continue;
					}
					ArrayList<Integer> tmp = new ArrayList<Integer>();
					tmp.add(num[i]);
					tmp.add(num[left]);
					tmp.add(num[right]);
					ans.add(tmp);
					++left;
					--right;
				} else if (sum > 0) {
					--right;
				} else {
					++left;
				}
			}
		}
		
		return ans;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int []num = {-1, 0, 1, 2, -1, -4};
		ArrayList<ArrayList<Integer>> ans = new Solution().threeSum(num);
		for (int i = 0; i < ans.size(); ++i) {
			ArrayList<Integer> tmp = ans.get(i);
			for (int j = 0; j < tmp.size(); ++j) {
				System.out.print(tmp.get(j) + " ");
			}
			System.out.println();
		}
	}
	
	
}
