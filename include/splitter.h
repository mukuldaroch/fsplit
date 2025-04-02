#ifndef SPLITTER_H
#define SPLITTER_H

#include <string>

class FileSplitter {
  public:
    FileSplitter(const std::string &inputFile, int parts);
    bool split(); // Method to split the file

  private:
    std::string inputFile;
    int parts;
};

#endif // SPLITTER_H
