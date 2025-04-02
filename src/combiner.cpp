#include "combiner.h"
#include <fstream>
#include <iostream>
#include <vector>

bool combineFiles(const std::string &outputFile, int parts) {
    std::ofstream out(outputFile, std::ios::binary);
    if (!out) {
        std::cerr << "Error: Could not create output file!\n";
        return false;
    }

    std::vector<char> buffer;
    for (int i = 0; i < parts; ++i) {
        std::ifstream in(outputFile + "_part_" + std::to_string(i + 1),
                         std::ios::binary);
        if (!in) {
            std::cerr << "Error: Could not open file part!\n";
            return false;
        }

        in.seekg(0, std::ios::end);
        std::streamsize size = in.tellg();
        in.seekg(0, std::ios::beg);

        buffer.resize(size);
        in.read(buffer.data(), size);
        out.write(buffer.data(), size);
    }

    std::cout << "Files combined successfully into " << outputFile << "!\n";
    return true;
}
