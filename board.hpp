#pragma once
#include <boost/dynamic_bitset.hpp>
#include <iostream>
#include <random>

class board{
private:
    int width;
    int height;
    boost::dynamic_bitset<> current;
    boost::dynamic_bitset<> next;
public:
    board(int width, int height);
    void update_all();
    bool next_cell(int x, int y);
    void set_blinker();
    void set_random();
    bool set_cell(int x, int y);
    bool reset_cell(int x, int y);
    void cui_output();
};
