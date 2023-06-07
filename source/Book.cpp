#include "Book.h"

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

auto Book::IsBorrowed() const -> bool
{
    return m_isBorrowed;
}

auto Book::SetBorrowed(bool isBorrowed) -> void
{
    m_isBorrowed = isBorrowed;
}