#pragma once
#include "book.h"

namespace HanYoonseo2649055
{
    class bookPtr
    {
        book* bPtr;
    public:
        bookPtr(const book& b = book{"bookTitle",1,10000}):bPtr{ new book(b) }
        {
            std::cout << "constructor\n";
        }
        ~bookPtr()
        {
            std::cout << "~destructor\n";
            delete bPtr;
        }
        bookPtr(const bookPtr& copy)
        {
            std::cout << "copy constructor\n";
            bPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
        }
        bookPtr(bookPtr&& move) noexcept
        {
            std::cout << "move constructor\n";
            bPtr = move.bPtr;
            move.bPtr = nullptr;
        }

        bookPtr& operator=(const bookPtr& copy)
        {
            std::cout << "copy operator=\n";
            if (this != &copy)
            {
                delete bPtr;
                bPtr = copy.bPtr ? new book{*copy.bPtr} : nullptr;
            }
            return *this;
        }
        bookPtr& operator=(bookPtr&& move) noexcept
        {
            std::cout << "move operator=\n";
            if (this != &move)
            {
                delete bPtr;
                bPtr = move.bPtr;
                move.bPtr = nullptr;
            }
            return *this;
        }
    };
}