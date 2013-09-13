package com.lei.cao;

import java.util.*;
public class Solution {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Solution().test();
	}
	
	void test() {
		String [] strs = 
		{
			"abc", "acb", "bca", "bbc", "ccc", "bcb"
		};
		ArrayList<String> ans = anagrams(strs);
		Iterator<String> itr = ans.iterator();
		while (itr.hasNext()) {
			System.out.println(itr.next());
		}		
	}

	public ArrayList<String> anagrams(String[] strs) {
		ArrayList<String> ans = new ArrayList<String>();
		Map<String, ArrayList<String> > strMap = new HashMap<String, ArrayList<String> > ();
		int size = strs.length;
		for (int i = 0; i < size; ++i) {
			String s = strs[i];
			// ½«sÅÅÐò
			char [] chars = s.toCharArray();
			Arrays.sort(chars);
			String key = new String(chars);
			if (strMap.containsKey(key)) {
				strMap.get(key).add(strs[i]);
			} else {
				ArrayList<String> sList = new ArrayList<String>();
				sList.add(strs[i]);
				strMap.put(key, sList);
			}			
		}
		Set<String> keySet = strMap.keySet();
		Iterator<String> itr = keySet.iterator();
		while (itr.hasNext()) {
			ArrayList<String> list = strMap.get(itr.next());
			if (list.size() > 1) {
				Iterator<String> listItr = list.iterator();
				while (listItr.hasNext()) {
					ans.add(listItr.next());
				}
			}
		}
		return ans;
	}
}
