#pragma once
class Counter {
private:
    int number;
public:
    void level_up();
    void level_down();
    void get_num();
    Counter();
    Counter(int num);
};