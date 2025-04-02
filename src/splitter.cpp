#include "splitter.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

FileSplitter::FileSplitter(const string &inputFile, int parts)
    : inputFile(inputFile), parts(parts) {}

bool FileSplitter::split() {
    ifstream in(inputFile, ios::binary); // Open file for reading
    if (!in) {
        cerr << "Error: Could not open input file!" << endl;
        return false;
    }

    // Find file size
    in.seekg(0, ios::end);
    streamsize fileSize = in.tellg();
    in.seekg(0, ios::beg);

    // Calculate part sizes
    streamsize partSize = fileSize / parts;
    streamsize lastPartSize = fileSize - (partSize * (parts - 1));

    vector<char> buffer(partSize); // Buffer to store file data

    // Split file into parts
    for (int i = 0; i < parts; ++i) {
        string partFile = inputFile + "_part_" + to_string(i + 1);
        ofstream out(partFile, ios::binary); // Create part file

        if (!out) {
            cerr << "Error: Could not create output file part!" << endl;
            return false;
        }

        streamsize currentSize = (i == parts - 1) ? lastPartSize : partSize;
        buffer.resize(currentSize); // Resize buffer to match part size

        in.read(buffer.data(), currentSize);   // Read part from file
        out.write(buffer.data(), currentSize); // Write part to new file
    }

    cout << "File split into " << parts << " parts successfully!" << endl;
    return true;
}
