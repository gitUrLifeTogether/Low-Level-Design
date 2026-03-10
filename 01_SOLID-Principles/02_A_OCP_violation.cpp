#include <iostream>

using namespace std;

class TaxCalculator
{
public:

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

int main(){
    TaxCalculator* CurrentTax1 = new TaxCalculator();

    cout<<"The final amount is: "<<CurrentTax1->CalculateTax("INDIA", 1000)<<endl;
    cout<<"The final amount is: "<<CurrentTax1->CalculateTax("UK", 1000)<<endl;
    cout<<"The final amount is: "<<CurrentTax1->CalculateTax("USA", 1000)<<endl;

}