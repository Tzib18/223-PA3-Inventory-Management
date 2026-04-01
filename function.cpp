#include "library.hpp"

void parseCSV(const string &filename)
{
    // opened the csv file 
    ifstream file(filename);// named it file name since the csv file is to long to type
    // saftey code and also tells me where the error occurs 
    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return; 
    }
    // made some string to hold data and to store it for the mean time
    string line; 
    string id, name, category, price, quantity;

    // skip the header line 
    getline(file, line); // skip the header line

   
    // read the lines 
    while (getline(file, line)){
        vector<string> fields; // this will hold the catgories 
        string currCharacter; // this will hold the current category we are on
        int iterator; // this will be used to iterate through the catagory tracker
        bool inQuotes = false; // this will be used to track if we are in quotes or not

        for(char character : line){ // this will itterate each charecter in the line
            if(character == '"'){ // if the character has a "" then we will switch the in quotes tracker
                inQuotes = !inQuotes;
            }
            else if(character == ',' && !inQuotes){ // if we are not in quotes and we see a comma then we will add the current category to the fields vector and reset the current category
                fields.push_back(currCharacter);
                currCharacter = "";
            }
            else{ // if we are not in quotes and we see a character then we will add it to the current category
                currCharacter += character;
                

            }
        }
        fields.push_back(currCharacter); // this will add the last category to the fields vector
        
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, category, ',');
        getline(ss, price, ',');
        getline(ss, quantity, ',');
        // cout << id << " " << name << " " << category << " " << price << " " << quantity << endl;
    }
    

}

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        cout << "YET TO IMPLEMENT!" << endl;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        cout << "YET TO IMPLEMENT!" << endl;
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}


int runapp(int argc, char const *argv[])
{
    string line;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
