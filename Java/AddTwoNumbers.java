package com.lei.cao;

public class Solution {

	public class ListNode {
		int val;
		ListNode next;
		ListNode (int x) {
			val = x;
			next = null;
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
				
		new Solution().test();
	}
	
	public void test() {
		ListNode n2 = new ListNode(2);
		ListNode n4 = new ListNode(4);
		ListNode n3 = new ListNode(3);
		ListNode n1 = new ListNode(1);
		
		n2.next = n4;
		n4.next = n3;
		n3.next = n1;
		
		ListNode n5 = new ListNode(5);
		ListNode n6 = new ListNode(6);
		ListNode n42 = new ListNode(4);
		
		n5.next = n6;
		n6.next = n42;
		
		ListNode ans = addTwoNumbers(n2, n5);
		while (ans != null) {
			System.out.println(ans.val);
			ans = ans.next;
		}		
	}

	
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode ans = new ListNode (0);
		ListNode p = ans;
		int carry = 0;
		while (l1 != null || l2 != null) {
			int tmp = carry;
			if (l1 != null) {
				tmp += l1.val;				
			}
			if (l2 != null) {
				tmp += l2.val;
			}
			carry = tmp / 10;
			tmp %= 10;
			ListNode pNode = new ListNode (tmp);
			p.next = pNode;
			if (l1 != null)
				l1 = l1.next;
			if (l2 != null)
				l2 = l2.next;
			p = p.next;
		}
		if (carry != 0) {
			ListNode pNode = new ListNode (1);
			p.next = pNode;
		}
		
		return ans.next;
	}

}
