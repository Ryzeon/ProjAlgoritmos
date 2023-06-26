#pragma once

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

namespace utils {
    class FileUtils {
    public:
        static void write(string path, string content) {
            ofstream file;
            file.open(path);
            file << content;
            file.close();
        }

        static void write_lines(string path, vector<string> lines) {
            ofstream file;
            file.open(path);
            for (string s : lines) {
                file << s << endl;
            }
            file.close();
        }

        static vector<string> read(string path) {
            ifstream file;
            vector<string> content;
            file.open(path);
            string line;
            while (getline(file, line)) {
                content.push_back(line);
            }
            file.close();
            return content;
        }

    };
};
