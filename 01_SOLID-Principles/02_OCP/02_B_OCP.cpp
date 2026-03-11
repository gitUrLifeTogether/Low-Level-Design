#include <iostream>

using namespace std;

class TaxCalculator{
    public:
        virtual double calculateTax(double amount)=0;
};

class IndiaTaxCalculator:public TaxCalculator{
    public:
    double calculateTax(double amount) override{
        return amount + amount * 0.18;
    }
};

class USTaxCalculator:public TaxCalculator{
    public:
    double calculateTax(double amount) override{
        return amount + amount * 0.08;
    }
};

class UKTaxCalculator:public TaxCalculator{
    public:
    double calculateTax(double amount) override{
        return amount + amount * 0.12;
    }
};

class Invoice{
    private:
    double amount;
    TaxCalculator* taxCalculator;

    public:
    Invoice(double amount , TaxCalculator* taxCalculator):amount(amount), taxCalculator(taxCalculator){}
    double getTotalAmount(){
        return amount+ taxCalculator->calculateTax(amount);
    }
};

int main(){
    double amount=1000.0;

    Invoice indiainvoice(amount,new IndiaTaxCalculator());
    cout<<"Total (india): Rs "<<indiainvoice.getTotalAmount()<<endl;

    Invoice usinvoice(amount,new USTaxCalculator());
    cout<<"Total (US): $ "<<usinvoice.getTotalAmount()<<endl;

    Invoice ukinvoice(amount,new UKTaxCalculator());
    cout<<"Total (UK): £ "<<ukinvoice.getTotalAmount()<<endl;

    return 0;
}

