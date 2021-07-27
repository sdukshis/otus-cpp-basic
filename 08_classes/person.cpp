// OTUS C++ Basic course inveritance example

#include <iostream>
#include <string>

class Person {
private:
    std::string firstname_;
    std::string lastname_;
public:
    Person(const std::string &firstname, const std::string &lastname)
        : firstname_(firstname)
        , lastname_(lastname)
    {}

    std::string firstname() const { return firstname_; }

    std::string lastname() const {return lastname_; }

    friend void print(std::ostream &out, const Person &person);
};

void print(std::ostream &out, const Person &person) {
    out << person.firstname_ << ' ' << person.lastname_ << '\n';
}

class Student: public Person {
private:
    int course_;

public:
    Student(const std::string &firstname, const std::string &lastname, int course)
        : Person(firstname, lastname)
        , course_(course)
    {}

    int course() const { return course_; }
};

int main() {
    Person person("John", "Smith");
    print(std::cout, person);

    Student student("Mary", "Jane", 1);
    print(std::cout, student);
}