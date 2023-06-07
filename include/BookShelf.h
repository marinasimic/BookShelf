#pragma once

#include <vector>

#include "Book.h"

class BookShelf
{
    private:
        std::vector<Book> m_books{};

    public:
        BookShelf() = default;

};