#include "BookShelfEntry.h"

BookShelfEntry::BookShelfEntry(const Book& book) : m_book(book)
{
}

auto BookShelfEntry::operator==(const BookShelfEntry& book) const -> bool
{
    return m_book == book.GetBook() &&
           m_borrowed == book.IsBorrowed() &&
           m_borrower == book.GetBorrower();
}

auto operator<<(std::ostream& os, const BookShelfEntry& book) -> std::ostream&
{
    os << book.GetBook();
    os << "Borrowed: " << (book.IsBorrowed() ? "Yes" : "No") << std::endl;
    
    if( book.IsBorrowed())
    {
        os << "Borrowed by: " << book.GetBorrower() << std::endl;
    }

    return os;
}

auto BookShelfEntry::GetBook() const -> Book
{
    return m_book;
}

auto BookShelfEntry::IsBorrowed() const -> bool
{
    return m_borrowed;
}

auto BookShelfEntry::SetBorrowed(bool isBorrowed) -> void
{
    m_borrowed = isBorrowed;
}

auto BookShelfEntry::GetBorrower() const -> std::string
{
    return m_borrower;
}

auto BookShelfEntry::SetBorrower(std::string borrower) -> void
{
    m_borrower = borrower;
}
