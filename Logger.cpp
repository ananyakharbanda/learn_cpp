#include <iostream>
#include <fstream>
    
class Logger {
    std::string filename;
    std::FILE* file;
    
public:
    Logger(const std::string& fname) : filename{fname} {
        file = std::fopen(fname.c_str(), "w");
        if (!file) throw std::runtime_error("cannot open " + fname);
        std::cout << "logger opened: " << fname << std::endl;
    }
    
    void log(const std::string& msg) {
        std::fputs(msg.c_str(), file);
    }
    
    ~Logger() {
        if (file) {
            std::fclose(file);
            std::cout << "logger closed: " << filename << std::endl;
        }
    }
};
    
int main() {
    Logger l{"/home/ananya/hellologger.txt"};
    l.log("hello logger");
    // (*l).log("bad logging using object dereferencing");
    // l->~Logger();
    return 0;
}
    
