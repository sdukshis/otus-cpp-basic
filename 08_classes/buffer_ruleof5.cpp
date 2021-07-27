// OTUS C++ basic course example of buffer with destructor

#include <cstddef>
#include <iostream>
#include <fstream>
#include <algorithm>

class buffer {
  private:
    std::size_t size_;
    char *data_;

  public:
    buffer(); // default constructor

    buffer(std::size_t size);

    buffer(const buffer &other); // copy constructor

    buffer & operator=(const buffer &other); // copy assignment

    ~buffer(); // destructor

    buffer(buffer &&other) = delete; //move constructor

    buffer & operator=(buffer &&other) = delete; // move assignment

    void resize(std::size_t size);

    char *data() const { return data_; }

    std::size_t size() const { return size_; }

    void free();
};

buffer::buffer()
    : size_(0)
    , data_(nullptr) {}

buffer::buffer(size_t size)
    : size_(size)
    , data_(new char[size_]) {}

buffer & buffer::operator=(const buffer &other) {
    if (this == &other) {
        return *this;
    }
    resize(other.size_);
    std::copy_n(other.data_, size_, data_);
    return *this;
}

buffer::~buffer() {
    delete[] data_;
}

void buffer::resize(std::size_t size) {
    char *new_data = new char[size];
    free();
    data_ = new_data;
    size_ = size;
}

void buffer::free() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
}

void process(const buffer&, const buffer &) {}

bool read_and_process(std::istream &in) {
    const size_t header_size = 256;
    buffer header(header_size);
    if (!in.read(header.data(), header.size())) {
        std::cerr << "Error on reading header data\n";
        return false;    
    }
    
    const size_t body_size = 4096;
    buffer body(body_size);
    if (!in.read(body.data(), body.size())) {
        std::cerr << "Error on reading body data\n";
        return false;
    }

    process(header, body);
    return true;
}

int main() {
    return 0;
    std::ifstream file("data.dat");
    if (!read_and_process(file)) {
        std::cerr << "Error read_and_prcess\n";
        return EXIT_FAILURE;
    }
}