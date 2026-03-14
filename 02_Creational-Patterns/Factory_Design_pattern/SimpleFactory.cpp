#include <iostream>

using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

class BasicBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing basic Burger with bun. patty and ketchup!" << endl;
    }
};

class standardBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing standard Burger with bun. patty, cheese and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing premium Burger with gourmet bun, premium patty , cheese, lettuce and secret sauce " << endl;
    }
};

class BurgerFactory
{
public:
    Burger *createBurger(string &type)
    {
        if (type == "Basic")
        {
            return new BasicBurger();
        }
        else if (type == "Standard")
        {
            return new standardBurger();
        }
        else if (type == "Premium")
        {
            return new PremiumBurger();
        }
        else
        {
            cout << "Invalid burger type" << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "Standard";

    BurgerFactory *myBurgerFactory = new BurgerFactory();

    Burger *burger = myBurgerFactory->createBurger(type);
    
    burger->prepare();
    return 0;
}