#include <iostream>
#include <string>
#include <vector>

class Book {
public:
  std::string name;

  Book(const std::string &bookName) : name(bookName) {}
};

class Library {
public:
  void addBook(const std::string &bookName) {
    books.push_back(Book(bookName));
    std::cout << "Added book: " << bookName << std::endl;
  }

  void removeBook(const std::string &bookName) {
    for (auto it = books.begin(); it != books.end(); ++it) {
      if (it->name == bookName) {
        books.erase(it);
        std::cout << "Removed book: " << bookName << std::endl;
        return;
      }
    }
    std::cout << "Book not found: " << bookName << std::endl;
  }

  void displayBooks() {
    if (books.empty()) {
      std::cout << "The library is empty." << std::endl;
      return;
    }
    std::cout << "Library inventory:" << std::endl;
    for (const auto &book : books) {
      std::cout << "- " << book.name << std::endl;
    }
  }

private:
  std::vector<Book> books;
};
