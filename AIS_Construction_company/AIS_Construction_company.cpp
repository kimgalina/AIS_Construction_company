#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string user_login, user_password;

struct Employee
{
    int num; // номер сотрудника в меню
    string account_type;
    string login;
    string password;
};

void autorization(Employee arr[],int num_of_employee)
{
    starting:cout << "Enter your login >>> " << endl;
    cin >> user_login;
    cout << "Enter your password >>> " << endl;
    cin >> user_password;
    if (user_login == arr[num_of_employee].login && user_password == arr[num_of_employee].password)
    {

        cout << "DONE !!!";


    }
    else
    {
        cout << "Login or password is wrong , please try again " << endl;
        goto starting;
    }

}


int main()
{
    //setlocale(LC_ALL, "Rus");
    ifstream in1("Employee_info.txt");

    string str;
    int choice, next, i = 0;
    Employee arr[5]; // массив сотрудников (их пять)
    while (in1.peek() != EOF) /// заносим данные по каждому сотруднику в массив 
    {
        in1 >> arr[i].num;
        in1 >> arr[i].account_type;
        in1 >> arr[i].login;
        in1 >> arr[i].password;
        ++i;
    }
    in1.close();
    /*for (int i = 0; i < 5; i++)
    {
        cout << arr[i].num << " " << arr[i].account_type << " " << arr[i].login << " " << arr[i].password << endl;
    }*/
    ifstream in2("main_menu.txt");
    while (in2.peek() != EOF)
    {
        getline(in2, str);
        cout << str << endl;

    }
    in2.close();
init_point: cin >> choice;
    if (choice > 5 || choice < 1)
    {
        cout << "Sorry, but we didn't find this type of account, please try again." << endl;
        goto init_point;
    }
    else
    {
        system("cls"); // чтобы открывалось новое окно 
        switch (choice)
        {
        case 1: autorization(arr, 0); break;
        case 2: autorization(arr, 1); break;
        case 3: autorization(arr, 2); break;
        case 4: autorization(arr, 3); break;
        case 5: autorization(arr, 4); break;
        }
        //cout << "Enter your login >>> " ;

        //cout << "Enter your password >>> ";

    }

    return 0;
}
