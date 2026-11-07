#include <cstddef>

char* strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* strncpy(char* dest, const char* src, std::size_t n) {
    int i = 0;
    while (i != n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i != n) {
            dest[i] = '\0';
            i++;
    }        
    return dest;
}

void* memcpy(void* dest, const void* src, std::size_t n) {
    std::size_t i = 0;
    auto* d = static_cast<unsigned char*>(dest);
    auto* s = static_cast<const unsigned char*>(src);
     
    while (i != n) {
        d[i] = s[i];
        i++;
    }
    return dest;
}

int memcmp(const void* ptr1, const void* ptr2, std::size_t n) {
    int i = 0;
    auto* p1 = static_cast<const unsigned char*>(ptr1);
    auto* p2 = static_cast<const unsigned char*>(ptr2);

    while (i != n) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        } else {
            i++;
        }
    }
    return 0;
}
            
int strcmp (const char* str1, const char* str2) {
    int i = 0;    
    while (true) {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] == '\0') {
            return 0;
        }
        i++;
    }
} 

