#include "board.hpp"
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
const int width = 15;
const int height = 15;

int main(int argc, char const *argv[]) {
    board bd(width, height);

    //input from file
    std::string filename = argv[1];
    std::ifstream reading_file;
    reading_file.open(filename, std::ios::in);
    std::string reading_line_buffer;
    std::cout << "reading " << filename << "....\n";
    for (int i = 0; !reading_file.eof(); i++) {
        std::getline(reading_file, reading_line_buffer);
        for (size_t j = 0; j < reading_line_buffer.size(); j++) {
            switch (reading_line_buffer[j]) {
                case '0':
                    // std::cout << "reset_cell" << '\n';
                    bd.reset_cell(i, j);
                    break;
                case '1':
                    // std::cout << "set_cell" << '\n';
                    bd.set_cell(i,j);
                    break;
                default:
                    break;
            }
        }
    }

    // bd.set_random();

    std::chrono::milliseconds wait(100);
    for (size_t i = 0; i <= 128; i++) {
        std::cout << "generation: " << i << '\n';
        bd.cui_output();
        bd.update_all();
        std::this_thread::sleep_for(wait);
    }
    return 0;
}
