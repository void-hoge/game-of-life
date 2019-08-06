#include "board.hpp"

board::board(int w, int h){
    width = w;
    height = h;
    int size = (width+2)*(height+2);
    current.resize(size);
    next.resize(size);
}

bool board::next_cell(int x, int y){
    x++;
    y++;
    //count cell around x,y;
    int alive = 0;
    if (current[(x-1)*(height+2)+(y-1)]) {
        alive++;
    }
    if (current[(x*(height+2)+(y-1))]) {
        alive++;
    }
    if (current[(x+1)*(height+2)+(y-1)]) {
        alive++;
    }
    if (current[(x-1)*(height+2)+y]) {
        alive++;
    }
    if (current[(x+1)*(height+2)+y]) {
        alive++;
    }
    if (current[(x-1)*(height+2)+(y+1)]) {
        alive++;
    }
    if (current[x*(height+2)+(y+1)]) {
        alive++;
    }
    if (current[(x+1)*(height+2)+(y+1)]) {
        alive++;
    }

    //evaluate
    if (alive == 3) {
        return true;
    }
    if (alive == 2) {
        return current[x*(height+2)+y];
    }
    if (alive<=1) {
        return false;
    }
    if (alive>=4) {
        return false;
    }
    return false;
}

void board::update_all(){
    next.clear();
    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < height; j++) {
            next[(i+1)*(height+2)+(j+1)] = next_cell(i, j);
        }
    }
    for (size_t i = 0; i < current.size(); i++) {
        current[i] = next[i];
    }
    return;
}

void board::set_blinker(){
    current[(3+1)*(height+2)+(2+1)] = true;
    current[(3+1)*(height+2)+(3+1)] = true;
    current[(3+1)*(height+2)+(4+1)] = true;
}

void board::set_random(){
    std::mt19937 mt((int)time(0));
    for (size_t i = 1; i < width+1; i++) {
        for (size_t j = 1; j < height+1; j++) {
            current[i*(height+2)+j] = (bool)(mt()&1);
        }
    }
}

bool board::set_cell(int x, int y){
    if ((x < 0) || (x > height)) {
        return false;
    }
    if ((y < 0) || (y > width)) {
        return false;
    }
    current[x*(height+2)+ (y+1)] = true;
    return true;
}

bool board::reset_cell(int x, int y){
    if ((x < 0) || (x > height)) {
        return false;
    }
    if ((y < 0) || (y > width)) {
        return false;
    }
    current[(x+1)*(height+2)+(y+1)] = false;
    return true;
}

void board::cui_output(){
    for (size_t i = 0; i < width+2; i++) {
        for (size_t j = 0; j < height+2; j++) {
            if (current[i*(height+2)+j]) {
                std::cout << "■";
            }else{
                std::cout << " ";
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
