#include "Book.h"

auto Book::operator==(const Book& book) const -> bool
{
    return m_title == book.GetTitle() &&
           m_author == book.GetAuthor() &&
           m_isbn == book.GetISBN() &&
           m_genre == book.GetGenre();
}

auto Book::GetTitle() const -> std::string
{
    return m_title;
}

auto Book::SetTitle(const std::string& title) -> void
{
    m_title = title;
}

auto Book::GetAuthor() const -> std::string
{
    return m_author;
}

auto Book::SetAuthor(const std::string& author) -> void
{
    m_author = author;
}

auto Book::GetISBN() const -> std::string
{
    return m_isbn;
}

auto Book::SetISBN(const std::string& isbn) -> void
{
    m_isbn = isbn;
}

auto Book::GetGenre() const -> std::string
{
    return m_genre;
}

auto Book::SetGenre(const std::string& genre) -> void
{
    m_genre = genre;
}