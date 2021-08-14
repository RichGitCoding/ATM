#include <iostream>
#include <string>
using namespace std;

void showMenu()
{
    //option 1 = check balance
    std::cout << "*******************MENU********************" << endl;
    std::cout << "(1) Check Balance" << endl;
    std::cout << "(2) Deposit Money" << endl;
    std::cout << "(3) Withdrawl Money" << endl;
    std::cout << "(4) Exit" << endl;
    std::cout << "(5) Account Information" << endl;
    std::cout << "*******************************************" << endl;
}

int main()
{
    std::cout <<"Welcome to RichEngineering's ATM"<<endl;

    //check balance, deposit money, withdraw, show menu
    int choice = 0;
    double balance = 500;

    //take name and information
    string fName = "Default";
    string lName = "Name";
    char bDay[8];

    std::cout << "Enter first name here: " << endl;
    cin >> fName;
    std::cout << "Enter last name here: " <<endl;
    cin >> lName;
    std::cout << "Enter Birthday in format MMDDYYYY" << endl;
    cin >> bDay;



    do{
        showMenu();
        
        cin >> choice;
        switch(choice)
        {
            case 1: std::cout << "Balance: $" << balance << endl; break;
            case 2: std::cout << "Deposit Amount: ";
                double depAmount;
                cin >> depAmount;
                balance += depAmount;
                break;
            case 3: std::cout << "Withdraw Amount:  ";
                double witAmount;
                cin >> witAmount;
                if(witAmount < balance)
                {
                    balance -= witAmount;
                }
                else
                {
                    std::cout << "You do not have enough money." << endl;
                }
                break;
            case 4:std::cout << "Thank You for using RichEngineering ATM" << endl;
            std::exit(0); 
            break;
            case 5: std::cout << "First Name: " << fName << endl;
            std::cout << "Last Name: " << lName << endl;
            std::cout << "Birthday MMDDYYYY: " << bDay << endl;
            break;


        }
    }
    while(1);   

   // system("pause>0");
    return 0;
}