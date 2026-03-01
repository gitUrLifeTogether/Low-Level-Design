#include <iostream>
#include<mutex> //helps to lock and unlock 

using namespace std;

class Singleton{
    private:
    static Singleton* instance;
    static mutex mtx;

    Singleton(){
        cout<<"Constructor called, new object created"<<endl;
    }

    public:
    static Singleton* getInstance(){
        
        if(instance==nullptr){
            lock_guard<mutex> lock(mtx);//lock for thread safety

            // double locking incase if at starting both threads neter at the same time
             if(instance==nullptr){
                 instance = new Singleton();
             }
           
        }
       return instance;
    }
};

Singleton* Singleton::instance=nullptr;

int main(){
    /* Singleton* S1 = new Singleton();
     Singleton* S2 = new Singleton();

 */
    Singleton* S1 = Singleton::getInstance();
    Singleton* S2 = Singleton::getInstance();
    cout<< (S1==S2)<<endl;
}