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

struct Corp_worker
{
    string name;
    string surname;
    string login;
    string password;

};

void print_menu(string path); 
void choose_option_marketer(Employee* arr);/// function fot marketer
void choose_option_manager(Employee* arr); /// function for manager
void choose_option_main_menu(Employee* arr, Corp_worker* workers);



int counting_strings(string path)
{
    string str;
    int count_strings = 0;
    ifstream stream1(path);
    while (stream1.peek() != EOF)
    {
        getline(stream1, str);
        count_strings++;
    }
    stream1.close();
    return count_strings; // возвращает количество строк в файле
}

void rewriting_duties(string path1,string path2)// получим файл с уже прошлыми делами и записанными недавно 
{
    int i = 0;
    int total_strings = counting_strings(path1) + counting_strings(path2);// всего строк должно быть
    string* duties = new string[total_strings];
    ifstream stream(path1);
    // заполняем массив строк данными из двух файлов
    while (stream.peek() != EOF)
    {
        getline(stream, duties[i]);
        ++i;
    }
    stream.close();
    stream.open(path2);
    while (stream.peek() != EOF)
    {
        getline(stream, duties[i]);
        ++i;
    }
    stream.close();
    // теперь записываем все данные массива в файл todo list
    ofstream out("Manager_TODO_List1.txt");
    for (int i = 0; i < total_strings; i++)
    {
        out << duties[i] << endl;
    }

    delete[]duties;
}

void choose_option_manager(Employee * arr,Corp_worker *arr1)
{
    int choice;
    char exit;
    initial_point:cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        print_menu("Manager_employee_list.txt");
        cout << endl << "To add a duty enter command 'a' or ";
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Manager_menu.txt");
            goto initial_point;
        }
        break;
    case 2:
        system("cls");
        print_menu("Manager_TODO_List1.txt");
        cout <<endl << "To add a duty enter command 'a' or ";
        cout << endl << "To return to menu , enter q >>> " ;
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Manager_menu.txt");
            goto initial_point;
        }
        else if (exit == 'a')
        {
            string duty;
            cout << endl << "Enter the name of the duty and info about it >>>";
            cin.get();// забираем символ перевода строки из потока 
            getline(cin, duty);

            ofstream out("Manager_TODO_List2.txt");
            out << endl  <<  " " << duty << endl;
            cout << "It was successfully written )";
            rewriting_duties("Manager_TODO_List1.txt", "Manager_TODO_List2.txt");
            cout << endl << "To return to menu , enter q >>> ";
            cin >> exit;
            if (exit == 'q')
            {
                system("cls");
                print_menu("Manager_menu.txt");
                goto initial_point;
            }
        }
        break;
    case 3:
        system("cls");
        print_menu("Manager_employee_duties.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Manager_menu.txt");
            goto initial_point;
        }
        break;
    case 4:
        system("cls");
        print_menu("Marketing_customer_areas1.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Marketing_menu.txt");
            goto initial_point;
        }
        break;
    case 5:
        system("cls");
        print_menu("main_menu.txt");
        choose_option_main_menu(arr,arr1);
        break;
    }

}





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



void choose_option_marketer(Employee *arr,Corp_worker * arr1)
{
    int budget = calculating_budget("Marketing_budget3.txt");
    initial_point:
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
            goto initial_point;
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
            goto initial_point;
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
            goto initial_point;
        }

        break;
    case 4:
        system("cls");
        
        cout << "The entire budget for marketing is  " << budget << "$";
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Marketing_menu.txt");
            goto initial_point;
        }
        break;
    case 5:
        system("cls");
        print_menu("Marketing_spend_budget.txt"); /// !!! продумать что будет если ввести не существуещее поле для продвижения !!!!
        int field_of_promotion,promotion;
        enter :cin >> field_of_promotion;
        if (field_of_promotion > 8 || field_of_promotion < 1)
        {
            cout << "Sorry , but there is no such category , try again " << endl;
            goto enter;
        }
        cout << endl << "Type in the amount of expense you want to spend from the budget >>> ";
        enter_sum :cin >> promotion;
        if (promotion > budget)
        {
            cout << "Not enough budget , your total budget is  " <<  budget << endl;
            goto enter_sum;
        }
        else
        {
            budget -= promotion;
            cout << "Promotion is successful " << endl;
            cout << "Total budget is " << budget << endl;

        }
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Marketing_menu.txt");
            goto initial_point;
        }

        break;
    case 6:
        system("cls");
        print_menu("main_menu.txt");
        choose_option_main_menu(arr,arr1);

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
bool Is_autorizationForWorker(Corp_worker *arr)// авторизация отдельно для сотрудников 
{
    int check = 0;
starting:cout << "Enter your login >>> " << endl;
    cin >> user_login;
    cout << "Enter your password >>> " << endl;
    cin >> user_password;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i].login == user_login && arr[i].password == user_password)
            check = 1;
    }
    if (check)
        return true;
    else
    {
        cout << "Login or password is wrong , please try again " << endl;
        goto starting;
    }
}

bool Is_autorization(Employee arr[], int num_of_employee)
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

void choose_option_main_menu(Employee* arr,Corp_worker * workers)
{
    int choice;
init_point: cin >> choice;
    if (choice > 5 || choice < 0)
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
            if (Is_autorization(arr, 0))
            {
                system("cls");
                print_menu("Marketing_menu.txt");// вывод меню маркетолога 
                choose_option_marketer(arr,workers);
            };
            break;
        case 1:
            if (Is_autorization(arr, 1))
            {
                system("cls");
                print_menu("Manager_menu.txt");// вывод меню менеджера 
                choose_option_manager(arr,workers);
            }



            break;
        case 2: Is_autorizationForWorker(workers) ; break;
        case 3: Is_autorization(arr, 2); break;
        case 4: Is_autorization(arr, 3); break;
        case 5:
            system("cls");
            cout << "The program is over, we look forward to your return! " << endl; break;
        }


    }
}


int main()
{
    //setlocale(LC_ALL, "Rus");
    ifstream in1("Employee_info.txt");

    string str;
    int next, i = 0;
    Corp_worker *workers = new Corp_worker[5];// массив сотрудников 
    Employee *arr = new Employee[4]; // массив 
    while (in1.peek() != EOF) /// заносим данные по каждому сотруднику в массив 
    {
        in1 >> arr[i].num;
        in1 >> arr[i].account_type;
        in1 >> arr[i].login;
        in1 >> arr[i].password;
        ++i;
    }
    in1.close();
    i = 0;
    in1.open("Workers_info.txt");
    while (in1.peek() != EOF) /// заносим данные по каждому сотруднику в массив 
    {
        in1 >> workers[i].name;
        in1 >> workers[i].surname;
        in1 >> workers[i].login;
        in1 >> workers[i].password;
        ++i;
    }
    in1.close();
    /*for (int i = 0; i < 5; i++)
    {
        cout << arr[i].num << " " << arr[i].account_type << " " << arr[i].login << " " << arr[i].password << endl;
    }*/
    print_menu("main_menu.txt");
    choose_option_main_menu(arr,workers);
    

    delete[] arr;
    delete[] workers;
    return 0;
}
