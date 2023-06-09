#pragma once

#include <string>
#include <ostream>

class Book
{
private:
    std::string m_title{};
    std::string m_author{};
    std::string m_isbn{};
    std::string m_genre{};

public:
    Book() = default;
    Book(const std::string &title, const std::string &author, const std::string &isbn, const std::string &genre);
    auto operator==(const Book &book) const -> bool;
    friend auto operator<<(std::ostream &os, const Book &book) -> std::ostream &;

    auto GetTitle() const -> std::string;
    auto SetTitle(const std::string &title) -> void;

    auto GetAuthor() const -> std::string;
    auto SetAuthor(const std::string &author) -> void;

    auto GetISBN() const -> std::string;
    auto SetISBN(const std::string &isbn) -> void;

    auto GetGenre() const -> std::string;
    auto SetGenre(const std::string &genre) -> void;
};