#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class User{

    public:
        string Name = "";
        char bDay[8];
        double balance = 500;
        int ID;
        string passwd;

        void showBalance();

        void withdraw(double amount);
        

        void deposit(double amount);
        


};

void User::showBalance()
    {
        std::cout << "balance: " << balance << endl;
    }

void User::withdraw(double amount)
{
    
    balance -= amount;
    std::cout << "Your amount was withdrawn."<< endl;

}

void User::deposit(double amount)
{
    if(amount <= 0)
    {
        std::cout << "This is an invalid amount." << endl;
        return;
    }

    balance += amount;
    std::cout << "The amount was added into your account." << endl;
}


void showMenu()
{
    //option 1 = check balance
    std::cout << "*******************MENU********************" << endl;
    std::cout << "(1) Check Balance" << endl;
    std::cout << "(2) Deposit Money" << endl;
    std::cout << "(3) Withdrawl Money" << endl;
    std::cout << "(4) Back to init menu" << endl;
    std::cout << "(5) Account Information" << endl;
    std::cout << "*******************************************" << endl;
}

void iniMenu()
{
    std::cout << "*******************MENU********************" << endl;
    std::cout << "(1) New User" << endl;
    std::cout << "(2) Login " << endl;
    std::cout << "(3) Exit" << endl;
    //std::cout << "(5) Account Information" << endl;
    std::cout << "*******************************************" << endl;
}

int main()
{
    std::cout <<"Welcome to RichEngineering's ATM"<<endl;

    //check balance, deposit money, withdraw, show menu
    int choice = 0;
    double balance = 500;

    //take name and information
    string fName;
    string lName;
    int ID =0;
    char bDay[8];
    int size = 0;

    //create a vector for users
    vector<User> Users;
    

    while(1)
    {
        iniMenu();

        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                size +=1;
                Users.resize(size);//add a new spot in array

                cin.ignore(10000, '\n');
                std::cout << "Enter name here: ";
                getline(cin, fName);
                std::cout << "Name:" << fName << endl;

                
                std::cout << "Enter Birthday in format MMDDYYYY" << endl;
                cin >> bDay;

                //create password
                string pass1;
                cin.ignore(10000, '\n');
                std::cout << "Enter Password: " << endl;
                getline(cin, pass1);
            
                

                //enter data into user object
                Users[size-1].Name = fName;
                Users[size-1].ID = ID;
                Users[size-1].passwd = pass1;
                strcpy(Users[size-1].bDay,bDay);
                
                
                
                std::cout << "Name:" << Users[size-1].Name << endl;
                std::cout << "Birthday:" << Users[size-1].bDay << endl;
                std::cout << "ID:" << Users[size-1].ID << endl;

                break;
            }
            case 2:
            {
                string pass2;
                std::cout << "Enter ID: " << endl;
                cin >> ID;
                cin.ignore(10000, '\n');
                std::cout << "Enter Password: " << endl;
                getline(cin, pass2);

                if(pass2 != Users[ID].passwd)
                {
                    std::cout << "Incorrect Password " << endl;
                    choice = 2;
                }
                
                //can add password functionality
                break;
            }
            case 3:std::cout << "Thank You for using RichEngineering ATM" << endl;
            std::exit(0);
            break;
        }

        do{
            showMenu();
            
            cin >> choice;
            switch(choice)
            {
                case 1: std::cout << "Balance: $" << Users[ID].balance << endl; break;
                case 2: 
                {
                    std::cout << "Deposit Amount: ";
                    double depAmount;
                    cin >> depAmount;
                    //Users[ID].balance += depAmount;
                    //balance += depAmount;
                    Users[ID].deposit(depAmount);
                    break;
                }
                case 3: std::cout << "Withdraw Amount:  ";
                    double witAmount;
                    cin >> witAmount;
                    if(witAmount < Users[ID].balance)
                    {
                        Users[ID].withdraw(witAmount);
                    }
                    else
                    {
                        std::cout << "You do not have enough money." << endl;
                    }
                    break;
                case 4:choice = 4;
                break;

                case 5: std::cout << "Name: " << Users[ID].Name << endl;
                std::cout << "Birthday MMDDYYYY: " << Users[ID].bDay << endl;
                break;


            }
        }
        while(choice != 4);   
    }
   // system("pause>0");
    return 0;
}