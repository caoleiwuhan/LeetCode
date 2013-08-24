//============================================================================
// SimplifyPath
// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together,
// such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".
//============================================================================

#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int N = path.size();
        if (N <= 1) return path;
        deque<char> buffer;
        for (int i = 0; i < N; i++) {
            char c = path[i];
            if (c == '/') {
                if (buffer.empty() || buffer.back() != '/')
                    buffer.push_back(path[i]);
            }
            else if (c == '.') {
                if (i+1 < N && path[i+1] == '.') {
                    i++;
                    buffer.pop_back();
                    while (!buffer.empty()) {
                        if (buffer.back() != '/') buffer.pop_back();
                        else break;
                    }
                }
            }
            else {
                buffer.push_back(path[i]);
            }
        }
        if (buffer.size() < 2) return "/";
        if (buffer.back() == '/') buffer.pop_back();
        string res;
        while (!buffer.empty()) {
            res.push_back(buffer.front());
            buffer.pop_front();
        }
        return res;
    }
};

int main() {
	return 0;
}
