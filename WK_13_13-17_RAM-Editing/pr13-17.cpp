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
#include "Invtry.h"
#include <iostream>
#include <fstream>
using namespace std;

Invtry record;
int Invtry::createRecords()
{

    int numberBytesToWrite = sizeof(record);

    // Create file object and open file
    fstream inventory("invtry.dat", ios::out | ios::binary);
    if (!inventory)
    {
        cout << "Error opening file.";
        return 0;
    }


    // Now write the blank records
    for (int count = 0; count < NUM_RECORDS; count++)
    {
        cout << "Now writing record " << count << endl;
        inventory.write(reinterpret_cast<char*>(&record), numberBytesToWrite);

    }
    cout << numberBytesToWrite << " bytes were written to the file.\n";
    //Close the file
    inventory.close();
    return 0;
}

int Invtry::writeRecords()
{
    fstream inventory("invtry.dat", ios::in | ios::binary);
    if (!inventory)
    {
        cout << "Error in opening the file.";
        return 0;
    }
    int recordSize = sizeof(record);

    // Now read and display the records
    inventory.read(reinterpret_cast<char*>(&record), recordSize);
    while (!inventory.eof())
    {
        cout << "Description: ";
        cout << record.desc << endl;
        cout << "Quantity: ";
        cout << record.qty << endl;
        cout << "Price: ";
        cout << record.price << endl << endl;
        inventory.read(reinterpret_cast<char*>(&record), recordSize);
    }
    cout << recordSize << " bytes were read from the file.\n";
    inventory.close();
    return 0;
}

int Invtry::readRecords()
{
    long recNum; // Record number to edit

    // Open the file
    fstream inventory("invtry.dat", ios::in | ios::out | ios::binary); // Open for reading and writing
    if (!inventory)
    {
        cout << "Error opening file.";
        return 0;
    }

    // Move to the desired record and read it into record
    cout << "Which record do you want to edit?";
    cin >> recNum;
    inventory.seekg(recNum * sizeof(record), ios::beg); //seekg() is used to move the file pointer to a specific location in the file
    // and read the record
    // The first argument is the number of bytes to move the file pointer 2*48=96
    // The second argument is the starting point for the move
    inventory.read(reinterpret_cast<char*> (&record), sizeof(record));

    // Get new data from user and edit in-memory record						
    cout << "Description: ";
    cout << record.desc << endl;
    cout << "Quantity: ";
    cout << record.qty << endl;
    cout << "Price: ";
    cout << record.price << endl;
    cout << "Enter the new data:\n";
    cout << "Description: ";
    cin.ignore(); // Ignore the newline character in the input buffer
    cin.getline(record.desc, DESC_SIZE);
    cout << "Quantity: ";
    cin >> record.qty;
    cout << "Price: ";
    cin >> record.price;

    // Move to the right place in file and write the record
    inventory.seekp(recNum * sizeof(record), ios::beg); //seekp() is used to move the file pointer to a specific location in the file
    // and write the record
    inventory.write(reinterpret_cast<char*> (&record), sizeof(record));

    // Close the file					 
    inventory.close();
    return 0;
}
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