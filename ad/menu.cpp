#include "io.h"
#include "book.h"
#include <iostream>


bool isNumeric(std::string const& str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

void Subsubmenu(Book array[], int Size)
{
    string inputValue;
    int thirdChoice = 0;
    string secondFileAddress = "";
    int inputinInput = 0;
    do {
        cout << "1 - ��������� ������ � ����" << endl;
        cout << "2 - ��������� � �������" << endl;
        while (true)
        {
            getline(cin, inputValue);
            if (!(isNumeric(inputValue)))
            {

                cout << "������� �� �����...�������� ��� ���!" << endl;
                continue;
            }
            else
            {
                thirdChoice = stoi(inputValue);
                break;
            }

        }
        ofstream secondFile;
        switch (thirdChoice) {
        case saveDataOld:
            cout << "1 - C�������� ��������� � ������������ ����" << endl;
            cout << "2 - ��������� ��������� � ����� ����" << endl;
            while (true)
            {
                getline(cin, inputValue);
                if (!(isNumeric(inputValue)))
                {

                    cout << "������� �� �����...�������� ��� ���!" << endl;
                    continue;
                }
                else
                {
                    inputinInput = stoi(inputValue);
                    break;
                }

            }
            if (inputinInput == 1) {
                cout << "�������� �����:" << endl;
                cin.get();
                getline(cin, secondFileAddress);
                secondFile.open(secondFileAddress, ofstream::trunc);
                for (int i = 0; i < Size; i++) {

                    secondFile << array[i].getBookName() << endl << array[i].getName() << endl << array[i].getLastName() << endl;
                    secondFile << array[i].getPatronymic() << endl << array[i].getPublishingOffice() << endl;
                    secondFile << array[i].getYear() << endl;

                }
                secondFile.close();
                cout << "���� �������" << endl;
            }
            else if (inputinInput == 2) {
                string nameFile = "";
                cout << "�������� �����:" << endl;
                cin >> nameFile;
                secondFile.open(nameFile);
                if (secondFile.is_open()) {
                    for (int i = 0; i < Size; i++) {

                        secondFile << array[i].getBookName() << endl << array[i].getName() << endl << array[i].getLastName() << endl;
                        secondFile << array[i].getPatronymic() << endl << array[i].getPublishingOffice() << endl;
                        secondFile << array[i].getYear() << endl;
                    }
                }
                else {
                    cout << "�������� �� �������..." << endl;
                }
                secondFile.close();
                cout << "���� �������!" << endl;
            }
            else {
                cout << "������ ������ �� ����������..." << endl;
            }
            break;
        case notSaveDate:
            cout << "������ �� ����� ���������..." << endl;
            break;
        default:
            cout << "����� ����� � ���� �� ����������!" << endl;
            break;
        }
    } while (thirdChoice != notSaveDate);
}


void Submenu(Book array[], int Size)
{
    string inputValue;
    int secondChoice = 0;
    string NameAuthor = "";
    string LastNameAuthor = "";
    string PatronymicAuthor = "";
    string NameOfPublishingOffice = "";
    int minYearOfIssue = 0;
    Book* resultArray = 0;
    int resultSize = 0;
    do {
        cout << "����� ���� �������." << endl;
        cout << "1 - ������ ����,�� ����� ������. " << endl;
        cout << "2 - ������ ����,�� ������������." << endl;
        cout << "3 - ������ ����,���������� ����� ��������� ����." << endl;
        cout << "4 - ������� � ���������� ����." << endl;
        while (true)
        {
            getline(cin, inputValue);
            if (!(isNumeric(inputValue)))
            {

                cout << "������� �� �����...�������� ��� ���!" << endl;
                continue;
            }
            else
            {
                secondChoice = stoi(inputValue);
                break;
            }

        }
        switch (secondChoice) {
        case listOfBooksByAuthor:
            resultSize = 0;
            cin.get();
            cout << "������� ��� ������" << endl;
            getline(cin,NameAuthor);
            cout << "������� ������� ������" << endl;
            getline(cin,LastNameAuthor);
            cout << "������� �������� ������" << endl;
            getline(cin,PatronymicAuthor);
            for (int i = 0; i < Size; i++) {
                if (array[i].getName() == NameAuthor and array[i].getLastName() == LastNameAuthor
                    and array[i].getPatronymic() == PatronymicAuthor)
                {
                    array[i].getData();
                    resultSize++;
                }
            }
            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) {
                if (array[i].getName() == NameAuthor and array[i].getLastName() == LastNameAuthor
                    and array[i].getPatronymic() == PatronymicAuthor) {
                    resultArray[j] = array[i];
                    j++;
                }
            }
            Subsubmenu(resultArray, resultSize);
            break;
        case listOfBooksByPublishingOffice:
            resultSize = 0;
            cout << "������� �������� ������������" << endl;
            cin.get();
            getline(cin,NameOfPublishingOffice);
            for (int i = 0; i < Size; i++) {
                if (array[i].getPublishingOffice() == NameOfPublishingOffice) {
                    array[i].getData();
                    resultSize++;
                }
            }
            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) {
                if (array[i].getPublishingOffice() == NameOfPublishingOffice) {
                    resultArray[j] = array[i];
                    j++;
                }
            }
            Subsubmenu(resultArray, resultSize);
            break;
        case listOfBooksByYearOfIssue:
            resultSize = 0;
            cout << "������� ��� ����� �������� ���� ������ �����" << endl;
            while (true)
            {
                getline(cin, inputValue);
                if (!(isNumeric(inputValue)))
                {

                    cout << "������� �� �����...�������� ��� ���!" << endl;
                    continue;
                }
                else
                {
                    minYearOfIssue = stoi(inputValue);
                    break;
                }

            }
            for (int i = 0; i < Size; i++) {
                if (array[i].getYear() >= minYearOfIssue) {
                    array[i].getData();
                    resultSize++;

                }
                else {
                    cout << "��� ���� �������� ����� ����� ����..." << endl;
                }
            }
            resultArray = new Book[resultSize];
            for (int i = 0, j = 0; i < Size; i++) {
                if (array[i].getYear() >= minYearOfIssue) {
                    resultArray[j] = array[i];
                    j++;
                }
            }
            Subsubmenu(resultArray, resultSize);
        case backToTheBeginning:
            cout << "����������� � ������..." << endl;
            break;
        default:
            cout << "����� � ���� �� ����������!" << endl;
            break;
        }

    } while (secondChoice != backToTheBeginning);
};