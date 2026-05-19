#include <iostream>
#include <utility>

class File {
    FILE* handle;
    
public:
    explicit File(const char* path, const char* mode) {
        handle = fopen(path, mode);
        if (!handle) {
            throw std::runtime_error(std::string("cannot open: ") + path);
        }
    }
    
    ~File() {
        if (handle) {
            fclose(handle);
        }
        std::cout << "file closed" << std::endl;
    }
    
    File(const File&) = delete;
    File& operator=(const File&) = delete;
    
    File(File&& other) noexcept 
        : handle(std::exchange(other.handle, nullptr))
    {}
    
    File& operator=(File&& other) noexcept {
        if (this != &other) {
            if (handle) {
                fclose(handle);
            }
        }
        return *this;
    }
    
    FILE* get() const {
        return handle;
    }
    
    void write(const char* msg) {
        fputs(msg, handle);
    }
    
    std::string read_line() {
        char buf[256]; // character buffer
        if (!fgets(buf, sizeof(buf), handle)) {
            return {}; // returns nothing
        }
        return buf; // std::string constructor called
    }
};

    
int main() {
    try {
        File f("test.txt", "w");
        f.write("hello RAII\n");
        // File bad("/root/no_permission.txt", "w");
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << "\n";
    }
}
    
