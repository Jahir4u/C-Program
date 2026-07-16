#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<ctype.h>
#define max 50
using namespace std;

int num = 0;
void gotoXY(int, int);
void Cdelay(int);
void border(int, int, int, int);
void borderNoDelay(int, int, int, int);
void loginFrame(int, int, int, int);
void intro();
void login();
void menu();
void insert();
void edit();
void editmenu();
void editname(int);
void editcode(int);
void editdes(int);
void editexp(int);
void editage(int);
void editsalary(int);
void list();
void deletes();
void search();
void setWindowSize(int, int);
void saverecords();
void getrecords();
bool isFilePresent();
void displayPayslip();

class employce
{
public:
    char name[20];
    int code;
    char designation[20];
    int exp;
    int age;
    int salary;
    char AnyLoan;
    int HRA;
    int PF;
    int tax;
    int MealAllowance;
    int TransportAllowance;
    int MedicalAllowance;
    int LoanBalance;
    int LoanDebit;
    int grosspay;
    int workingHours;
    int DA;
};

employce emp[max], tempemp[max];

void getrecords()
{
    FILE* fp;
    fp = fopen("Records.txt", "r");
    int c = 0;
    if (fp != NULL)
    {
        while (fscanf(fp, "%s %d %s %d %d %d %c %d %d %d %d %d %d %d %d %d %d %d",
            emp[c].name,
            &emp[c].code,
            emp[c].designation,
            &emp[c].exp,
            &emp[c].age,
            &emp[c].salary,
            &emp[c].AnyLoan,
            &emp[c].HRA,
            &emp[c].PF,
            &emp[c].tax,
            &emp[c].MealAllowance,
            &emp[c].TransportAllowance,
            &emp[c].MedicalAllowance,
            &emp[c].LoanBalance,
            &emp[c].LoanDebit,
            &emp[c].grosspay,
            &emp[c].workingHours,
            &emp[c].DA) != EOF)
        {
            c++;
        }
        num = c;
        fclose(fp);
    }
}

void saverecords()
{
    if (num == 0)
    {
        remove("Records.txt");
    }
    else
    {
        FILE* fp;
        fp = fopen("Records.txt", "w");
        for (int i = 0; i < num; i++)
        {
            fprintf(fp, "%s %d %s %d %d %d %c %d %d %d %d %d %d %d %d %d %d %d\n",
                emp[i].name, emp[i].code, emp[i].designation, emp[i].exp,
                emp[i].age, emp[i].salary, emp[i].AnyLoan, emp[i].HRA, emp[i].PF,
                emp[i].tax, emp[i].MealAllowance, emp[i].TransportAllowance,
                emp[i].MedicalAllowance, emp[i].LoanBalance, emp[i].LoanDebit,
                emp[i].grosspay, emp[i].workingHours, emp[i].DA);
        }
        fclose(fp);
    }
}

void Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
}

void gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void borderNoDelay(int xLenS = 2, int yLenS = 2, int xLenE = 75, int yLenE = 24)
{
    system("cls");
    gotoXY(xLenS, yLenS); printf("%c", 201);
    gotoXY(xLenS, yLenE); printf("%c", 200);
    for (int i = xLenS + 1; i <= xLenE - 1; i++)
    {
        gotoXY(i, yLenS);
        printf("%c", 205);
        gotoXY(i, yLenE);
        printf("%c", 205);
    }
    gotoXY(xLenE, yLenS); printf("%c", 187);
    gotoXY(xLenE, yLenE); printf("%c", 188);
    for (int i = yLenS + 1; i <= yLenE - 1; i++)
    {
        gotoXY(xLenS, i);
        printf("%c", 186);
        gotoXY(xLenE, i);
        printf("%c", 186);
    }
    printf("\n\n");
}

void border(int xLenS = 2, int yLenS = 2, int xLenE = 75, int yLenE = 22)
{
    system("cls");
    gotoXY(xLenS, yLenS); printf("%c", 201);
    gotoXY(xLenS, yLenE); printf("%c", 200);
    for (int i = xLenS + 1; i <= xLenE - 1; i++)
    {
        Cdelay(15);
        gotoXY(i, yLenS);
        printf("%c", 205);
        gotoXY(i, yLenE);
        printf("%c", 205);
    }
    gotoXY(xLenE, yLenS); printf("%c", 187);
    gotoXY(xLenE, yLenE); printf("%c", 188);
    for (int i = yLenS + 1; i <= yLenE - 1; i++)
    {
        Cdelay(15);
        gotoXY(xLenS, i);
        printf("%c", 186);
        gotoXY(xLenE, i);
        printf("%c", 186);
    }
    printf("\n\n");
}

void loginFrame(int xLenS = 18, int yLenS = 8, int xLenE = 55, int yLenE = 15)
{
    border(xLenS, yLenS, xLenE, yLenE);
}

void intro()
{
    getch();
    gotoXY(20, 4); printf("PAYROLL MANAGEMENT SYSTEM");
    gotoXY(15, 5); for (int i = 0; i < 37; i++) printf("%c", 196);
    gotoXY(20, 8); printf("Designed and Programmed by:");
    gotoXY(20, 9); for (int i = 0; i < 27; i++) printf("%c", 196);
    gotoXY(20, 11); printf("Jahir Alom , by the help of teacher");
    gotoXY(20, 13); printf(" from D.K College, Mirza");
    gotoXY(20, 15); printf("For my experience");
    gotoXY(15, 16); for (int i = 0; i < 40; i++) printf("%c", 196);
    gotoXY(24, 19); printf("Press Any key to continue..");
    getch();
}

void login()
{
    while (1) {
        char UserName[30], Password[30], ch; int i = 0;
        system("cls");
        loginFrame();
        gotoXY(20, 10);
        printf("Enter UserName  : ");
        cin >> UserName;
        gotoXY(20, 12);
        cout << "Enter Password  : ";
        while (1)
        {
            ch = getch();
            if (ch == 13) break;
            if (ch == 32 || ch == 9) continue;
            else {
                cout << "*";
                Password[i] = ch;
                i++;
            }
        }
        Password[i] = '\0';

        if (strcmp(UserName, "jahir07") == 0 && strcmp(Password, "jahir@786") == 0)
        {
            system("cls");
            loginFrame();
            gotoXY(27, 10);
            cout << "Login Success!!!";
            getch();
            break;
        }
        else
        {
            system("cls");
            loginFrame();
            gotoXY(27, 10);
            printf("Access Denied!!!\a");
            getch();
        }
    }
}

void insert()
{
    borderNoDelay();
    int i = num;
    int sal, PF, TAX, HRA, MealA, MedicalA, TransportA, LoanBal, LoanDeb, h, DA;
    char loan;
    num += 1;
    gotoXY(28, 4);
    printf("Insert New Record");
    gotoXY(10, 6);
    cout << "Name : ";
    cin >> emp[i].name;
    gotoXY(10, 8);
    cout << "Code: ";
    cin >> emp[i].code;
    gotoXY(10, 10);
    cout << "Designation :";
    cin >> emp[i].designation;
    gotoXY(10, 12);
    cout << "Years of Experience: ";
    cin >> emp[i].exp;
    gotoXY(10, 14);
    cout << "Age :";
    cin >> emp[i].age;
    gotoXY(10, 16);
    cout << "Enter Working Hours :";
    cin >> h;
    sal = h * 300;
    emp[i].workingHours = h;
    do
    {
        gotoXY(10, 18);
        cout << "Any Loan (Y/N) ?: \b\b";
        loan = getche();
        if (loan == 'Y' || loan == 'y' || loan == 'n' || loan == 'N')
            break;
    } while (1);
    if (loan == 'y' || loan == 'Y')
    {
        gotoXY(10, 20);
        cout << "Enter Loan Balance:  ";
        cin >> LoanBal;
    }
    else
    {
        LoanBal = 0;
    }
    gotoXY(14, 22);
    cout << "Recorded Successfully..!";
    TAX = 0.04 * sal;
    DA = 1.20 * sal;
    PF = 0.12 * sal;
    HRA = sal * 0.27;
    MealA = 300;
    MedicalA = 300;
    TransportA = 300;
    LoanDeb = sal * 0.09;
    if (LoanDeb > LoanBal)
    {
        LoanDeb = LoanBal;
        LoanBal = 0;
    }
    emp[i].salary = sal;
    emp[i].DA = DA;
    emp[i].tax = TAX;
    emp[i].PF = PF;
    emp[i].HRA = HRA;
    emp[i].MealAllowance = MealA;
    emp[i].MedicalAllowance = MedicalA;
    emp[i].TransportAllowance = TransportA;
    emp[i].LoanBalance = LoanBal - LoanDeb;
    emp[i].AnyLoan = loan;
    emp[i].LoanDebit = LoanDeb;
    emp[i].grosspay = (sal + MealA + MedicalA + TransportA + HRA + DA) - (PF + TAX + LoanDeb);

    saverecords();
    getch();
}

void list()
{
    borderNoDelay();
    gotoXY(20, 4);
    printf("******** List of the Employees *******");
    gotoXY(6, 6);
    cout << "Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary" << endl;
    gotoXY(6, 7);
    cout << "__________________________________________________________" << endl;
    for (int i = 0, j = 8; i <= num - 1; i++, j++)
    {
        gotoXY(6, j);
        cout << emp[i].name;
        gotoXY(19, j);
        cout << emp[i].code;
        gotoXY(26, j);
        cout << emp[i].designation;
        gotoXY(44, j);
        cout << emp[i].exp;
        gotoXY(56, j);
        cout << emp[i].age;
        gotoXY(64, j);
        cout << emp[i].grosspay;
    }
    getch();
}

void deletes()
{
    for (int i = 0; i < num; i++)
    {
        tempemp[i] = emp[i];
    }
    borderNoDelay();
    int code;
    int check = -1;
    gotoXY(28, 4);
    printf("Delete a Record");
    gotoXY(10, 6);
    cout << "Enter the JobCode To Delete That Record :";
    cin >> code;
    int i, j;
    for (i = 0; i <= num - 1; i++)
    {
        if (emp[i].code == code)
        {
            check = i;
        }
    }
    if (check != -1)
    {
        for (i = 0, j = 0; i <= num - 1; i++, j++)
        {
            if (i == check)
            {
                i++;
            }
            emp[j] = tempemp[i];
        }
        num--;
        saverecords();
    }
}

void search()
{
    borderNoDelay();
    int jobcode;
    bool found = false;
    gotoXY(10, 4);
    cout << "You can Search only through the Jobcode of an Employee";
    gotoXY(10, 6);
    cout << "Enter Code Of the Employee :";
    cin >> jobcode;
    for (int i = 0; i <= num - 1; i++)
    {
        if (emp[i].code == jobcode)
        {
            gotoXY(6, 8);
            cout << "Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary " << endl;
            gotoXY(6, 9);
            cout << "_____________________________________________________" << endl;
            gotoXY(6, 11);
            cout << emp[i].name;
            gotoXY(19, 11);
            cout << emp[i].code;
            gotoXY(26, 11);
            cout << emp[i].designation;
            gotoXY(45, 11);
            cout << emp[i].exp;
            gotoXY(56, 11);
            cout << emp[i].age;
            gotoXY(64, 11);
            cout << emp[i].grosspay;
            found = true;
        }
    }
    if (!found)
    {
        gotoXY(26, 11);
        cout << "No records Found..!!!\a";
    }
    getch();
}

void editmenu()
{
    borderNoDelay();
    gotoXY(28, 4);
    printf("Edit An Entry");
    gotoXY(10, 6);
    cout << "What Do You Want To edit";
    gotoXY(12, 8);
    cout << "n -----> Name ";
    gotoXY(12, 9);
    cout << "c -----> Code ";
    gotoXY(12, 10);
    cout << "d -----> Designation";
    gotoXY(12, 11);
    cout << "e -----> Experience ";
    gotoXY(12, 12);
    cout << "a -----> Age";
    gotoXY(12, 13);
    cout << "s -----> Salary";
    gotoXY(12, 14);
    cout << "q -----> QUIT";
    gotoXY(10, 16);
    cout << "Enter Choice ---->>> ";
}

void editname(int i)
{
    gotoXY(10, 18);
    cout << "Enter New Name----> ";
    cin >> emp[i].name;
}

void editcode(int i)
{
    gotoXY(10, 18);
    cout << "Enter New Job Code---->";
    cin >> emp[i].code;
}

void editdes(int i)
{
    gotoXY(10, 18);
    cout << "Enter new designation-----> ";
    cin >> emp[i].designation;
}

void editexp(int i)
{
    gotoXY(10, 18);
    cout << "Enter new Years of Experience------>";
    cin >> emp[i].exp;
}

void editage(int i)
{
    gotoXY(10, 18);
    cout << "Enter new Age-------> ";
    cin >> emp[i].age;
}

void editsalary(int i)
{
    int sal, PF, TAX, HRA, MealA, MedicalA, TransportA, LoanBal = emp[i].LoanBalance, LoanDeb, DA;
    gotoXY(10, 18);
    cout << "Enter new Salary--------> ";
    cin >> sal;
    DA = 1.20 * sal;
    TAX = 0.04 * sal;
    PF = 0.12 * sal;
    HRA = 4000;
    MealA = 300;
    MedicalA = 300;
    TransportA = 300;
    LoanDeb = sal * 0.09;
    if (LoanDeb > LoanBal)
    {
        LoanDeb = LoanBal;
        LoanBal = 0;
    }
    emp[i].salary = sal;
    emp[i].tax = TAX;
    emp[i].PF = PF;
    emp[i].HRA = HRA;
    emp[i].MealAllowance = MealA;
    emp[i].MedicalAllowance = MedicalA;
    emp[i].TransportAllowance = TransportA;
    emp[i].LoanBalance = LoanBal;
    emp[i].LoanDebit = LoanDeb;
    emp[i].grosspay = (sal + MealA + MedicalA + TransportA + HRA + DA) - (PF + TAX + LoanDeb);
}

void edit()
{
    borderNoDelay();
    int jobcode;
    gotoXY(28, 4);
    printf("Edit a Record");
    int i;
    gotoXY(10, 6);
    cout << "Enter the jobcode To Edit: ";
    cin >> jobcode;
    for (i = 0; i <= num - 1; i++)
    {
        if (emp[i].code == jobcode)
        {
            char option;
            while (true)
            {
                editmenu();
                cin >> option;
                switch (option)
                {
                case 'n': editname(i); break;
                case 'c': editcode(i); break;
                case 'd': editdes(i); break;
                case 'e': editexp(i); break;
                case 'a': editage(i); break;
                case 's': editsalary(i); break;
                case 'q': saverecords(); return;
                default: gotoXY(20, 18); cout << "Invalid Choice!!!"; getch(); break;
                }
                saverecords();
            }
        }
    }
}

void displayPayslip()
{
    borderNoDelay();
    int jobcode;
    gotoXY(28, 4);
    printf("Display Payslip");
    gotoXY(10, 6);
    cout << "Enter the Jobcode Of Employee to see Payslip:";
    cin >> jobcode;
    for (int i = 0; i <= num - 1; i++)
    {
        if (emp[i].code == jobcode)
        {
            borderNoDelay();
            gotoXY(30, 2);
            cout << "PAYSLIP";
            gotoXY(10, 4);
            cout << "Name : " << emp[i].name;
            gotoXY(40, 4);
            cout << "Jobcode : " << emp[i].code;
            gotoXY(10, 6);
            cout << "Designation : " << emp[i].designation;
            gotoXY(40, 6);
            cout << "Experience : " << emp[i].exp;
            gotoXY(10, 8);
            cout << "Age : " << emp[i].age;
            gotoXY(40, 8);
            cout << "Working Hours : " << emp[i].workingHours;
            gotoXY(10, 10);
            cout << "Basic Salary : " << emp[i].salary;
            gotoXY(10, 12);
            cout << "DA : " << emp[i].DA;
            gotoXY(10, 14);
            cout << "HRA : " << emp[i].HRA;
            gotoXY(10, 16);
            cout << "Meal Allowance : " << emp[i].MealAllowance;
            gotoXY(10, 18);
            cout << "Medical Allowance : " << emp[i].MedicalAllowance;
            gotoXY(10, 20);
            cout << "Transport Allowance : " << emp[i].TransportAllowance;
            gotoXY(40, 12);
            cout << "PF : " << emp[i].PF;
            gotoXY(40, 14);
            cout << "Tax : " << emp[i].tax;
            gotoXY(40, 16);
            cout << "Loan Debit : " << emp[i].LoanDebit;
            gotoXY(40, 18);
            cout << "Loan Balance : " << emp[i].LoanBalance;
            gotoXY(40, 20);
            cout << "Gross Pay : " << emp[i].grosspay;
        }
    }
    getch();
}

void menu()
{
    int choice;
    while (true)
    {
        borderNoDelay();
        gotoXY(28, 4);
        cout << "**** Payroll Management System ****";
        gotoXY(10, 6);
        cout << "1. Insert New Record";
        gotoXY(10, 8);
        cout << "2. Delete a Record";
        gotoXY(10, 10);
        cout << "3. Search Record";
        gotoXY(10, 12);
        cout << "4. Edit a Record";
        gotoXY(10, 14);
        cout << "5. List the Record";
        gotoXY(10, 16);
        cout << "6. Display Payslip";
        gotoXY(10, 18);
        cout << "7. Exit";
        gotoXY(10, 20);
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: insert(); break;
        case 2: deletes(); break;
        case 3: search(); break;
        case 4: edit(); break;
        case 5: list(); break;
        case 6: displayPayslip(); break;
        case 7: exit(0);
        default: gotoXY(20, 22); cout << "Invalid Choice!!!"; getch(); break;
        }
    }
}

int main()
{
    setWindowSize(1000, 600);
    intro();
    login();
    getrecords();
    menu();
    return 0;
}

void setWindowSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
