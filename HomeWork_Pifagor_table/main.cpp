#include <iostream>
#include <locale.h>
#include <windows.h> //Для STD_OUTPUT_HANDLE
#include <conio.h> //Для функции _getch()
using namespace std;
using std::cout;
using std::cin;
using std::setlocale;
using std::endl;

void Pifagor_table();
void geo_square();
void geo_triangle_1();
void geo_triangle_2();
void geo_triangle_3();
void geo_triangle_4();
void geo_rhomb();
void chess_square();
int main_menu();

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, spase = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
const int SIZE_MENU = 9;

void SetCursor(int x, int y)
{
    COORD myCoords = { x, y };
    SetConsoleCursorPosition(hStdOut, myCoords);
}

void main()
{
    setlocale(LC_ALL, "Russian");

    int poz = 0;
    poz = main_menu();
    bool exit = false;
    while (exit == false)
    {
        switch (poz)
        {
        case 0: Pifagor_table();            break;
        case 1: geo_square();               break;
        case 2: geo_triangle_1();           break;
        case 3: geo_triangle_2();           break;
        case 4: geo_triangle_3();           break;
        case 5: geo_triangle_4();           break;
        case 6: geo_rhomb();                break;
        case 7: chess_square();             break;
        case 8: exit = true; cout << endl;
        }
    }
    cout << "Вы покидаете программу.";
}

int main_menu()
{
    system("cls");
    cout << "\n\n\n\t\t***ДОМАШНЯЯ РАБОТА***\n\n";
    cout << "\t\tсостоит из нескольких задач на вложенные циклы FOR\n";
    int poz = 0, key;
    char menu[SIZE_MENU][100] =
    {
        "Таблица Пифагора",
        "Задачка 1 (Квадрат)",
        "Задачка 2 (Треугольник с левым нижним прямым углом)",
        "Задачка 3 (Треугольник с левым верхним прямым углом)",
        "Задачка 4 (Треугольник с правым верхним прямым углом)",
        "Задачка 5 (Треугольник с правым нижним прямым углом)",
        "Задачка 6 (Ромб)",
        "Задачка 7 (Квадрат с символами в шахматном порядке)",
        "Выход"
    };
    for (int i = 0; i < SIZE_MENU; i++)
    {
        SetCursor(10, 10 + i);
        cout << menu[i];
    }
    do {
        for (int i = 0; i < SIZE_MENU; i++)
        {
            SetCursor(8, 10 + i);
            if (i == poz)
            {
                SetCursor(7, 10 + i);
                cout << "=> ";
            }
            else
            {
                SetCursor(7, 10 + i);
                cout << "   ";
            }
            cout << menu[i];
        }
        key = _getch();
        switch (key)
        {
        case Up: if (--poz < 0) poz = SIZE_MENU - 1; break;
        case Down: if (++poz > SIZE_MENU - 1) poz = 0; break;
        case Enter: return(poz);
        }
    } while (key != esc);
}

void Pifagor_table()
{
    system("cls");
    int size_cell = 2, size_table;
    cout << "\n\n\t\t***ТАБЛИЦА ПИФАГОРА***"
        << "\n\n\tВведите число, до которого нужно создать таблицу Пифагора: ";
    cin >> size_table;
    int tmp = size_table * size_table;
    while (tmp / 10 != 0)
    {
        size_cell++;
        tmp /= 10;
    }
    setlocale(LC_ALL, "C");
                            // 1 raw
    cout << '\t' << char(201);
    for (int i = 1; i <= size_cell; i++) cout << char(205);
    cout << char(209);
    for (int cell = 0; cell < size_table; cell++)
    {
        for (int i = 0; i < size_cell; i++) cout << char(205);
    }
    cout << char(187) << endl;
                            //2 raw
    cout << '\t' << char(186);
    printf("%*.c", size_cell, ' ');
    cout << char(179);
    for (int cell = 1; cell <= size_table; cell++)
    {
        printf("%*.d", size_cell, cell);
    }
    cout << char(186) << endl;
                            //3 raw
    cout << '\t' << char(199);
    for (int i = 0; i < size_cell; i++) cout << char(196);
    cout << char(197);
    for (int cell = 0; cell < size_table; cell++)
    {
        for (int i = 0; i < size_cell; i++) cout << char(196);
    }
    cout << char(182) << endl;
                            //All raws
    for (int raw = 1; raw <= size_table; raw++)
    {
        cout << '\t' << char(186);
        printf("%*.d", size_cell, raw);
        cout << char(179);
        for (int cell = 1; cell <= size_table; cell++)
        {
            printf("%*.d",size_cell, cell * raw);
        }
        cout << char(186) << endl;
    }
                            //Last raw
    cout << '\t' << char(200);
    for (int i = 1; i <= size_cell; i++) cout << char(205);
    cout << char(207);
    for (int cell = 0; cell < size_table; cell++)
    {
        for (int i = 0; i < size_cell; i++) cout << char(205);
    }
    cout << char(188) << endl;
    setlocale(LC_ALL, "Russian");
    cout << "Для возврата в главное меню нажмите клавишу \"esc\"";
    if (_getch() == esc) main();
}

void geo_square()
{
    system("cls");
    cout << "\t\t***ВЫВОД ГЕОМЕТРИЧЕСКИХ ФИГУР***\nЗадача 1 (квадрат)\nВведите размер фигуры: ";
    int size;
    char SYMBOL = '*';
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << SYMBOL;
        }
        cout << endl;
    }
    cout << "Для возврата в главное меню нажмите клавишу \"esc\"";
    if (_getch() == esc) main();
}

void geo_triangle_1()
{
    system("cls");
    cout << "\t\t***ВЫВОД ГЕОМЕТРИЧЕСКИХ ФИГУР***\nЗадача 2 (треугольник с прямым углом слева внизу)\nВведите размер фигуры: ";
    int size;
    char SYMBOL = '*';
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << SYMBOL;
        }
        cout << endl;
    }
    cout << "Для возврата в главное меню нажмите клавишу \"esc\"";
    if (_getch() == esc) main();
}

void geo_triangle_2()
{
    system("cls");
    cout << "\t\t***ВЫВОД ГЕОМЕТРИЧЕСКИХ ФИГУР***\nЗадача 3 (треугольник с прямым углом слева вверху)\nВведите размер фигуры: ";
    int size;
    char SYMBOL = '*';
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            cout << SYMBOL;
        }
        cout << endl;
    }
    cout << "Для возврата в главное меню нажмите клавишу \"esc\"";
    if (_getch() == esc) main();
}

void geo_triangle_3()
{
    system("cls");
    cout << "\t\t***ВЫВОД ГЕОМЕТРИЧЕСКИХ ФИГУР***\nЗадача 4 (треугольник с прямым углом справа вверху)\nВведите размер фигуры: ";
    int size;
    char SYMBOL = '*';
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        for (int k = i; k < size; k++)
        {
            cout << SYMBOL;
        }
        cout << endl;
    }
    cout << "Для возврата в главное меню нажмите клавишу \"esc\"";
    if (_getch() == esc) main();
}

void geo_triangle_4()
{
    system("cls");
    cout << "\t\t***ВЫВОД ГЕОМЕТРИЧЕСКИХ ФИГУР***\nЗадача 5 (треугольник с прямым углом справа внизу)\nВведите размер фигуры: ";
    int size;
    char SYMBOL = '*';
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << ' ';
        }
        for (int k = size - i; k <= size; k++)
        {
            cout << SYMBOL;
        }
        cout << endl;
    }
    cout << "Для возврата в главное меню нажмите клавишу \"esc\"";
    if (_getch() == esc) main();
}

void geo_rhomb()
{
    system("cls");
    cout << "\t\t***ВЫВОД ГЕОМЕТРИЧЕСКИХ ФИГУР***\nЗадача 5 (ромб)\nВведите размер фигуры: ";
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << ' ';
        }
        cout << '/';
        for (int k = 0; k < 2 * i; k++)
        {
            cout << ' ';
        }
        cout << '\\' << endl;
    }
    for (int l = 0; l < size; l++)
    {
        for (int m = 0; m < l; m++)
        {
            cout << ' ';
        }
        cout << '\\';
        for (int n = 0; n < 2 * (size - l - 1); n++)
        {
            cout << ' ';
        }
        cout << '/' << endl;
    }
    cout << "Для возврата в главное меню нажмите клавишу \"esc\"";
    if (_getch() == esc) main();
}

void chess_square()
{
    system("cls");
    cout << "\t\t***ВЫВОД ГЕОМЕТРИЧЕСКИХ ФИГУР***\nЗадача 6 (квадрат из символов в шахматном порядке)\nВведите размер фигуры: ";
    int size;
    char SYMBOL_1 = '+', SYMBOL_2 = '-';
    bool flag = true;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            flag ? cout << SYMBOL_1 : cout << SYMBOL_2;
            flag = !flag;
        }
        if (size % 2 == 0) flag = !flag;
        cout << endl;
    }
    cout << "Для возврата в главное меню нажмите клавишу \"esc\"";
    if (_getch() == esc) main();
}