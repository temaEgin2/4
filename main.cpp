#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
class TBook {
private:
    std::string Name;
    std::string Author;
    int Count;
public:
    TBook() {}
    TBook(const std::string& name, const std::string& author, int count) : Name(name), Author(author), Count(count) {}
    void setName(const std::string& name) { Name = name; }
    void setAuthor(const std::string& author) { Author = author; }
    void setCount(int count) { Count = count; }
    std::string getName() const { return Name; }
    std::string getAuthor() const { return Author; }
    int getCount() const { return Count; }
};

bool compareByAuthor(const TBook& a, const TBook& b) {
    return a.getAuthor() < b.getAuthor();
}
bool compareByName(const TBook& a, const TBook& b) {
    return a.getName() < b.getName();
}
int main() {
    std::vector<TBook> books;
    std::ifstream input("books.txt");
    if (input.is_open()) {
        std::string line;
        while (std::getline(input, line)) {
            std::stringstream ss(line);
            std::string name, author;
            int count;
            ss >> name >> author >> count;
            TBook book(name, author, count);
            books.push_back(book);
        }
        input.close();
        std::sort(books.begin(), books.end(), compareByAuthor);
        std::cout << "Sorted by author:" << std::endl;
        for (const auto& book : books) {
            std::cout << "Name: " << book.getName() << ", Author: " << book.getAuthor() << ", Count: " << book.getCount() << std::endl;
        }
        std::cout << std::endl;
        std::sort(books.begin(), books.end(), compareByName);
        std::cout << "Sorted by name:" << std::endl;
        for (const auto& book : books) {
            std::cout << "Name: " << book.getName() << ", Author: " << book.getAuthor() << ", Count: " << book.getCount() << std::endl;
        }
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }
    return 0;
}
