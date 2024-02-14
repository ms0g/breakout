#include "UTILS.H"

#define abs(x) ((x) < 0 ? -(x) : (x))

static const char* digit_array = "0123456789";

string to_string(int val) {
    static char _ptr[4];
    string strNum;

    int quotient = val;
    int i = 0;

    do {
        char c = digit_array[abs(quotient % 10)];
        _ptr[i++] = c;
        quotient = (quotient >> 1) / 5;
    } while (quotient);
    
    strNum.ptr = _ptr;
    strNum.size = i;

    return strNum;

}