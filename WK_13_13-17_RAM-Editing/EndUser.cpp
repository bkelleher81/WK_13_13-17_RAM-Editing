// This program allows the user to edit a specific 
// record in the inventory file.
#include <iostream>
#include <fstream>
#include "Invtry.h"
using namespace std;

int main() 
{

    // Variables needed to reead the file
    Invtry r;

    r.createRecords();
    r.writeRecords();
    r.readRecords();
    return 0;
}