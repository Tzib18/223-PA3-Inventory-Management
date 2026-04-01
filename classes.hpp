#include "library.hpp"


class Inventory{
    private:
        string id;
        string name;
        string category;
        double price;
        int quantity;

    public:
    // defualt constructor 
        Inventory(){
            this->id = "";
            this->name = "";
            this->category = "";
            this->price = 0.0;
            this->quantity = 0;
        }

    // constructor
        Inventory(const string& id, const string& name, const string& category, double price, int quantity){
            this->id = id;
            this->name = name;
            this->category = category;
            this->price = price;
            this->quantity = quantity;
        }
        
        // getters
        string getId() const{
            return id;
        }
        string getName()const{
            return name;
        }
        string getCategory() const{
            return category;
        }
        double getPrice() const{
            return price;
        }
        int getQuantity() const{
            return quantity;
        }
        //setters
        void setId(string id){
            this->id = id;
        }
        void setName(string name){
            this->name = name;
        }
        void setCategory(string category){
            this->category = category;
        }
        void setPrice(double price){
            this->price = price;
        }
        void setQuantity(int quantity){
            this->quantity = quantity;
        }
};