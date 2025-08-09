#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 }; // 429 CountLetters function

namespace MyLib
{

    /// Get Random Number///
    int RandomNumber(int From, int To)
    {

        int RandumNumber = rand() % (To - From + 1) + From;
        return RandumNumber;
    }

    // ReadNumbers Functions :

    int ReadpositiveNumebr(string Message)
    {
        int Number;
        do
        {
            cout << Message << endl;
            cin >> Number;

        } while (Number < 0);

        return Number;
    }

    
    int ReadNumberInRange(int From, int To)
    {
        int Number;
        do
        {
            cin >> Number;

        } while (Number < From || Number > To);

        return Number;
    }

    int ReadNumber()
    {
        int Number;
        
    

        cout << "Please enter a number ";
        cin >> Number;
        while (cin.fail())
        {

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one" << endl;
            cin >> Number;
        }
        return Number;
    }

    //************************************************************************************
    
    //File Functions :

    void PrintFileContent(string FileName)
    {

        fstream MyFile;

        MyFile.open(FileName, ios::in); 

        if (MyFile.is_open())
        {
            string line;

            while (getline(MyFile, line))
            {

                cout << line << endl;

            }

            MyFile.close();

        }

    }

    void LoadDataFromFileToVector(string FileName, vector <string> vFileData)
    {

        fstream MyFile;

        MyFile.open(FileName, ios::in);

        if (MyFile.is_open())
        {
            string line;

            while (getline(MyFile, line)) {

                vFileData.push_back(line);

            }

            MyFile.close();

        }

    }


    void SaveVectorToFile(string FileName, vector <string> vFileContent)
    {

        fstream MyFile;
        MyFile.open(FileName, ios::out);

        if (MyFile.is_open())
        {
            for (string Line : vFileContent) {

                if (Line != "")
                    MyFile << Line << endl;
            }
        }

        MyFile.close();
    }


    void DeleteRecordFromFile(string FileName, string Record)
    {
        fstream MyFile;
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        for (string& Line : vFileContent)
        {
            if (Line == Record)
            {
                Line = "";
            }
        }

        SaveVectorToFile(FileName, vFileContent);

    }


    void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
    {
        fstream MyFile;
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        for (string& Line : vFileContent)
        {
            if (Line == Record)
            {
                Line = UpdateTo;
            }
        }

        SaveVectorToFile(FileName, vFileContent);

    }

    //************************************************************************************

    // Matrix Functions :

    void FillMatrixWithRandomNumbers(int Mat[3][3], int Row, int Col)
    {

        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
            {
                Mat[i][j] = RandomNumber(1, 10);
            }
        }
    }


    int SumMatrixElements(int Mat[3][3], short Row, short Col) {
        int Sum = 0;
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {

                Sum += Mat[i][j];
            }
        }
        return Sum;
    }


    bool AreMatricesEquavilent(int Mat1[3][3], int Mat2[3][3], short Row, short Col) {

        return SumMatrixElements(Mat1, Row, Col) == SumMatrixElements(Mat2, Row, Col);
    }


    void PrintMatrix(int Mat[3][3], int Row, int Col) {

        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {

                printf("%0*d\t", 2, Mat[i][j]);
            }
            cout << endl;
        }
    }


    void PrintMidColOfMatrix(int Mat[3][3], short Row, short Col) {
        short MiddleCol = Col / 2;

        for (int i = 0; i < Row; i++) {

            printf("%0*d\t", 2, Mat[i][MiddleCol]);

        }
        cout << endl;
    }


    void PrintMidRowOfMatrix(int Mat[3][3], short Row, short Col) {
        short MiddleRow = Row / 2;

        for (int i = 0; i < Col; i++) {

            printf("%0*d\t", 2, Mat[MiddleRow][i]);

        }
        cout << endl;
    }

    //************************************************************************************

       //Array Functions :


    void ReadArray(int Array[100], int& arrlength) {

        cout << "\nPlease enter the length of the elements : \n";
        cin >> arrlength;
        cout << "Plaese enter array elements :" << endl;

        for (int i = 0; i < arrlength; i++)
        {
            cout << "Elemnet [" << i + 1 << "] :";
            cin >> Array[i];

        }
        cout << endl;
    }

   
    void PrintArrayElements(int Array[100], int length) {

        for (int i = 0; i < length; i++)
        {
            cout << Array[i] << " ";
        }
    }


    int SumOfArrayelements(int Array[100], int arrlength) {
        int sum = 0;

        for (int i = 0; i < arrlength; i++) {

            sum += Array[i];

        }
        return sum;
    }


    void FillArrayWithRandomElements(int Array[100], int& arrlength) {

        cout << "How many elements you want to enter :\n";
        cin >> arrlength;

        for (int i = 0; i < arrlength; i++) {

            Array[i] = MyLib::RandomNumber(1, 100);
        }
    }


    void CopyArrayelements(int OriganalArray[100], int CopiedArray[100], int arrlength) {

        for (int i = 0; i < arrlength; i++) {

            CopiedArray[i] = OriganalArray[i];

        }
    }



        //************************************************************************************

       //String Functions :


    
    char ReadChar()
    {
        char C;
        cout << "Enter a char :\n";
        cin >> C;

        return C;
    }


    
    string ReadString()
    {
        string Text = "";

        cout << "Please enter a text\n";
        getline(cin, Text);
        return Text;
    }



    void PrintFirstLetterOfEachWord(string Text)
    {
        bool IsFirstLetter = true;
        cout << "The first letters of each word are :\n";

        for (int i = 0; i < Text.length(); i++)
        {

            if (Text[i] != ' ' && IsFirstLetter) {
                cout << Text[i] << endl;
            }

            IsFirstLetter = (Text[i] == ' ' ? true : false);

        }
    }



    string UppercaseFirstLetterOfEachWord(string Text)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < Text.length(); i++)
        {

            if (Text[i] != ' ' && IsFirstLetter) {
                Text[i] = toupper(Text[i]);
            }

            IsFirstLetter = (Text[i] == ' ' ? true : false);

        }

        return Text;
    }




    string LowercaseFirstLetterOfEachWord(string Text)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < Text.length(); i++)
        {

            if (Text[i] != ' ' && IsFirstLetter) {
                Text[i] = tolower(Text[i]);
            }

            IsFirstLetter = (Text[i] == ' ' ? true : false);

        }

        return Text;
    }




    string LowerAllString(string text)
    {
        for (int i = 0; i < text.length(); i++)
        {
            text[i] = tolower(text[i]);
        }
        return text;
    }



    string UpperAllString(string Text)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = toupper(Text[i]);
        }
        return Text;
    }




    char InvertCharCase(char Character)
    {
        return isupper(Character) ? tolower(Character) : toupper(Character);
    }



    short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All) {
            return S1.length();
        }

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;
        }

        return Counter;
    }



    short CountSmallLetters(string Str)
    {
        short Counter = 0;
        for (short i = 0; i < Str.length(); i++)
        {
            if (islower(Str[i]))
                Counter++;
        }
        return Counter;
    }



    short CountCapitalLetters(string Str)
    {
        short Counter = 0;
        for (short i = 0; i < Str.length(); i++)
        {
            if (isupper(Str[i]))
                Counter++;
        }
        return Counter;
    }


    short CountCharacterInString(string S, char Ch)
    {
        short Counter = 0;

        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == Ch)
                Counter++;
        }

        return Counter;
    }


    bool IsAVowelLetter(char Letter)
    {
        Letter = tolower(Letter);
        return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
    }


    short CountVowels(string S)
    {
        short Counter = 0;

        for (short i = 0; i < S.length(); i++)
        {
            if (IsAVowelLetter(S[i]))
                Counter++;
        }

        return Counter;
    }



    void PrintVowels(string S)
    {
        cout << "Vowels in string are : ";
        for (short i = 0; i < S.length(); i++)
        {
            if (IsAVowelLetter(S[i]))
                cout << S[i] << "\t";
        }
    }



    void PrintEachWordInString(string S1)
    {
        string delim = " ";
        short Pos = 0;
        string Word;

        while ((Pos = S1.find(delim)) != std::string::npos)
        {
            Word = S1.substr(0, Pos);

            if (Word != "")
            {
                cout << Word << endl;
            }

            S1.erase(0, Pos + delim.length());

        }

        if (S1 != "")
        {
            cout << S1 << endl;

        }
    }



    short CountWordsInString(string S1) {

        short pos = 0, Counter = 0;
        string Word, delim = " ";

        while ((pos = S1.find(delim)) != string::npos)
        {
            Word = S1.substr(0, pos);
            if (Word != "")
            {
                Counter++;
            }

            S1.erase(0, pos + delim.length());
        }

        if (Word != "")
        {
            Counter++;
        }

        return Counter;
    }




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



    string ReplaceWordWithCustomFunction(string S1, string StringToRep, string sReplacedTo, bool MatchCase = true)
    {
        vector<string> vString;
        vString = SplitWords(S1, " ");
        if (MatchCase)
        {
            for (string& S : vString)
            {
                if (S == StringToRep)
                    S = sReplacedTo;
            }
        }

        else {

            for (string& S : vString)
            {
                if (LowerAllString(S) == LowerAllString(StringToRep))
                    S = sReplacedTo;
            }
        }

        S1 = JoinString(vString, " ");
        return S1;
    }



    string TrimLeft(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return (S1.substr(i, S1.length() - 1));
            }
        }
    }




    string TrimRight(string S1)
    {

        for (int i = S1.length(); i > 0; i--)
        {
            if (S1[i] != ' ')
            {
                return (S1.substr(0, i));
            }
        }
    }




    string TrimAll(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }



    string JoinString(vector <string> VS1, string delim)
    {
        int pos = 1;
        string S1 = "";

        for (string& S : VS1)
        {
            S1 += S + delim;

        }

        return S1.substr(0, S1.length() - delim.length());
    }



    string JoinString(string Arr[], short arrlength, string delim)
    {
        string S1 = "";

        for (short i = 0; i < arrlength; i++)
        {
            if (Arr[i] != "")
            {
                S1 += Arr[i] + delim;
            }
        }

        return S1.substr(0, S1.length() - delim.length());
    }



    string reverseString(string S1)
    {
        vector <string> vString;
        string revString = "";
        vString = SplitWords(S1, " ");
        vector <string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;

            revString += *iter + " ";
        }


        return revString.substr(0, revString.length() - 1);
    }


    string ReplaceWord(string S1, string StringToRep, string sReplacedTo)
    {
        int pos = S1.find(StringToRep);

        while (pos != string::npos)
        {
            S1 = S1.replace(pos, StringToRep.length(), sReplacedTo);
            pos = S1.find(StringToRep);
        }

        return S1;
    }


    sClientData ConvertLineToRecord(string Line, string delim = "#//#")
    {
        sClientData Client;
        vector<string> vClientData;

        vClientData = SplitWords(Line, delim);

        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);

        return Client;
    }


    void PrintClientRecord(sClientData Client)
    {
        cout << "Account Nnumber: " << Client.AccountNumber << endl;
        cout << "Pin Code: " << Client.PinCode << endl;
        cout << "Name: " << Client.Name << endl;
        cout << "Phone: " << Client.phone << endl;
        cout << "Account Balance: " << Client.AccountBalance << endl;
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


    sClientData ReadNewClient()
    {
        sClientData ClientData;

        cout << "Enter Account Number ?  ";
        getline(cin, ClientData.AccountNumber);

        cout << "Enter Pin Code ?  ";
        getline(cin, ClientData.PinCode);

        cout << "Enter Name ?  ";
        getline(cin, ClientData.Name);

        cout << "Enter Phone ?  ";
        getline(cin, ClientData.phone);

        cout << "Enter Account Balance ?  ";
        cin >> ClientData.AccountBalance;

        return ClientData;

    }



    string ConvertRecordToLine(sClientData ClientData, string delim = "#//#")
    {
        string stClientData = "";
        stClientData += ClientData.AccountNumber + delim;
        stClientData += ClientData.PinCode + delim;
        stClientData += ClientData.Name + delim;
        stClientData += ClientData.phone + delim;
        stClientData += to_string(ClientData.AccountBalance);

        return stClientData;
    }


    void PrintClientRecordWithSetw(sClient Client)
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


    void AddNewClient()
    {
        sClientData sClient;

        sClient = ReadNewClient();

        AddDataLineToFile(ClientsFileName, ConvertRecordToLine(sClient));
    }


    void AddClients()
    {
        char AddMore = 'y';

        do
        {
            system("cls");
            cout << "Adding a New Client:\n\n";
            AddNewClient();

            cout << "\nClient Added Successfully, do you want to add more clients? y/press any key: ";
            cin >> AddMore;

        } while (tolower(AddMore) == 'y');

    }


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


    string ReadClientAccountNumber()
    {
        string AccountNumber = "";

        cout << "Please enter Account Number? ";
        cin >> AccountNumber;

        return AccountNumber;
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


    bool DeleteClientByAccountNumber(vector <sClient>& vClients, string AccountNumber)
    {
        sClient Client;
        char Answer = 'n';

        if (FindClientByAccountNumber(Client, vClients, AccountNumber))
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


    bool UpdateClientByAccountNumber(vector <sClient>& vClients, string AccountNumber)
    {
        sClient Client, NewClient;
        char Answer = 'n';

        if (FindClientByAccountNumber(Client, vClients, AccountNumber))
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



}