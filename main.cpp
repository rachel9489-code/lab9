#include "bookPtr.h"
#include <memory>
int main()
{
    using namespace HanYoonseo2649055;

    bookPtr bp1;
    bookPtr bp2{bp1};//copy constructor
    bookPtr bp3{std::move(bp2)}; //move constructor
    bp2 = std::move(bp3);//move operator=
    bp3 = bp2; //copy operator=

    bookPtr* bp{ new bookPtr };
    delete bp; 

    std::unique_ptr<bookPtr> up1;

    std::unique_ptr<bookPtr> up2{ std::make_unique(book{"title",1,10000}) };
    
    return 0;
}