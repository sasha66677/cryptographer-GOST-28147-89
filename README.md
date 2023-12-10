# cryptographer GOST 28147-89
Cryptographic algorithm that uses GOST 28147-89. Can encrypt information in 64-bit blocks using a 128-bit key and a replacement table.

key.txt - file for key in format:
/uint32_t/ /uint32_t/ /uint32_t/ /uint32_t/ /uint32_t/ /uint32_t/ /uint32_t/ /uint32_t/

sBox.txt - file for s matrix in format:
/uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ 
/uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ 
/uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ 
/uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ 
/uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ 
/uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ 
/uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ 
/uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ /uint8_t/ 

message.txt - file with text of message