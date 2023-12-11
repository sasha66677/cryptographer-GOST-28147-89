#ifndef DEBUGGING_H
#define DEBUGGING_H

//#define DEBUG
//#define DEBUG1

template <class T>
void output_bin(T val) {
    bool* arr = new bool[sizeof(val) * 8];
    std::memset(arr, 0, sizeof(val) * 8);

    for (int i = sizeof(val) * 8 - 1; i >= 0; --i) {
        arr[i] = val & 0x1;
        val >>= 1;
    }

    for (int i = 0; i < sizeof(val) * 8; ++i) {
        if (i % 4 == 0)
            std::cout << ' ';
        std::cout << arr[i];
    }

    delete[] arr;
}
#endif // !DEBUGGING_H
