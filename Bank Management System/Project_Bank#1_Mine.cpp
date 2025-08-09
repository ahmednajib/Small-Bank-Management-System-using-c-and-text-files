#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

             //Necessary functions//

void MainPage();

vector <string> SplitWords(string S1, string delim)
{
    short pos = 0;
    string Word;
    vector <string> vSplitedWords;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        Word = S1.substr(0, pos);
        if (Word != "")
        {
            vSplitedWords.push_back(Word);
        }

        S1.erase(0, pos + delim.length());
    }

    if (Word != "")
    {
        vSplitedWords.push_back(S1);
    }

    return vSplitedWords;
}

sClient ConvertLineToRecord(string Line, string delim = "#//#")
{
    sClient Client;
    vector<string> vClientData;

    vClientData = SplitWords(Line, delim);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

string ConvertRecordToLine(sClient ClientData, string delim = "#//#")
{
    string stClientData = "";
    stClientData += ClientData.AccountNumber + delim;
    stClientData += ClientData.PinCode + delim;
    stClientData += ClientData.Name + delim;
    stClientData += ClientData.Phone + delim;
    stClientData += to_string(ClientData.AccountBalance);

    return stClientData;
}

vector <sClient> LoadClientsDataFromFile(string FileName)
{

    fstream MyFile;
    vector<sClient> vClients;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string line;
        sClient Client;

        while (getline(MyFile, line))
        {

            Client = ConvertLineToRecord(line);
            vClients.push_back(Client);

        }

        MyFile.close();

    }
    return vClients;

}

void AddDataLineToFile(string FileName, string Line)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << Line << endl;
        MyFile.close();
    }

}

vector <sClient> SaveClientsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);

    string Line = "";

    if (MyFile.is_open())
    {
        for (sClient C : vClients) {

            if (C.MarkForDelete == false)
            {
                Line = ConvertRecordToLine(C);
                MyFile << Line << endl;
            }

        }
        MyFile.close();
    }
    return vClients;
}

           //Add New Client// 
bool CheckClientByAccountNumber(string AccountNumber) 
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            return true;
        }
    }

    return false;

}

sClient ReadNewClient()
{
    sClient ClientData;

    cout << "Enter Account Number ?  ";
    getline(cin >> ws, ClientData.AccountNumber);
    
    while (CheckClientByAccountNumber(ClientData.AccountNumber))
    {
        cout << "Client With Account Number[" << ClientData.AccountNumber << "] already exist, try another Account Number ?";
        getline(cin, ClientData.AccountNumber);
    }

    cout << "Enter Pin Code ?  ";
    getline(cin, ClientData.PinCode);

    cout << "Enter Name ?  ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone ?  ";
    getline(cin, ClientData.Phone);

    cout << "Enter Account Balance ?  ";
    cin >> ClientData.AccountBalance;

    return ClientData;

}

void AddNewClient()
{
    sClient sClient;

    sClient = ReadNewClient();

    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(sClient));
}

void AddClients()
{
    char AddMore = 'y';

    do
    {
        cout << "Adding a New Client:\n\n";
        AddNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? y/press any key: ";
        cin >> AddMore;

    } while (tolower(AddMore) == 'y');

}

          //Show Client List// 

void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllCLientsData(vector <sClient> vClients)
{
    cout << "\t\t\t\t\t\tClient list (" << vClients.size() << ") Client(s).";
    cout << "\n\n _______________________________________________________________________________________________________________________\n\n";
    cout << "| " << setw(15) << left << "Account Number";
    cout << "| " << setw(10) << left << "Pin Code";
    cout << "| " << setw(40) << left << "Client Name";
    cout << "| " << setw(12) << left << "Phone";
    cout << "| " << setw(12) << left << "Balance";
    cout << "\n _______________________________________________________________________________________________________________________\n\n";

    for (sClient client : vClients)
    {
        PrintClientRecord(client);
        cout << endl;
    }

    cout << "\n\n _______________________________________________________________________________________________________________________\n\n";
}

void PrintClientCard(sClient Client)
{
    cout << "\n\nThe following are client details\n\n";
    cout << "Account Nnumber: " << Client.AccountNumber << endl;
    cout << "Pin Code: " << Client.PinCode << endl;
    cout << "Name: " << Client.Name << endl;
    cout << "Phone: " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
}

         //Find Client// 

bool FindClientByAccountNumber(sClient& client, string AccountNumber)
{
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            client = C;
            return true;
        }
    }

    return false;
}

void ShowFoundClient(string AccountNumber)
{
    sClient Client;
    if (FindClientByAccountNumber(Client, AccountNumber))
    {

        PrintClientCard(Client);
    }
    else
    {
        cout << "Client with account number (" << AccountNumber << ") Not Found!";
    }
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "Please enter Account Number? ";
    cin >> AccountNumber;

    return AccountNumber;
}

        //Delete Client//

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }

    return false;
}

bool DeleteClientByAccountNumber(vector <sClient>& vClients, string AccountNumber)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(Client, AccountNumber))
    {

        PrintClientCard(Client);
        cout << "/n/nAre you sure you want to delete this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);

            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "\n\nClient deleted successfully.";
            return true;
        }

    }
    else
    {
        cout << "Client with account number (" << AccountNumber << ") Not Found!";
        return false;
    }
}

        //Update Client//

sClient ChangeClientRecord(string AccountNumber)
{
    sClient ClientData;

    ClientData.AccountNumber = AccountNumber;

    cout << "\n\nEnter Pin Code ?  ";
    getline(cin >> ws, ClientData.PinCode);

    cout << "Enter Name ?  ";
    getline(cin, ClientData.Name);

    cout << "Enter Phone ?  ";
    getline(cin, ClientData.Phone);

    cout << "Enter Account Balance ?  ";
    cin >> ClientData.AccountBalance;

    return ClientData;

}

bool UpdateClientByAccountNumber(vector <sClient>& vClients, string AccountNumber)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(Client, AccountNumber))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to Update this client? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }

            }

            SaveClientsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated successfully.";
            return true;
        }

    }
    else
    {
        cout << "Client with account number (" << AccountNumber << ") Not Found!";
        return false;
    }
}

         //Main Page//

void ShowMainMenueScreen()
{
    cout << "=================================================================\n";
    cout << "\t\t\tMain Menue Screen";
    cout << "\n=================================================================\n"; 
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.\n";
    cout << "=================================================================\n";

}

short WhatToDo() 
{
    short WhatToDo;
    do{
    
    cout << "\nChoose what do you want to do? [1 to 6]?";
    cin >> WhatToDo;
    
    } while (WhatToDo < 1 || WhatToDo > 6);

    return WhatToDo;
}

void PressAnyKeyToContinue() 
{
    cout << "\n\nPress any key to go back to Main Minue...";
    system("pause>0");
    MainPage();
}

void ProcessScreen(string message)
{
    cout << "--------------------------------------- \n";
    cout << "\t" << message << endl;
    cout << "--------------------------------------- \n";
}

void MainPage()
{
    system("cls");
    vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    short Option;
    string AccountNumber = "";
    ShowMainMenueScreen();
    Option = WhatToDo();

    switch (Option)
    {
    case 1 :
        system("cls");
        PrintAllCLientsData(vClients);
        PressAnyKeyToContinue();
        break;
    
    case 2 : 
        system("cls");
        ProcessScreen("Add New Clients Screen");        
        AddClients();
        PressAnyKeyToContinue();
        break;

    case 3 :
        system("cls");
        ProcessScreen("Delete Client Screen");
        AccountNumber = ReadClientAccountNumber();
        DeleteClientByAccountNumber(vClients, AccountNumber);
        PressAnyKeyToContinue();
        break;
    case 4 :
        system("cls");
        ProcessScreen("Update Client Info Screen");
        AccountNumber = ReadClientAccountNumber();
        UpdateClientByAccountNumber(vClients, AccountNumber);
        PressAnyKeyToContinue();
        break;

    case 5 :
        system("cls");
        ProcessScreen("Find Client Screen");
        AccountNumber = ReadClientAccountNumber();
        ShowFoundClient(AccountNumber);
        PressAnyKeyToContinue();
        break;

    case 6 :
        system("cls");
        ProcessScreen("Program Ends :-)");
        break;
    }
}

int main()
{ 
    MainPage();

    return 0;

}