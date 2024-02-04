// INTRO26.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

void showval(void);

int main()
{
    int mainvar = 100;
    showval();
    cout << funcvar << '\n';

    return 0;
}

void showval(void)
{
    int funcvar = 10;
    cout << funcvar << '\n';
    cout << mainvar << '\n';
}
