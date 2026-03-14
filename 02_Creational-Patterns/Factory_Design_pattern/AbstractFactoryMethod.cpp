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

class BasicWheatBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing basic  wheat Burger with bun. patty and ketchup!" << endl;
    }
};

class standardWheatBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing standard wheat Burger with bun. patty, cheese and lettuce!" << endl;
    }
};

class PremiumWheatBurger : public Burger
{

public:
    void prepare() override
    {
        cout << "Preparing premium wheat Burger with gourmet bun, premium patty , cheese, lettuce and secret sauce " << endl;
    }
};

class GarlicBread {
public:
    virtual void prepare() = 0;
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Basic Garlic Bread with butter and garlic!\n";
    }
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Cheese Garlic Bread with extra cheese and butter!\n";
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Basic Wheat Garlic Bread with butter and garlic!\n";
    }
};

class CheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        std::cout << "Preparing Cheese Wheat Garlic Bread with extra cheese and butter!\n";
    }
};


class MealFactory
{
public:
 virtual Burger* createBurger(string& type)=0;
 virtual GarlicBread* createGarlicBread(string& type)=0;

};

class singhBurger: public MealFactory{
    Burger *createBurger(string &type) override
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

    GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicGarlicBread();
        } else if (type == "cheese") {
            return new CheeseGarlicBread();
        } 
        else {
            cout << "Invalid Garlic bread type! " << endl;
            return nullptr;
        }
    }
};

class kingBurger: public MealFactory{
    Burger *createBurger(string &type)
    {
        if (type == "Basic")
        {
            return new BasicWheatBurger();
        }
        else if (type == "Standard")
        {
            return new standardWheatBurger();
        }
        else if (type == "Premium")
        {
            return new PremiumWheatBurger();
        }
        else
        {
            cout << "Invalid burger type" << endl;
            return nullptr;
        }
    }

     GarlicBread* createGarlicBread(string& type) override {
        if (type == "basic") {
            return new BasicWheatGarlicBread();
        } else if (type == "cheese") {
            return new CheeseWheatGarlicBread();
        } 
        else {
            cout << "Invalid Garlic bread type! " << endl;
            return nullptr;
        }
    }
};

int main()
{
    string burgertype = "Basic";
    string GarlicBreadType ="cheese";

    MealFactory *mealFactory = new kingBurger();

    Burger *burger = mealFactory->createBurger(burgertype);
    GarlicBread *garlicBread = mealFactory->createGarlicBread(GarlicBreadType);
    
    burger->prepare();
    garlicBread->prepare();
    return 0;
}