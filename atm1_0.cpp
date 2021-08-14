#include <iostream>
using namespace std;

void showMenu()
{
    //option 1 = check balance
    cout << "*******************MENU********************" << endl;
    cout << "(1) Check Balance" << endl;
    cout << "(2) Deposit Money" << endl;
    cout << "(3) Withdrawl Money" << endl;
    cout << "(4) Exit" << endl;
    cout << "*******************************************" << endl;
}

int main()
{
    //cout <<"Hello world"<<endl;

    //check balance, deposit money, withdraw, show menu
    int choice = 0;
    double balance = 500;

    do{
        showMenu();
        
        cin >> choice;
        switch(choice)
        {
            case 1: cout << "Balance: $" << balance << endl; break;
            case 2: cout << "Deposit Amount: ";
                double depAmount;
                cin >> depAmount;
                balance += depAmount;
                break;
            case 3: cout << "Withdraw Amount:  ";
                double witAmount;
                cin >> witAmount;
                if(witAmount < balance)
                {
                    balance -= witAmount;
                }
                else
                {
                    cout << "You do not have enough money." << endl;
                }
                break;
            case 4:cout << "Thank You for using RichEngineering ATM" << endl;
            exit(0); 
            break;


        }
    }
    while(1);   

   // system("pause>0");
    return 0;
}