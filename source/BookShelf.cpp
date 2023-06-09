#include "BookShelf.h"

#include <algorithm>

auto BookShelf::AddBook(const BookShelfEntry& book) -> void
{
    m_books.push_back(book);
}

auto BookShelf::RemoveBook(const BookShelfEntry& book) -> bool
{
    if (!BookExists(book))
    {
        return false;
    }

    m_books.remove(book);
    
    return true;
}

auto BookShelf::BorrowBook(const BookShelfEntry& book, const std::string borrower) -> bool
{
    return ChangeBorrowedStatus(book, true, borrower);
}

auto BookShelf::ReturnBook(const BookShelfEntry& book) -> bool
{
    return ChangeBorrowedStatus(book, false);
}

auto BookShelf::BookExists(const BookShelfEntry& book) const -> bool
{
    return std::find(m_books.begin(), m_books.end(), book) != std::end(m_books);
}

auto BookShelf::GetAllBooks() const -> std::vector<BookShelfEntry>
{
    return std::vector<BookShelfEntry>(m_books.begin(), m_books.end());
}

auto BookShelf::GetAvailableBooks() const -> std::vector<BookShelfEntry>
{
    auto isBookAvailable = [](const BookShelfEntry& book) {
        return !book.IsBorrowed();
    };

    std::vector<BookShelfEntry> books{};
    std::copy_if(m_books.begin(), m_books.end(), std::back_inserter(books), isBookAvailable);

    return books;
}

auto BookShelf::GetBorrowedBooks() const -> std::vector<BookShelfEntry>
{
    auto isBookBorrowed = [](const BookShelfEntry& book) {
        return book.IsBorrowed();
    };

    std::vector<BookShelfEntry> books{};
    std::copy_if(m_books.begin(), m_books.end(), std::back_inserter(books), isBookBorrowed);

    return books;
}

auto BookShelf::GetBooksByAuthor(const std::string author) const -> std::vector<BookShelfEntry>
{
    auto isBookByAuthor = [&author](const BookShelfEntry& book) {
        return book.GetBook().GetAuthor() == author;
    };

    std::vector<BookShelfEntry> books{};
    std::copy_if(m_books.begin(), m_books.end(), std::back_inserter(books), isBookByAuthor);

    return books;
}

auto BookShelf::GetBooksByGenre(const std::string genre) const -> std::vector<BookShelfEntry>
{
    auto isBookOfGenre = [&genre](const BookShelfEntry& book) {
        return book.GetBook().GetGenre() == genre;
    };

    std::vector<BookShelfEntry> books{};
    std::copy_if(m_books.begin(), m_books.end(), std::back_inserter(books), isBookOfGenre);

    return books;
}

auto BookShelf::ChangeBorrowedStatus(const BookShelfEntry& book, bool status, std::string borrower) -> bool
{
    if (!BookExists(book))
    {
        return false;
    }

    bool changed = false;
    
    // use algorithm for this
    for (auto& b: m_books)
    {
        if(b == book)
        {
            b.SetBorrowed(status);
            
            if (status)
            {
                b.SetBorrower(borrower);
            }

            changed = true;
            break;
        }
    }

    return changed;
}