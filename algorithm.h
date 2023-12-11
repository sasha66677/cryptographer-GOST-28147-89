#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "debugging.h"

uint8_t sBox[8][16];



/**
* number of first part
* rebuild first and second halfs of byte
* /____/  /____/ -- byte
* number number+1
*/
uint8_t substitute(uint8_t byte, uint8_t number) {
    uint8_t col = byte >> 4;
    uint8_t new_byte = sBox[number][col] << 4;
    col = byte & 0xF;
    new_byte += sBox[number + 1][col];
    return new_byte;
}

uint32_t substitute(uint32_t val) {
#ifdef DEBUG1
    std::cout << "\n\nsubstitute\nval\n";
    output_bin(val);
#endif // DEBUG1

    uint32_t new_val = 0;
    uint8_t temp;
    for (int i = 0; i < 8; i += 2) {
        temp = val >> (24 - i * 4);
        temp = substitute(temp, i);
        new_val += uint32_t(temp) << (24 - i * 4);
    }
#ifdef DEBUG1
    std::cout << "\nnew val\n";
    output_bin(new_val);
#endif // DEBUG1

    return new_val;
}

uint64_t main_iteration(uint64_t val, uint32_t key) {
    uint32_t first_part = val >> 32;
    uint32_t second_part = val;
#ifdef DEBUG
    std::cout << "\n\n\nmain_iteration\nfirst_part, second part, key \n";
    output_bin(first_part);
    std::cout << std::endl;
    output_bin(second_part);
    std::cout << std::endl;
    output_bin(key);
    std::cout << std::endl;
#endif // DEBUG

    uint32_t sum = (static_cast<uint64_t>(second_part) + static_cast<uint64_t>(key));

#ifdef DEBUG
    std::cout << "\nstep 1: sum\n";
    output_bin(sum);
#endif // DEBUG


    uint32_t substituted = substitute(sum);

#ifdef DEBUG
    std::cout << "\nstep 2: substituted\n";
    output_bin(substituted);
#endif // DEBUG

    uint32_t shifted = substituted << 11;

#ifdef DEBUG
    std::cout << "\nstep 3: shifted\n";
    output_bin(shifted);
#endif // DEBUG

    uint32_t xored = shifted ^ first_part;

#ifdef DEBUG
    std::cout << "\nstep 4: shifted XOR first part\n";
    output_bin(xored);
#endif // DEBUG

    uint64_t result = (uint64_t(second_part) << 32) + xored;

#ifdef DEBUG
    std::cout << "\nstep 5: swap F and first part\n";
    output_bin(result);
#endif // DEBUG

    return result;
}

/**encryption cycle 32-3 for one block
*/
uint64_t simple_replacement(uint64_t block, uint32_t key[]) {
#ifdef DEBUG
    std::cout << "\n=======================================\nencrypt\nblock, key \n";
    output_bin(block);
    std::cout << std::endl;
    for (int i = 0; i < 8; ++i) {
        output_bin(key[i]);
        std::cout << ' ';
    }
    std::cout << std::endl;
#endif // DEBUG

    for (int k = 0; k < 3; ++k)
        for (int i = 0; i < 8; ++i) {
            block = main_iteration(block, key[i]);
        }

    for (int i = 7; i >= 0; --i) {
        block = main_iteration(block, key[i]);
    }
    uint32_t first_part = block >> 32;
    uint32_t secod_part = block;

    uint64_t result = (uint64_t(secod_part) << 32) + first_part;

#ifdef DEBUG
    std::cout << "\nresult\n";
    output_bin(result);
    std::cout << "\n=======================================\n";
#endif // DEBUG

    return result;
}

/**encryption cycle 32-3 for message
*/
std::string simple_replacement(std::string message, uint32_t key[]) {
    while (message.size() % 8 != 0)
        message.push_back('\0');
    std::string result{ "" };
    uint64_t temp;
    char ch;
    for (int i = 0; i + 7 < message.size(); i += 8) {
        temp = 0;
        for (int j = 0; j < 8; ++j) {
            temp <<= 8;
            temp += static_cast<uint8_t> (message[i + j]);
        }

        uint64_t encr = simple_replacement(temp, key);
        for (int j = 7; j >= 0; --j) {
            ch = static_cast<char>(encr >> 8 * j);
            result.push_back(ch);
        }
    }
    return result;
}




#endif