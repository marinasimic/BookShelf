#pragma once

#include "Book.h"

#include <string>

class BookShelfEntry
{
private:
    Book m_book;
    bool m_borrowed{false};
    std::string m_borrower;
public:
    BookShelfEntry(const Book& bse);

    auto operator==(const BookShelfEntry& book) const -> bool;
    friend auto operator<<(std::ostream& os, const BookShelfEntry& book) -> std::ostream&;

    auto GetBook() const -> Book;

    auto IsBorrowed() const -> bool;
    auto SetBorrowed(bool isBorrowed) -> void;

    auto GetBorrower() const -> std::string;
    auto SetBorrower(std::string borrower) -> void;
};
