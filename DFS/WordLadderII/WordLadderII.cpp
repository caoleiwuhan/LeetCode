//============================================================================
// Word Ladder II
// Given two words (start and end), and a dictionary, find all shortest 
// transformation sequence(s) from start to end, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,
//
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// Return
//   [
//       ["hit","hot","dot","dog","cog"],
//       ["hit","hot","lot","log","cog"]
//   ]
// Note:
//  All words have the same length.
//  All words contain only lowercase alphabetic characters.
//============================================================================

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
     vector<vector<string>> findLadders(string start, string end, unordered_set<string> & dict) 
     {
         dict.insert(end);
         int steps = ladderLength(start, end, dict);
         cout << steps << endl;

         vector<vector<string> > res;
         vector<string> path;
         unordered_set<string> visit;
         dfs(start, end, dict, visit, steps, path, res);
         return move(res);
     }

     void dfs(string const & start, string const & end, unordered_set<string> const & dict, unordered_set<string> visit, int steps, vector<string> path, vector<vector<string> > & res)
     {
         if (steps == 0 || visit.find(start) != visit.end())
            return;
         visit.insert(start);
         path.push_back(start);
         
         if (start == end)
         {
             res.push_back(path);
             return;
         }

        for (string node : getNeighbors(start, dict))
            dfs(node, end, dict, visit, steps-1, path, res);
     }
     
     int ladderLength(string const & start, string const & end, unordered_set<string> dict) 
     {   
         queue<pair<string, int> > queue;
         queue.push(make_pair(start, 1));
         while (!queue.empty())
         {   
             pair<string, int> cur = queue.front();   
             queue.pop();
             if (cur.first == end)
                 return cur.second;

             for (string node : getNeighbors(cur.first, dict))
                 queue.push(make_pair(node, cur.second+1));
         }   

         return 0;
     }   

     vector<string> getNeighbors(string const & word, unordered_set<string> dict)
     {
         vector<string> res;
         for (size_t i = 0; i < word.size(); i++)
         {
             string copy(word);
             for (char c = 'a'; c <= 'z'; c++)
             {
                 copy[i] = c;
                 if (word == copy)
                     continue;
                 if (dict.find(copy) != dict.end())
                 {
                     res.push_back(copy);
                     dict.erase(copy);
                 }
             }
         }
         return move(res);
     }
};

int main() {
    return 0;
}
