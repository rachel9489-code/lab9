#pragma once
#include "book.h"

namespace HanYoonseo2649055
{
    class bookPtr
    {
        book* bPtr;
    public:
        bookPtr(const book& b = book{"bookTitle",1,10000}):bPtr{ new book(b) }{}
        ~bookPtr(){delete bPtr;}
        bookPtr(const bookPtr& copy)
        {
            bPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
        }
        bookPtr& operator=(const bookPtr& copy)
        {
            if (this != &copy)
            {
                delete bPtr;
                bPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
            }
            return *this;
        }
    };
}