#include<iostream>
#include<vector>


using namespace std;

class Account{
    public:
    virtual void deposit(double amount)=0;
    virtual void withdraw(double amount)=0;

};

class savingsAcc: public Account{
    double balance;

    public:
    savingsAcc(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<" in savings account. New balance: "<<balance<<endl;
    }
    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
        cout<<"withdrawn: "<<amount<<" from savings account. New balance: "<<balance<<endl;
        }

        else {
            cout<<"Insufficient balance";
        }
        
    }
};

class currentAcc: public Account{
    double balance;

    public:
    currentAcc(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<" in current account. New balance: "<<balance<<endl;
    }
    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
        cout<<"withdrawn: "<<amount<<" from current account. New balance: "<<balance<<endl;
        }

        else {
            cout<<"Insufficient balance";
        }
        
    }
    
};
class fixedDepositAcc: public Account{
    double balance;

    public:
    fixedDepositAcc(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<" in FD account. New balance: "<<balance<<endl;
    }
    void withdraw(double amount){
        throw logic_error("withdrawal not allowed in fixed term account!");
    }
    
};

class BankClient{
    vector<Account*> accounts;

    public:
    BankClient(vector<Account*> accounts){
        this->accounts=accounts;
    }

    void processTransactions(){
        for(Account* acc : accounts){
            acc->deposit(1000);
            try{
                acc->withdraw(500);
            }
            catch(const logic_error& e){
                cout<<"Exception: "<<e.what() <<endl;
            }
        }
    }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new savingsAcc());
    accounts.push_back(new currentAcc());
    accounts.push_back(new fixedDepositAcc());

    BankClient * client = new BankClient(accounts);
    client->processTransactions();

    return 0;
}