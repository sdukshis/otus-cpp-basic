// OTUS C++ basic course example of buffer without destructor

#include <cstddef>
#include <iostream>
#include <fstream>

class buffer {
  private:
    std::size_t size_;
    char *data_;

  public:
    buffer();

    explicit buffer(std::size_t size);

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

void buffer::resize(std::size_t size) {
    free();
    data_ = new char[size];
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
        header.free();
        return false;    
    }
    
    const size_t body_size = 4096;
    buffer body(body_size);
    if (!in.read(body.data(), body.size())) {
        std::cerr << "Error on reading body data\n";
        body.free();
        return false;
    }

    process(header, body);

    header.free();
    body.free();
    return true;
}

int main() {
    std::ifstream file("data.dat", std::ios::binary);
    if (!read_and_process(file)) {
        std::cerr << "Error read_and_prcess\n";
        return EXIT_FAILURE;
    }
}