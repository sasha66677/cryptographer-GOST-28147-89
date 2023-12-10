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

#endif