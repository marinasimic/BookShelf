#include <iostream>
#include <map>

#include "BookShelf.h"

auto AddBook(BookShelf& bookshelf) -> bool
{
    std::string title, author, isbn, genre;

    std::cout << "Title: ";
    std::cin >> title;
    std::cout << "Author: ";
    std::cin >> author;
    std::cout << "ISBN: ";
    std::cin >> isbn;
    std::cout << "Genre: ";
    std::cin >> genre;

    BookShelfEntry entry(Book(title, author, isbn, genre));

    bookshelf.AddBook(entry);
    return true;
}

auto SeeAllBooks(BookShelf& bookshelf) -> bool
{
    auto books = bookshelf.GetAllBooks();

    for (auto book: books)
    {
        std::cout << book << std::endl;
    }

    if (books.empty())
    {
        std::cout << "You have no books on your bookshelf!" << std::endl;
    }

    return true;
}

auto RemoveBook(BookShelf& bookshelf) -> bool
{
    auto books = bookshelf.GetAllBooks();
    for (auto count = 0; count < books.size(); count++)
    {
        std::cout << count << ") " << books[count].GetBook().GetTitle() << " " << books[count].GetBook().GetAuthor() << std::endl;
        count++;
    }

    int bookNr = 0;

    std::cout << "Enter the number of a book you want to remove: ";
    std::cin >> bookNr;

    if (bookNr < 0 || bookNr >= books.size())
    {
        std::cout << "Invalid book number!" << std::endl;
        return false;
    }

    return bookshelf.RemoveBook(books[bookNr]);
}

auto BorrowBook(BookShelf& bookshelf) -> bool
{
    auto books = bookshelf.GetAvailableBooks();
    for (auto count = 0; count < books.size(); count++)
    {
        std::cout << count << ") " << books[count].GetBook().GetTitle() << " " << books[count].GetBook().GetAuthor() << std::endl;
        count++;
    }

    int bookNr = 0;

    std::cout << "Enter the number of a book you want to borrow: ";
    std::cin >> bookNr;

    if (bookNr < 0 || bookNr >= books.size())
    {
        std::cout << "Invalid book number!" << std::endl;
        return false;
    }
    
    std::string borrower;

    std::cout << "Enter the name of the borrower: ";
    std::cin >> borrower;

    return bookshelf.BorrowBook(books[bookNr], borrower);
}

int main()
{
    uint16_t option;
    BookShelf bookshelf;

    std::map<uint16_t, bool (*)(BookShelf&)> actions = {{1, AddBook},
                                                        {2, SeeAllBooks},
                                                        {3, RemoveBook},
                                                        {4, BorrowBook}};

                                                    
    std::cout << "Hello!" << std::endl;
    std::cout << "Welcome to the BookShelf!" << std::endl;

    do
    {
        std::cout << std::endl;
        std::cout << "Enter the number of the command:" << std::endl;
        std::cout << "\t1) Add new book to the bookshelf" << std::endl;
        std::cout << "\t2) See all books on the bookshelf" << std::endl;
        std::cout << "\t3) Remove book from the bookshelf" << std::endl;
        std::cout << "\t4) Borrow the book from the bookshelf" << std::endl;
        std::cout << "\t5) Edit the book from the bookshelf" << std::endl;
        std::cout << "\t0) Leave the BookShelf" << std::endl;

        std::cin >> option;

        if (option > 5)
        {
            std::cout << "Invalid option! Try again" << std::endl << std::endl;
            continue;
        }

        if(option <= 0)
        {
            break;
        }

        if( !actions[option](bookshelf))
        {
            std::cout << "Action failed!" << std::endl;
        }
    } while(option != 0);

    
    std::cout << "Goodbye!" << std::endl;

    return 0;
}