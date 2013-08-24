//============================================================================
// Text Justification
// Given an array of words and a length L, format the text such that each line
// has exactly L characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words
// as you can in each line. Pad extra spaces ' ' when necessary so that each
// line has exactly L characters.
//
// Extra spaces between words should be distributed as evenly as possible. If
// the number of spaces on a line do not divide evenly between words, the empty
// slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is
// inserted between words.
//
// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
//
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.
//
// Corner Cases:
// A line other than the last line might contain only one word. What should
// you do in this case?
// In this case, that line should be left-justified.
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        if(words.size() == 0 || L <= 0) {
            result.push_back("");
            return result;
        }
        int N = words.size();
        vector<int> spaces;
        int start = 0, end = 0;
        while (end < N)  {
            // justify one line
            spaces.clear();
            int length = words[start].size();
            end = start+1;
            while (end < N) {
                int M = words[end].size();
                if (length + 1 + M > L) break;
                length += 1 + M;
                spaces.push_back(1);
                end++;
            }
            int rest = L-length;
            if (spaces.size() == 0 || end == N) {
                spaces.push_back(rest);
            }
            else if (end < N) {
                size_t j = 0;
                while (rest > 0) {
                    spaces[j++] += 1;
                    if (j == spaces.size()) j = 0;
                    rest--;
                }
                spaces.push_back(0);
            }
            // append one line
            string line = "";
            for (int i = start; i < end; i++) {
                line.append(words[i]); // append words
                for (int j = 0; j < spaces[i - start]; j++)
                    line.push_back(' '); // append spaces
            }
            result.push_back(line);
            start = end;
        }
        return result;
    }
};

int main() {
    return 0;
}
