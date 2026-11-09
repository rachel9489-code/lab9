#include "bookPtr.h"

int main()
{
    using namespace HanYoonseo2649055;

    bookPtr bp1, bp2{bp1}, bp3;
    bp3 = bp1;

    return 0;
}