#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;

string user_login, user_password;

struct Employee
{
    int num; // номер сотрудника в меню
    string account_type;
    string login;
    string password;
};

int calculating_budget(string path)
{
    int budget = 0;
    char money_c[10];
    string str,substr = "0123456789",money;
    string::size_type k, pos = 1; // так как в файле идет нумерация мы будем пропускать нумерацию и искать сумму бюджета
    ifstream inn(path);
    while (inn.peek() != EOF)
    {
        getline(inn, str);
        
        k = str.find_first_of(substr, pos);
        if (k != string::npos)
        {
            money = str.substr(k, str.length() - k);
            //cout << money << " ";
            strcpy_s(money_c, money.c_str()); // переводим string в строку си 
            budget += atoi(money_c);
        }

    }
    
    inn.close();
    return budget;
}


void print_menu(string path);

void choose_option_marketer()
{
    int choice;
    cin >> choice;
    
    char exit;
    switch (choice)
    {
    case 1:
        system("cls");
        print_menu("Marketing_customer_areas1.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Marketing_menu.txt");
            choose_option_marketer();
        }
        break;
    case 2:
        system("cls");
        print_menu("Marketing_categories2.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Marketing_menu.txt");
            choose_option_marketer();
        }
        break;

    case 3:
        system("cls");
        print_menu("Marketing_budget3.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Marketing_menu.txt");
            choose_option_marketer();
        }

        break;
    case 4:
        system("cls");
        cout << "The entire budget for marketing is  " << calculating_budget("Marketing_budget3.txt") << "$";
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Marketing_menu.txt");
            choose_option_marketer();
        }
        break;
    case 5:
        break;
    case 6:
        break;
    }
}

void print_menu(string path)
{
    string str;
    ifstream in3(path);
    while (in3.peek() != EOF)
    {
        getline(in3, str);
        cout << str << endl;
    }
    in3.close();
    
}


bool autorization(Employee arr[],int num_of_employee)
{
    starting:cout << "Enter your login >>> " << endl;
    cin >> user_login;
    cout << "Enter your password >>> " << endl;
    cin >> user_password;
    if (user_login == arr[num_of_employee].login && user_password == arr[num_of_employee].password)
    {
        return true;
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
    print_menu("main_menu.txt");
    
    
init_point: cin >> choice;
    if (choice > 4 || choice < 0)
    {
        cout << "Sorry, but we didn't find this type of account, please try again." << endl;
        goto init_point;
    }
    else
    {
        system("cls"); // чтобы открывалось новое окно 
        switch (choice)
        {
        case 0: 
            if (autorization(arr, 0))
            {
                system("cls");
                print_menu("Marketing_menu.txt");// вывод меню маркетолога 
                
                choose_option_marketer();

                





                
            }; break;
        case 1: autorization(arr, 1); break;
        case 2: autorization(arr, 2); break;
        case 3: autorization(arr, 3); break;
        case 4: autorization(arr, 4); break;
        }
        

    }

    return 0;
}
