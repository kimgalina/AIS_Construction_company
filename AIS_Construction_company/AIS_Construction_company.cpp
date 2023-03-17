#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;

int calculating_budget(string path);

const int n = 5; // переменная для количества сотрудников (именно типа worker)
int m = 4; // количество employee не workers
string user_login, user_password;
int choice; // выбор меню
int salary_budget = calculating_budget("Salary_budget.txt");
int marketing_budget = calculating_budget("Marketing_budget3.txt");


struct Employee
{
    string name;
    string surname;
    string account_type;
    string login;
    string password;
    int salary;
};

struct Corp_worker
{
    string name;
    string surname;
    string account_type = "worker";
    string login;
    string password;
    int salary = 200; 

};

void print_menu(string path); 
void choose_option_marketer(Employee* arr, Corp_worker* arr1);/// function for marketer
void choose_option_manager(Employee* arr, Corp_worker* arr1); /// function for manager
void choose_option_main_menu(Employee* arr, Corp_worker* workers);

void change_salary(string name ,string what_to_do,Employee * arr,Corp_worker * arr1,int dif_salary)
{    // проверяем первый массив employee типа
    int check = 0; // проверяем нашелся ли сотрудник 
    for (int i = 0; i < m; i++)
    {
        if (arr[i].name == name)
        {
            check = 1;
            if (what_to_do == "increase")
            {
                arr[i].salary += dif_salary;
                cout << endl << "“Supercharge successfully made! \n Current salary for employees after the allowance: " << arr[i].salary << endl;
            }
            else if (what_to_do == "decrease")
            {
                if (arr[i].salary > dif_salary) // проеверяем уместность урезания зарплаты 
                {
                    arr[i].salary -= dif_salary;
                    cout << endl << " Pay cut successfully done! The current salary for this employee after the pay cut :" << arr[i].salary << endl;
                }
                else
                    cout << "ERROR , the amount of pay cut money is greater then the employee's salary" << endl;
            }
        }
    }
    // проверяем второй массив workers типа 
    for (int i = 0; i < n; i++)
    {
        if (arr1[i].name == name)
        {
            check = 1;
            if (what_to_do == "increase")
            {
                arr1[i].salary += dif_salary;
                cout << endl << "“Supercharge successfully made! \n Current salary for employees after the allowance: " << arr1[i].salary << endl;
            }
            else if (what_to_do == "decrease")
            {
                if (arr1[i].salary > dif_salary) // проеверяем уместность урезания зарплаты 
                {
                    arr1[i].salary -= dif_salary;
                    cout << endl << " Pay cut successfully done! The current salary for this employee after the pay cut :" << arr1[i].salary << endl;
                }
                else
                    cout << "ERROR , the amount of pay cut money is greater then the employee's salary" << endl;
            }
        }
    }
    // запишем в файл с зарплатой сотрудников новые данные
    ofstream out("Salary_budget.txt");
    for (int i = 0; i < m; i++)
    {
        out << arr[i].name << " " << arr[i].surname << " " << arr[i].account_type << " " << arr[i].salary << endl;
    }
    for (int i = 0; i < n; i++)
    {
        out << arr1[i].name << " " << arr1[i].surname << " " << arr1[i].account_type << " " << arr1[i].salary << endl;
    }

    out.close();
    salary_budget = calculating_budget("Salary_budget.txt");
    if (!check)
        cout << "ERROR , the employee with that name has not been found !" << endl;
}


void choose_option_director(Employee* arr, Corp_worker* arr1) // function for director 
{
    char exit; // для выхода из подменю
    string name;
    int dif_salary;// разница в зарплате повысить/понизить
initial_point:
    cin >> choice;
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
            print_menu("Director_menu.txt");
            goto initial_point;
        }
        break;
    case 2:
        system("cls");
        cout << "Budget for marketing >>>      " << marketing_budget << endl;
        cout << "Budget for salary    >>>      " << salary_budget << endl;
        print_menu("Salary_budget.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Director_menu.txt");
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
            print_menu("Director_menu.txt");
            goto initial_point;
        }

        break;
    case 4:// increase salary
        system("cls");

        cout << "Type the name of employee , for who's salary you want to increase  >>> ";
        cin >> name;
        cout << "how much would you like to raise the  salary ? >>> ";
        cin >> dif_salary;
        change_salary(name, "increase", arr, arr1, dif_salary);
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Director_menu.txt");
            goto initial_point;
        }
        break;
    case 5:// decrease salary
        system("cls");
        cout << "Type the name of employee , for who's salary you want to decrease  >>> ";
        cin >> name;
        cout << "how much would you like to decrease the  salary ? >>> ";
        cin >> dif_salary;
        change_salary(name, "decrease", arr, arr1, dif_salary);
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Director_menu.txt");
            goto initial_point;
        }
        break;
    case 6:
        system("cls");
        print_menu("Director_List_equipment.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Director_menu.txt");
            goto initial_point;
        }
        break;
    case 7:
        system("cls");
        print_menu("main_menu.txt");
        choose_option_main_menu(arr, arr1);
        break;
    }
}

void what_is_duty(string name) // понять какое задание по имени сотрудника 
{
    string name2;
    int i = 0;
    string duties[n]; // каждая строка это задание на одного человека
    ifstream stream("Manager_employee_duties.txt");
    // заполнение строк из файла
    while (stream.peek() != EOF)
    {
        getline(stream, duties[i]);
        i++;
    }
    string::size_type k;
    for (int j = 0; j < n; j++)
    {
        k = duties[j].find(' ', 0);// находим символ пробела с нулевой позиции строки чтобы потом вычислить имя сотрудника 
        name2 = duties[j].substr(0, k); // выделили имя в строке 
        if (name2 == name)
        {
            cout << endl << duties[j];
            break;
        }
    }
    stream.close();
}


string who_am_I(Corp_worker * arr1) // узнать имя сотрудника
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i].login == user_login)
            return arr1[i].name;
    }
}
int my_salary(Corp_worker* arr1,string name)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i].name == name)
            return arr1[i].salary;  
    }
}

void choose_option_worker(Employee * arr,Corp_worker * arr1) /// function for corp-workers
{
    string name_of_worker = who_am_I(arr1);
    char exit; // для выхода из подменю
initial_point:cin >> choice;
    switch (choice)
    {
    case 1: // какое задание 
        system("cls");
        what_is_duty(name_of_worker);
        
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Worker_menu.txt");
            goto initial_point;
        }
        break;
    case 2: // завершенные задания
        system("cls");
        print_menu("Worker_completed_tasks.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Worker_menu.txt");
            goto initial_point;
        }
        break;
    case 3: // задания над которыми сейчас работаю 
        system("cls");
        what_is_duty(name_of_worker);// сначала порученное задание показывает 
        cout << endl;
        print_menu("Worker_current_tasks.txt");
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Worker_menu.txt");
            goto initial_point;
        }
        break;
    case 4: // показать зарплату
        system("cls");
        cout << my_salary(arr1, name_of_worker);
        cout << endl << "To return to menu , enter q >>> ";
        cin >> exit;
        if (exit == 'q')
        {
            system("cls");
            print_menu("Worker_menu.txt");
            goto initial_point;
        }
        break;
    case 5:
        system("cls");
        print_menu("main_menu.txt");
        choose_option_main_menu(arr, arr1);
        break;
    }

}

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
        if (k != string::npos)// если мы нашли символы в строке из подстроки те числа 
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
    //int budget = marketing_budget;
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
        
        cout << "The entire budget for marketing is  " << marketing_budget << "$";
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
        if (promotion > marketing_budget)
        {
            cout << "Not enough budget , your total budget is  " <<  marketing_budget << endl;
            goto enter_sum;
        }
        else
        {
            marketing_budget -= promotion;
            cout << "Promotion is successful " << endl;
            cout << "Total budget is " << marketing_budget << endl;

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
    for (int i = 0; i < n; i++)
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
                print_menu("Director_menu.txt");// вывод меню для директора
                choose_option_director(arr, workers);
            }
            break;
            
        case 1:
            if (Is_autorization(arr, 1))
            {
                system("cls");
                print_menu("Marketing_menu.txt");// вывод меню маркетолога 
                choose_option_marketer(arr, workers);
            };
            break;
        case 2: 
            if (Is_autorization(arr, 2))
            {
                system("cls");
                print_menu("Manager_menu.txt");// вывод меню менеджера 
                choose_option_manager(arr, workers);
            }
            break;
        case 3: 
            if (Is_autorizationForWorker(workers))
            {

                system("cls");
                print_menu("Worker_menu.txt");// вывод меню для сотрудника
                choose_option_worker(arr, workers);
            }
            break;
        case 4: Is_autorization(arr, 3); break;
        case 5:
            system("cls");
            cout << "The program is over, we look forward to your return! " << endl; break;
        }


    }
}

void my_salary(string path,Employee * arr) // считывает данные с файла о зарплате сотрудника 
{
    ifstream in(path);

    char money_c[10];
    string str, substr = "0123456789", money;
    string::size_type k, pos = 0; 
   
    for (int i = 0; i < 4; i++)// сотрудников (не workers) всего 4
    {
        getline(in, str);
        k = str.find_first_of(substr, pos);
        money = str.substr(k, (str.length() - k));
        strcpy_s(money_c, money.c_str());
        arr[i].salary = atoi(money_c);
    }

    
    in.close();
}



int main()
{
    //setlocale(LC_ALL, "Rus");
    ifstream in1("Employee_info.txt");

    string str;
    int next, i = 0;
    Corp_worker *workers = new Corp_worker[n];// массив сотрудников 
    Employee *arr = new Employee[m]; // массив 
    while (in1.peek() != EOF) /// заносим данные по каждому сотруднику в массив 
    {
        in1 >> arr[i].name;
        in1 >> arr[i].surname;
        in1 >> arr[i].account_type;
        in1 >> arr[i].login;
        in1 >> arr[i].password;
        ++i;
    }
    in1.close();
    my_salary("Salary_budget.txt", arr);
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
