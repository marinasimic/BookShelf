#include "BookShelf.h"

auto BookShelf::AddBook(const Book& book) -> bool
{
    return false;
}

auto BookShelf::RemoveBook(const Book& book) -> bool
{
    return false;
}

auto BookShelf::BorrowBook(const Book& book) -> bool
{
    return false;
}

auto BookShelf::ReturnBook(const Book& book) -> bool
{
    return false;
}

auto BookShelf::BookExists(const Book& book) -> bool
{
    return false;
}

auto BookShelf::GetAllBooks() const -> std::vector<Book>
{
    return std::vector<Book>();
}

auto BookShelf::GetAllAvailableBooks() const -> std::vector<Book>
{
    return std::vector<Book>();
}

auto BookShelf::GetBooksByAuthor(const std::string author) const -> std::vector<Book>
{
    return std::vector<Book>();
}

auto BookShelf::GetBooksByGenre(const std::string genre) const -> std::vector<Book>
{
    return std::vector<Book>();
}
