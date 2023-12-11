#include <iostream>
#include "file_services.h"
#include "algorithm.h"
#include "debugging.h"

int main()
{
    uint32_t key[8];
    read_from_file<uint32_t, 8>("key.txt", key);
    read_from_file<uint8_t, 8, 16>("sBox.txt", sBox);
    std::string message;
    read_from_file("message.txt", message);

    uint64_t* first_s = new uint64_t;
    read_from_file<uint64_t, 1>("first_s.txt", first_s);

    std::cout << "\n\nMessage:\n" << message;

    auto cifer = simple_replacement_encrypt(message, key);
    std::cout << "\n\nAfter encrypting:\n" << cifer;
    std::cout << "\n\nAfter decrypting:\n" << simple_replacement_decrypt(cifer, key);

    auto cifer1 = gamma_encrypt(message, key, *first_s);
    std::cout << "\n\ngamma:\n" << cifer1 << '\n';
    std::cout << "\n\ndegamma:\n" << gamma_encrypt(cifer1, key, *first_s) << '\n';


    std::cout << "\n\Message Authentication Code:\n";
    output_bin(makeMAC(cifer1, key));
    
    delete first_s;
}

