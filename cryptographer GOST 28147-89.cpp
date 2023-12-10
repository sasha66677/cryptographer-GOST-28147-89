#include <iostream>
#include "file_services.h"
int main()
{
    uint32_t key[8];
    read_from_file<uint32_t, 8>("key.txt", key);
    
    std::cout << "Key:\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << key[i] << '\t';
    }

    uint8_t sBox[8][16];
    read_from_file<uint8_t, 8, 16>("sBox.txt", sBox);
   
    std::cout << "\n\nsBox:\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 16; ++j) {
            std::cout << (int)sBox[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    std::string message;
    read_from_file("message.txt", message);

    std::cout << "\n\nMessage:\n" << message;
}

