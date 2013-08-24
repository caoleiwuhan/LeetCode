//============================================================================
// Substring with Concatenation of All Words
// You are given a string, S, and a list of words, L, that are all of the
// same length. Find all starting indices of substring(s) in S that is a
// concatenation of each word in L exactly once and without any intervening
// characters.
//
// For example, given:
// S: "barfoothefoobarman"
// L: ["foo", "bar"]
//
// You should return the indices: [0,9].
// (order does not matter).
//============================================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		map<string, int> toFind;
		map<string, int> hasFound;
		for (size_t i = 0; i < L.size(); i++) toFind[L[i]]++;
		int N = L.size();
		int M = L[0].size();
		vector<int> res;
		for (int i = 0; i <= (int)S.size() - N * M; i++) {
			hasFound.clear();
			int j;
			for (j = 0; j < N; j++) {
				int k = i + j * M;
				string sub = S.substr(k, M);
				if (toFind.find(sub) == toFind.end()) break;
				hasFound[sub]++;
				if (hasFound[sub] > toFind[sub]) break;
			}
			if (j == N) res.push_back(i);
		}
		return res;
	}
};

int main() {
	return 0;
}
