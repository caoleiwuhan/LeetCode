package com.lei.cao;

public class Solution {

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String a = "111";
		String b = "1";
		String ans = new Solution().addBinary(a, b);
		System.out.println(ans);
	}
	
	/*
	 * Given two binary strings, return their sum (also a binary string).
		For example,
		a = "11"
		b = "1"
		Return "100".
	 */
	public String addBinary(String a, String b) {
		StringBuffer ans = new StringBuffer();
		int len1 = a.length();
		int len2 = b.length();
		int len = Math.max(len1, len2);
		int carry = 0;
		for (int i = len - 1; i >= 0; --i) {
			int tmp = carry;
			if (len1 > 0) {
				tmp += a.charAt(--len1) - '0';
			}
			if (len2 > 0) {
				tmp += b.charAt(--len2) - '0';
			}
			carry = tmp / 2;
			tmp %= 2;
			ans.insert(0, (char)(tmp + '0'));
		}
		if (carry == 1) {
			ans.insert(0, '1');
		}
		return ans.toString();
	}

}
