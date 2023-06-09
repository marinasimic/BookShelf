#include <iostream>

#include "BookShelf.h"

int main()
{
    uint16_t option;
    BookShelf bookshelf;

    do
    {
        std::cout << "Hello!" << std::endl;
        std::cout << "Welcome to the BookShelf!" << std::endl << std::endl;
        std::cout << "Enter the number of the command:" << std::endl;
        std::cout << "1) Add new book to the bookshelf" << std::endl;
        std::cout << "2) See all books on the bookshelf" << std::endl;
        std::cout << "3) Remove book from the bookshelf" << std::endl;
        std::cout << "4) Borrow the book from the bookshelf" << std::endl;
        std::cout << "5) Edit the book from the bookshelf" << std::endl;
        std::cout << "0) Leave the BookShelf" << std::endl;

        std::cin >> option;

        if (option > 5)
        {
            std::cout << "Invalid option! Try again" << std::endl << std::endl;
            continue;
        }
    } while(option != 0);

    
    std::cout << "Goodbye!" << std::endl;

    return 0;
}