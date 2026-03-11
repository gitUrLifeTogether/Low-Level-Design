#include <iostream>

using namespace std;

class Car {
protected:
    int speed;    

public:
    Car() {
        speed = 0;
    }
    
    void accelerate() {
        cout << "Accelerating" << endl;
        speed += 20;
    }

    //PostCondition : Speed must reduce after brake
    virtual void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
    }
};
class HybridCar : public Car {
private:
    int charge;

public:

    HybridCar() : Car() {
        charge = 0;
    }
    void brake() {
        cout << "Applying brakes" << endl;
        speed -= 20;
        charge += 10;
    }
};


int main() {
    Car* hybridCar = new HybridCar();
    hybridCar->brake();  
    return 0;
}