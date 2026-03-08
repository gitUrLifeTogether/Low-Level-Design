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

/* class TaxCalculator
{
public:

this violates the OCP cause if we have to add another region(ex. UK, germany etc) 
we need to modify this code
    double CalculateTax(string region, double amount)
    
    {
        if (region == "INDIA"){
            return amount + amount * 0.18;
        }
           
        else if (region == "USA")
        {
            return amount + amount * 0.08;
        }
            
        else if (region == "UK")
        {
            return amount + amount * 0.12;
        }
        


        else
        {
            return amount; // No tax for unknown region
        }
}
}
; 

*/