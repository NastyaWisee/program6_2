// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <locale.h>
#include <iomanip>
using namespace std;

class Cartoon
{
    char* name;         //  название мультфильма
public:
    Cartoon(char* NAME)
    {
        name = new char[strlen(NAME) + 1];
        strcpy_s(name, strlen(NAME) + 1, NAME);
        cout << "Конструктор - Cartoon" << endl;
    }
    ~Cartoon()
    {
        delete[] name;
        cout << "деструктор класса А" << endl;
    }
    void cartoon_prnt() { cout << "Название мультфильма " << name << endl; }
};


class Discription : virtual public Cartoon
{
protected:
    char* studio;      // название мультфильм студии
    int  sesion;           // количество сезонов
public:
    Discription(char* NAME, char* STUDIO, int SESION) : Cartoon(NAME), sesion(SESION)
    {
        studio= new char[strlen(STUDIO) + 1];
        strcpy_s(studio, strlen(STUDIO) + 1, STUDIO);
        cout << "Конструктор - Discription(D1)" << endl;
    }
    ~Discription()
    {
        delete[] studio; ;
        cout << "деструктор класса D1" << endl;
    }
    void cartoon_prnt()
    {
        //Cartoon::cartoon_prnt();
        cout << "Студия, которая выпустила мультфильм " << studio << " количество сезонов " << sesion << endl;
    }
};


class Name :  virtual public Cartoon
{
protected:
    int year;        // год выпуска
    double  count;    // кол-во серий
public:
    Name(char* NAME, int YEAR, double COUNT) : Cartoon(NAME), year(YEAR), count(COUNT) 
    {
        cout << "Конструктор - Name(D2)" << endl;
    };
    ~Name() { cout << "деструктор класса D2" << endl; }

    void cartoon_prnt()
    {
        //Cartoon::cartoon_prnt();
        cout << "Год выпуска мультфильма " << year << " кол-во серий " << count << endl;
    }
};


class Genre : public Discription, public Name
{
    char* genre;       // название жанра
public: Genre(char* NAME, char* STUDIO, int SESION, int YEAR, double COUNT, char* GENRE) :
    Discription(NAME, STUDIO, SESION), Name(NAME, YEAR, COUNT), Cartoon(NAME)
{
    genre = new char[strlen(GENRE) + 1];
    strcpy_s(genre, strlen(GENRE) + 1, GENRE);
    cout << "Конструктор - Genre(D12)" << endl;
}
      ~Genre()
      {
          delete[] genre;
          cout << "деструктор класса D12" << endl;
      }


      /*
      void  cartoon_prnt()
      {
          Cartoon::cartoon_prnt();
          Discription::cartoon_prnt();
          Name::cartoon_prnt();
          cout << " Название жанра " << genre << endl;
      }
      */
};


int main()
{
    setlocale(LC_ALL, "Russian");
    char* name = new char[20];
    cout << "Введите название мультфильма" << endl;
    cin >> name;

    char* col = new char[20];
    cout << "Введите студию мультфильма" << endl;
    cin >> col;


    char* nm = new char[20];
    cout << "Введите название жанра" << endl;
    cin >> nm;

    int ses = 0;
    cout << "Введите кол-во сезонов" << endl;
    while (!(cin >> ses))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите ещё раз: ";
    }

    int god = 0;
    cout << "Введите год выпуска" << endl;
    while (!(cin >> god))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите ещё раз: ";
    }

    int coun = 0;
    cout << "Введите кол-во серий" << endl;
    while (!(cin >> coun))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите ещё раз: ";
    }


    Genre cart(name, col, ses, god, coun, nm); // объект класса Genre
   Genre* ptr = &cart; // указатель на созданный объект. Далее можно использовать для вызова методов либо сам объект cart, либо указатель на него pt 
   cart.Cartoon::cartoon_prnt();
   cart.Discription::cartoon_prnt();
   cart.Name::cartoon_prnt();
    //pt->cartoon_prnt();
    //pt->cartoon_prnt();
    //pt->genre_prnt();

   
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
