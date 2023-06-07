#pragma once

#include <string>

class Book
{
    private:
        std::string m_title{};
        std::string m_author{};
        std::string m_isbn{};
        bool m_isBorrowed{false};
    
    public:
        Book() = default;

        auto GetTitle() const -> std::string;
        auto SetTitle(const std::string& title) -> void;

        auto GetAuthor() const -> std::string;
        auto SetAuthor(const std::string& author) -> void;

        auto GetISBN() const -> std::string;
        auto SetISBN(const std::string& isbn) -> void;

        auto IsBorrowed() const -> bool;
        auto SetBorrowed(bool isBorrowed) -> void;
};