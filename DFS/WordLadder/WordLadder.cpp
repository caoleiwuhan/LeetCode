//============================================================================
// Word Ladder
// Given two words (start and end), and a dictionary, find the length of 
// shortest transformation sequence from start to end, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
//
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//============================================================================

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
     int ladderLength(string start, string end, unordered_set<string> &dict) 
     {
         queue<pair<string, int> > queue;
         queue.push(make_pair(start, 1));
         dict.insert(end);
         while (!queue.empty())
         {
            pair<string, int> cur = queue.front();   
            queue.pop();
            if (cur.first == end)
            {
                return cur.second;
            }

            for (string word : getNeighbors(cur.first, dict))
            {
                queue.push(make_pair(word, cur.second+1));
            }
         }

         return 0;
     }

     vector<string> getNeighbors(string const & word, unordered_set<string> &dict)
     {
        vector<string> res;
        for (size_t i = 0; i < word.size(); i++)
        {
            string copy(word);
            for (char c = 'a'; c <= 'z'; c++)
            {
                copy[i] = c;
                if (dict.find(copy) != dict.end())
                {
                    res.push_back(copy);
                    dict.erase(copy);
                }
            }
        }
        return res;
     }
};

int main() {
    Solution sol;
    unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
    cout << sol.ladderLength("hit", "cog", dict) << endl;
    return 0;
}
