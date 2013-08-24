//============================================================================
// Valid Number
// Validate if a given string is numeric.
//
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Note: It is intended for the problem statement to be ambiguous. You should
// gather all requirements up front before implementing one.
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isNumber(const char* s) {
        // trim leading/trailing spaces
        while (*s != '\0' && isspace(*s)) s++;
        if (*s == '\0') return false;
        const char *e = s + strlen(s) - 1;
        while (e > s && isspace(*e)) e--;
        // skip leading +/-
        if (*s == '+' || *s == '-') s++;

        bool num = false; // is a digit
        bool dot = false; // is a '.'
        bool exp = false; // is a 'e'
        while (s != e + 1) {
            if (*s >= '0' && *s <= '9') {
                num = true;
            }
            else if (*s == '.') {
                if(exp || dot) return false;
                dot = true;
            }
            else if (*s == 'e') {
                if(exp || num == false) return false;
                exp = true;
                num = false;
            }
            else if (*s == '+' || *s == '-') {
                if (*(s-1) != 'e') return false;
            }
            else {
                return false;
            }
            s++;
        }
        return num;
    }
};

int main() {
   return 0;
}
