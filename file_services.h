#ifndef FILE_SERVICES_H
#define FILE_SERVICES_H

#include <sstream>
#include <fstream>
#include <iostream>

template<typename T, int cols>
bool read_from_file(const std::string& filename, T array[cols]) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return false;
    }

    T value;
    int count = 0;
    while (count < cols && file >> value) {
        array[count] = value;
        ++count;
    }

    file.close();
    return true;
}

template<typename T, int rows, int cols>
bool read_from_file(const std::string& filename, T arr[rows][cols]) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return false;
    }

    std::string line;
    for (int i = 0; i < rows; ++i) {
        std::getline(file, line);
        std::istringstream iss(line);
        for (int j = 0; j < cols; ++j) {
            int val;
            if (!(iss >> val)) {
                std::cerr << "Error reading array from file " << filename << std::endl;
                file.close();
                return false;
            }
            arr[i][j] = static_cast<T>(val);
        }
    }

    file.close();
    return true;
}

bool read_from_file(const std::string& filename, std::string& str) {
    std::ifstream file(filename);

    if (file.is_open()) {
        char ch;
        while (file.get(ch) && !file.eof()) {
            str += ch;
        }
        file.close();
    }
    else {
        std::cerr << "Error reading string from file " << filename << std::endl;
        return 0;
    }

    return 1;
}

bool writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);

    if (file.is_open()) {
        file << content;
        file.close();
        return 1;
    }
    else {
        std::cerr << "Unable to open file " << filename << " for writing." << std::endl;
    }
    return 0;
}

#endif