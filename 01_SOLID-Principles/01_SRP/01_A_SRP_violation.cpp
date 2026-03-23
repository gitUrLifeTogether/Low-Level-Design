#include<iostream>
#include<vector>

using namespace std;
// this is an example thaat violates single responsibility principle
class Product{
    public:
     double price;
     string name;

     Product(string name,double price){
        this->name=name;
        this->price=price;
     }
};

class ShoppingCart{
    private:
    vector<Product*> products;

    public:
     void addProduct(Product* p){
        products.push_back(p);
     }

    const vector<Product*>&getProducts(){
        return products;
    }

    double calculateTotal(){
        double total =0;
        for(auto p:products){
            total+=p->price;
        }
        return total;
    }

    void printInvoice(){
        cout<<"Shopping Cart Invoice:\n";
        for(auto p:products){
            cout<<p->name<<" $" <<p->price<<endl;
        }
        cout<<"Total: $"<<calculateTotal()<<endl;
    }

    void saveToDataBase(){
        cout<<"saving shopping cart to database...."<<endl;
    }
};
 
int main(){
    ShoppingCart* cart= new ShoppingCart;

    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",50));

    cart->printInvoice();
    cart->saveToDataBase();

    return 0;

   }


   
