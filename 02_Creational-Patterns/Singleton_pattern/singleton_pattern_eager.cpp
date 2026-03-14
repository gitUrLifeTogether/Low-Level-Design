#include <iostream>

using namespace std;

class Singleton{
    private:
    static Singleton* instance;

    Singleton(){
        cout<<"Constructor called, new object created"<<endl;
    }

    public:
    static Singleton* getInstance(){
       return instance;
    }
};
//initialize static members
Singleton* Singleton::instance= new Singleton();

int main(){
    /* Singleton* S1 = new Singleton();
     Singleton* S2 = new Singleton();

 */
    Singleton* S1 = Singleton::getInstance();
    Singleton* S2 = Singleton::getInstance();
    cout<< (S1==S2)<<endl;
}
 /* disadvantage : if object is too expensive to create 
 and we create it before main function, and we never use it 
 main fn , then it wastes a lot of memory  */