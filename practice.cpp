#include<iostream>

using namespace std;

class Animal{
    private:
     static Animal* instance;
    Animal(){
       
        cout<<"constructor called"<<endl;
    }

    public:
    static Animal* getAnimal(){
        if(instance==nullptr){
            instance= new Animal();
        }
        return instance;
    }
};

Animal* Animal::instance=nullptr;

int main(){
    Animal* A1 = Animal::getAnimal();
    Animal* A2 = Animal::getAnimal();
}