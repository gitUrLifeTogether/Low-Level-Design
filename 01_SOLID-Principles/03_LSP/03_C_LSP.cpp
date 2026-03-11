#include<iostream>
#include<vector>


using namespace std;

class depositOnlyAcc{
    public:
    virtual void deposit(double amount)=0;

};

class withrawableAcc: public depositOnlyAcc{
    public:
    virtual void withdraw(double amount) = 0;
};

class savingsAcc: public withrawableAcc{
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

class currentAcc: public withrawableAcc{
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

class fixedDepositAcc: public depositOnlyAcc{
    double balance;

    public:
    fixedDepositAcc(){
        balance=0;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"deposited: "<<amount<<" in FD account. New balance: "<<balance<<endl;
    }
    
};

class BankClient{
    vector<withrawableAcc*> WithrawableAcc;
    vector<depositOnlyAcc*> DepositOnlyAcc;

    public:
    BankClient(vector<withrawableAcc*> WithrawableAc,vector<depositOnlyAcc*> DepositOnlyAcc){
        this->WithrawableAcc = WithrawableAcc;
        this->DepositOnlyAcc = DepositOnlyAcc;
    }

    void processTransactions(){
        for(withrawableAcc* acc : WithrawableAcc){
            acc->deposit(1000);
            acc->withdraw(100);
        }
        for (depositOnlyAcc* acc : DepositOnlyAcc){
            acc->deposit(500);
        }
    }
};

int main(){
    vector<withrawableAcc*> Withdrableacc;
    Withdrableacc.push_back(new savingsAcc());
    Withdrableacc.push_back(new currentAcc());

    vector<depositOnlyAcc*> DepositOnlyAcc;
    DepositOnlyAcc.push_back(new fixedDepositAcc());

    BankClient * client = new BankClient(Withdrableacc,DepositOnlyAcc);
    client->processTransactions();

    return 0;
}

