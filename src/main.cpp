#include "combiner.h"
#include "splitter.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        std::cout << "Usage:\n";
        std::cout << "  Split:   fsplit split <filename> <num_parts>\n";
        std::cout
            << "  Combine: fsplit combine <output_filename> <num_parts>\n";
        return 1;
    }

    std::string command = argv[1];
    std::string filename = argv[2];
    int parts = std::stoi(argv[3]);

    if (command == "split") {
        if (!splitFile(filename, parts)) {
            std::cerr << "File splitting failed!\n";
            return 1;
        }
    } else if (command == "combine") {
        if (!combineFiles(filename, parts)) {
            std::cerr << "File combining failed!\n";
            return 1;
        }
    } else {
        std::cerr << "Invalid command!\n";
        return 1;
    }

    return 0;
}
