#pragma once

#include <list>
#include <vector>

#include "BookShelfEntry.h"

class BookShelf
{
private:
    std::list<BookShelfEntry> m_books{};

    auto ChangeBorrowedStatus(const BookShelfEntry &book, bool status, std::string borrower = "") -> bool;

public:
    auto AddBook(const BookShelfEntry &book) -> void;
    auto RemoveBook(const BookShelfEntry &book) -> bool;
    auto BorrowBook(const BookShelfEntry &book, const std::string borrower) -> bool;
    auto ReturnBook(const BookShelfEntry &book) -> bool;
    auto BookExists(const BookShelfEntry &book) const -> bool;

    auto GetAllBooks() const -> std::vector<BookShelfEntry>;
    auto GetAvailableBooks() const -> std::vector<BookShelfEntry>;
    auto GetBorrowedBooks() const -> std::vector<BookShelfEntry>;
    auto GetBooksByAuthor(const std::string author) const -> std::vector<BookShelfEntry>;
    auto GetBooksByGenre(const std::string genre) const -> std::vector<BookShelfEntry>;
};