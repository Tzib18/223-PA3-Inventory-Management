#include "classes.hpp"
#include "library.hpp"

void parseCSV(const string &filename, HashTable<string, Inventory> &inventoryTable)
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
        string currCharacter; // this will hold the current category/field we are on
        bool inQuotes = false; // this will be used to track if we are in quotes or not

        for(char character : line){ // this will itterate each charecter in the line
            if(character == '"'){ // if the character has a double quote ("") then we will switch the in quotes tracker
                inQuotes = !inQuotes; // this will set the in quotes to true if thier is double quote
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
        
        if(fields.size() < 9){ // this will check if the line is valid or not
          continue; // if the line is not valid then we will skip it
        }
        // have the basic elements for the assingments req. but i will add more when i have time
        id = fields[0]; // this will set the id to the first category
        name = fields[1]; // this will set the name to the second category
        category = fields[4]; // this will set the category to the third category
        price = fields[7]; // this will set the price to the fourth category
        quantity = fields[8]; // this will set the quantity to the fifth category  
        
        // this will check if any of the categories are empty or not
        if(id.empty() || name.empty()){ 
            continue; // if any of the categories are empty then we will skip the line
        }
        if(category.empty()){ // if their is no catagiry then set it to `NA`
            category = "NA";
        }
        if(price.empty()){ // if their is no price then set it to 0.0
            price = "0.0";
        }
        if(quantity.empty()){ // if ther is no quentity then set it to 0
            quantity = "0";
        }

        double priceValue = 0.0; // making this decleration to 0.0 of a double that is an actual number not string 
        int quantityValue = 0; // making this decleration to 0 of an int that is an actual number not string

        // this will try to convert the price and quantity to real numbers instead of string and if it fails then 
        // it will set the price and quantity to 0.0 and 0 
        try{ // this will try to convert the price and quantity to the correct data type
            priceValue = stod(price); // this will convert the price from a string to a double
        }
        catch(...){
            priceValue = 0.0; // if the conversion fails then we will set the price to 0.0
        }

        try{
            quantityValue = stoi(quantity); // this will convert the quantity from a string to an int 

        }
        catch(...){
            quantityValue = 0; // if the conversion fails then we will set the quantity to 0
        }

        // this will create an inventory object with the data we have parsed from the csv file
        Inventory items(id, name, category, priceValue, quantityValue); 

        vector<string> catagories = splitCategory(category);
        // this will split the category into a vector of categories in case there are multiple categories for an item. 

        for (const string& oneCategory : catagories)
        {
            cout << "Split Category: " << oneCategory << endl;
        }
        // after splitting the | catagories we need to implement the hash table so we can store the data
        inventoryTable.insert(id, items); // this will insert the inventory object into the hash table with the id as the key and the inventory object as the value

        // checking to see if parse fucntion works 
        cout<<"ID: "<<items.getId()<<endl // made this to where it will print out the elemenet with the name so easier to see.
        <<"Name: "<<items.getName()<<endl
        <<"Category: "<<items.getCategory()<<endl
        <<"Price: "<<items.getPrice()<<endl
        <<"Quantity: "<<items.getQuantity()<<endl;   

    }
    

}

vector<string> splitCategory(const string &CategoryLine)
{
    vector<string> categories; // this will hold the categories
    string currCategory; // this will hold the current category we are on
    for(char character : CategoryLine){ // this will itterate each charecter in the category line
        // this scenario checks for things like this: electronics|home|kitchen. so it will read all words in the category.
        if(character == '|'){ // if we see a pipe character then we will add the current category to the categories vector and reset the current category
            if(!currCategory.empty()){ // this will check if the current category is empty or not
                categories.push_back(currCategory); // this will add the current category to the categories vector
                currCategory = ""; // this will reset the current category
            }
        }
        else{ // if we see a character then we will add it to the current category
            currCategory += character;
        }
        // this is another scenario from the top ex: electronics. 
        // so electronics gets pushed into teh categories vector
        if(!currCategory.empty()){ // this will check if the current category is empty or not
            categories.push_back(currCategory);
        }
    }
    return categories;
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
