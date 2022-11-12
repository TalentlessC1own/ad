#include "io.h"
#include "book.h"
#include "menu.h"
#include <Windows.h>
#include <clocale>




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int userChoice = 0;
    int Size = 0;
    string fileAddress = "";
    string inputValue;
    int input2InInput = 0;
    string thirdFileAdress = "";
    ofstream thirdFile;
    ifstream file;
    file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    string secondName = "";;
    string str;;
    int i = 0;
    setlocale(LC_ALL, "Rus");
    
    cout << "Контрольная работа номер 1. Вариант 4. Бердиев Э.М. 415. Задание: Необходимо разработать класс"
        "для указанной предметной области.Доступ к данным реализовать с помощью методов Set,Get,Show." << endl;
    do { 
        cout << "Меню." << endl;
        cout << "1 - Заполнение данных" << endl;
        cout << "2 - Файловый ввод" << endl;
        cout << "3 - Выход" << endl;
        while (true)
        {
            getline(cin, inputValue);
            if (!(isNumeric(inputValue)))
            {
              
                cout << "Введено не число...Попробуй ещё раз!" << endl;
                continue;
            }
            else
            {
                userChoice = stoi(inputValue);
                break;
            }
             
        }
        //cin >> userChoice;
        //cin.get();

        if (userChoice == 1)  // ввод данных вручную
        {
            while (true)
            {
                std::cout << "Введите количествл книг " << std::endl;
                getline(cin, inputValue);
                if (!(isNumeric(inputValue)))
                {

                    cout << "Введено не число...Попробуй ещё раз!" << endl;
                    continue;
                }
                else
                {
                    Size = stoi(inputValue);
                    if (Size < 1)
                    {
                        continue;
                    }
                    break;
                }

            }
        }
        if (userChoice == 2)
        {
            while (true)
            {
                std::cout << "Введите адрес файла . " << std::endl << "ENTER : ";
                std::cin >> fileAddress;
                try
                {
                    file.open(fileAddress);
                    std::cout << "Файл успешно открыт " << std::endl;
                    break;
                }
                catch (const std::exception)
                {
                    std::cout << " Ошибка" << std::endl;

                }
            }
            cin.clear();
            cin.ignore();
            while (true)
            {
                std::cout << "Введите количествл книг " << std::endl;
                getline(cin, inputValue);
                if (!(isNumeric(inputValue)))
                {

                    cout << "Введено не число...Попробуй ещё раз!" << endl;
                    continue;
                }
                else
                {
                    Size = stoi(inputValue);
                    if (Size < 1)
                    {
                        continue;
                    }
                    break;
                }

            }
           
            /*while (!file.eof()) {
                 getline(file, str, '\n');
                 i++;
                 if (i == 6) {  
                     Size++;
                     i = 0;
                 }
            }
            cout << "Количество книг:" << endl;
            cout << Size  << endl;*/

        }
        Book* array = new Book[Size];
        switch (userChoice) {
        case keyboardInput:

            for (int i = 0; i < Size; i++) {
                string bookname, name, lastName, patronymic, publishingoffice;
                int yearOfIssue = 0;
       
                cout << "Введите название книги" << endl;
                getline(cin, bookname);

                cout << "Введите имя автора" << endl;
                getline(cin, name);

                cout << "Введите фамилию автора" << endl;
                getline(cin, lastName);

                cout << "Введите отчество автора" << endl;
                getline(cin, patronymic);

                cout << "Введите название издательства" << endl;
                getline(cin, publishingoffice);

                cout << "Введите год издания книги" << endl;
                while (true)
                {
                    getline(cin, inputValue);
                    if (!(isNumeric(inputValue)))
                    {

                        cout << "Введено не число...Попробуй ещё раз!" << endl;
                        continue;
                    }
                    else
                    {
                        yearOfIssue = stoi(inputValue);
                        break;
                    }

                }

               array[i] = Book(bookname, name, lastName, patronymic, publishingoffice,
                    yearOfIssue);
               array[i].getData();

            }
            
            /*for (int i = 0; i < Size; i++) {
                array[i].getData();
                cout << "\n" << endl;
            }*/
            cout << "1 - Сохранить данные, заданные пользователем в новый файл. " << endl;
            cout << "2 - Сохранить данные, заданные пользователем в существующий файл." << endl;
            cout << "3 и любые другие цифры - Данные,заданные пользователем не сохранятся" << endl;
            while (true)
            {
                getline(cin, inputValue);
                if (!(isNumeric(inputValue)))
                {

                    cout << "Введено не число...Попробуй ещё раз!" << endl;
                    continue;
                }
                else
                {
                    input2InInput = stoi(inputValue);
                    break;
                }

            }
           //cin >> input2InInput;
            if (input2InInput == 2) {
                cout << "Название файла:" << endl;
                cin.get();
                getline(cin, thirdFileAdress);
                thirdFile.open(thirdFileAdress, ofstream::trunc);
                for (int i = 0; i < Size; i++) {
                    thirdFile << array[i].getBookName() << endl << array[i].getName() << endl << array[i].getLastName() << endl;
                    thirdFile << array[i].getPatronymic() << endl << array[i].getPublishingOffice() << endl << array[i].getYear() << endl;
                }
                thirdFile.close();
                cout << "Файл сохранён" << endl;
            }
            else if (input2InInput == 1) {
                cout << "Название файла:" << endl;
                cin >> secondName;
                thirdFile.open(secondName);
                for (int i = 0; i < Size; i++) {
                    thirdFile << array[i].getBookName() << endl << array[i].getName() << endl << array[i].getLastName() << endl;
                    thirdFile << array[i].getPatronymic() << endl << array[i].getPublishingOffice() << endl << array[i].getYear() << endl;
                }
                cout << "Файл сохранён" << endl;
                thirdFile.close();
            }
            else if (input2InInput == 3) {
                cout << "Данные будут использованны без сохранения..." << endl;
            }

            cin.clear();
            cin.ignore();
            Submenu(array, Size);
            delete[] array;
            array = nullptr;
            break;
        case fileInput:
              
            for (int i = 0; i < Size; i++) {
                string bookname, name, lastName, patronymic, publishingoffice;
                int yearOfIssue;

                    //file >> bookname;
                    getline(file, bookname);

                    //file >> name;
                    getline(file, name);

                    //file >> lastName;
                    getline(file, lastName);

                    //file >> patronymic;
                    getline(file, patronymic);

                    getline(file, publishingoffice); ;
                   

                    getline(file, inputValue);
                    yearOfIssue = stoi(inputValue);

                    array[i] = Book(bookname, name, lastName, patronymic,
                        publishingoffice, yearOfIssue);
                
            }
            for (int i = 0; i < Size; i++) { 
                array[i].getData();
            }
            Submenu(array, Size);
            delete[] array;
            array = nullptr;
            file.close();
            break;
        case quit:
            cout << "Завершение работы ;)" << endl;
            break;
            return 0;
        default:
            cout << "Пункт не существует!!" << endl;
            break;
        }
    } while (userChoice != quit);
}

