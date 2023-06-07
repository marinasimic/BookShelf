#pragma once

#include <vector>

#include "Book.h"

class BookShelf
{
    private:
        /**
         * \brief Vector of pairs - book and the name of the person borrowed it
         * \note Empty string means book is available
         * \todo Think of a better way to store books
        */
        std::vector<std::pair<Book, std::string>> m_books{};

    public:
        BookShelf() = default;

        auto AddBook(const Book& book) -> bool;
        auto RemoveBook(const Book& book) -> bool;
        auto BorrowBook(const Book& book) -> bool;
        auto ReturnBook(const Book& book) -> bool;
        auto BookExists(const Book& book) -> bool;

        auto GetAllBooks() const -> std::vector<Book>;
        auto GetAllAvailableBooks() const  -> std::vector<Book>;
        auto GetBooksByAuthor(const std::string author) const -> std::vector<Book>;
        auto GetBooksByGenre(const std::string genre) const -> std::vector<Book>;
};