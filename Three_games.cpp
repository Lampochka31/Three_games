#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#pragma execution_character_set("utf-8")

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;

    do
    {
        cout << "\nМенюшка:)\n";
        cout << "1. Игра \"Угадай число\"\n";
        cout << "2. Таблица умножения\n";
        cout << "3. Вывод делителей числа\n";
        cout << "0. Выход из программы\n";

        cout << "\nВведите пункт: ";
        if (!(cin >> choice))
        {
            cout << "\nОшибка! Нужно ввести число.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch (choice)
        {
            // ИГРА "УГАДАЙ ЧИСЛО"
        case 1:
        {
            int randomNumber;
            int number;

            srand(time(0));
            randomNumber = rand() % 101;
            cout << "\n Игра \"Угадай число\" \n";

            do
            {
                cout << "Введите число от 0 до 100: ";
                cin >> number;

                if (number < randomNumber)
                {
                    cout << "Загаданное число больше.\n";
                }
                else if (number > randomNumber)
                {
                    cout << "Загаданное число меньше.\n";
                }
                else
                {
                    cout << "Поздравляем! Вы угадали число!\n";
                }

            } while (number != randomNumber);

            break;
        }
        // ТАБЛИЦА УМНОЖЕНИЯ
        case 2:
        {
            int table[10][10]{};

            cout << "\n Таблица умножения \n";

            // Двумерный массив.
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    table[i][j] = (i + 1) * (j + 1);
                }
            }

            // Выводим двумерный массив
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    cout << table[i][j] << "\t";
                }

                cout << endl;
            }

            break;
        }

        // ДЕЛИТЕЛИ ЧИСЛА
        case 3:
        {
            int number;

            cout << "\n Вывод делителей числа \n";
            cout << "Введите число: ";
            cin >> number;

            cout << "Делители числа " << number << ": ";

            for (int i = 1; i <= number; i++)
            {
                if (number % i == 0)
                {
                    cout << i << " ";
                }
            }

            cout << endl;

            break;
        }


        case 0:
        {
            cout << "\nОбратно в меню.\n";
            break;
        }


        // игнор букв и не тех команд
        default:
        {
            cout << "\nОшибочка вышла! Такого пункта нет.\n";

            break;
        }
        }

    } while (choice != 0);

    return 0;
}