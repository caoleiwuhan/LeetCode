//============================================================================
// Palindrome Number
// Determine whether an integer is a palindrome. Do this without extra space.
//
// Some hints:
// Could negative integers be palindromes? (ie, -1)
//
// If you are thinking of converting the integer to string, note the
// restriction of using extra space.
//
// You could also try reversing an integer. However, if you have solved the
// problem "Reverse Integer", you know that the reversed integer might
// overflow. How would you handle such case?
//
// There is a more generic way of solving this problem.
//============================================================================

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int d = 1;
        while (x / d >= 10) d *= 10;
        while (x != 0) {
            int l = x / d;
            int r = x % 10;
            if (l != r) return false;
            x = (x % d) / 10;
            d /= 100;
        }
        return true;
    }
};

int main() {
    return 0;
}
