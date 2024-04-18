#pragma once
#include <iostream>
#include <fstream>
using namespace std;


const int DESC_SIZE = 31, NUM_RECORDS = 5;
class Invtry
{
private:


public:

    char desc[DESC_SIZE];
    int qty;
    double price;
    int createRecords();
    int readRecords();
    int writeRecords();


};
