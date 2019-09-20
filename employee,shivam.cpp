#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>


using namespace std;
class employee
{
 public:

  char c;
  int empid;
  char firstname[25];
  char lastname[25];
  char designation[25];
  void accept();
  void display();
  void display2();

 private:

    int salary;

};
employee obj; //GLOBAL OBJECT


class salary
{
private:
    int emp_id;
    float salary;

public:

    char month[20];
    char year[10];
    void accept1();
    void display1();
    void display3();

};
salary salobj; //GLOBAL OBJECT

void employee::accept()
{

   cout<<endl<<"EMPID: ";
   cin>>empid;
   cout<<endl<<"ENTER FIRST NAME: ";
   cin>>firstname;
   cout<<endl<<"ENTER LAST NAME: ";
   cin>>lastname;
   cout<<endl<<"ENTER SALARY: ";
   cin>>salary;
   cout<<endl<<"ENTER DESIGNATION: ";
   cin>>designation;

}

void employee::display()
{

   cout<<endl<<"***********************************************************************************************************************";
   cout<<endl<<"\t\t EMPID \t FIRST NAME \tLAST NAME \t SALARY \t DESIGNATION";
   cout<<endl<<"***********************************************************************************************************************";

}

void employee::display2()
{

      cout<<endl<<"\t\t "<<empid; cout<< "\t   "<<firstname;cout<<"     \t"<<lastname; cout<<"\t\t "<<salary; cout<<"\t\t "<<designation ;
      cout<<endl<<"***********************************************************************************************************************";
}
void salary::accept1()
    {
          system("cls");
          cout<<endl<<"ENTER EMP ID : ";
      cin>>emp_id;
      fstream rd;
      rd.open("D:\\EMPLOYEE.txt",ios::in);
      rd.seekg(0,ios::end);
      int n=rd.tellg();
      n=n/sizeof(obj);
      rd.seekg(0,ios::beg);
      for(int i=1;i<=n;i++)
        {
          rd.read((char*)&obj,sizeof(obj));
          if(emp_id==obj.empid)
          {
             obj.display();
             obj.display2();

          }

        }

          cout<<endl<<"ENTER SALARY : ";
          cin>>salary;
          cout<<endl<<"ENTER MONTH : ";
          cin>>month;
          cout<<endl<<"ENTER YEAR : ";
          cin>>year;


    }

void salary::display1()
  {
        cout<<endl<<"***********************************************************************************************************************";
    cout<<endl<<"\t\t EMP ID\t MONTH \t YEAR \t SALARY GIVEN";
    cout<<endl<<"***********************************************************************************************************************";

  }

 void salary::display3()
 {

     cout<<endl<<"\t\t "<<emp_id; cout<<"\t"<<month; cout<<"\t"<<year; cout<<"\t "<<salary;
     cout<<endl<<"***********************************************************************************************************************";
 }

void dispensesalary()
{

    system("cls");
    salobj.accept1();
    fstream wr;
    wr.open("D:\\SALARY.txt",ios::app);
    wr.write((char*)&salobj,sizeof(salobj));
    system("cls");
    cout<<endl<<"$$ SALARY DISPENSED $$";
    salobj.display1();
    salobj.display3();

}


 void addemployee()
 {

    cout<<endl<<"ENTER EMPLOYEE DETAILS :";
    obj.accept();
    ofstream wr;
    wr.open("D:\\EMPLOYEE.txt",ios::app);
    wr.write((char*)&obj,sizeof(obj));
    cout<<endl<<" # DATA WRITTEN TO THE FILE ..";
    wr.close();





 }

void showallemployee()
{

    system("cls");
    fstream rd;
    rd.open("D:\\EMPLOYEE.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    obj.display();
    for(int i=1;i<=n;i++)
      {
        rd.read((char*)&obj,sizeof(obj));

        obj.display2();
        cout<<endl<<"***********************************************************************************************************************";
      }



}

void removeemployee()
{
    system("cls");

    fstream rd,wr;
    rd.open("D:\\EMPLOYEE.txt",ios::in);
    wr.open("D:\\NEW EMPLOYEE.txt",ios::out);
    int id;
    cout<<endl<<"ENTER ID TO BE REMOVED:  ";
    cin>>id;
    rd.seekg(0,ios::end);
    int n =rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.empid==id)
        {
            cout<<endl<<"## EMP ID REMOVED ##";
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("D:\\EMPLOYEE.txt");
    rename("D:\\NEW EMPLOYEE.txt","D:\\EMPLOYEE.txt");

}

void updateemployee()
{
     system("cls");
    fstream rd,wr;
    rd.open("D:\\EMPLOYEE.txt",ios::in);
    wr.open("D:\\temp.txt",ios::out);

    int sr;
    cout<<endl<<"ENTER EMP ID TO BE UPDATED: ";
    cin>>sr;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);

    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {

    rd.read((char *)&obj,sizeof(obj));
    if(obj.empid==sr)
       {
        obj.accept();
        wr.write((char *)&obj,sizeof(obj));
        cout<<endl<<" # DATA UPDATED..";
       }
    else
       {
        wr.write((char *)&obj,sizeof(obj));

       }
    }
    rd.close();
    wr.close();
    remove("D:\\EMPLOYEE.txt");
    rename("D:\\temp.txt","D:\\EMPLOYEE.txt");
}


  void searchbyempid()
  {
      system("cls");
    fstream rd;
    rd.open("D:\\EMPLOYEE.txt",ios::in);
    int id;
    cout<<endl<<"ENTER ID TO BE SEARCHED: ";
    cin>>id;
    rd.seekg(0,ios::end);
    int n = rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    obj.display();
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.empid==id)
         {
            obj.display2();
            cout<<endl<<"***********************************************************************************************************************";
         }
    }


  }

  void searchbyname()
  {
    system("cls");
    fstream rd;
    rd.open("D:\\EMPLOYEE.txt",ios::in);
    char first_name[20];
    char last_name[20];
    cout<<endl<<"ENTERR FIRST NAME: ";
    cin>>first_name;
    cout<<endl<<"ENTER LAST NAME: ";
    cin>>last_name;
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    obj.display();
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.firstname,first_name)==0 && stricmp(obj.lastname,last_name)==0)
        {

            obj.display2();
            cout<<endl<<"***********************************************************************************************************************";
        }
    }



  }

  void searchbypost()
  {
    system("cls");
    fstream rd;
    rd.open("D:\\EMPLOYEE.txt",ios::in);
    char post[20];
    cout<<endl<<"ENTER PARTICULAR POST: ";
    cin>>post;
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/(sizeof(obj));
    rd.seekg(0,ios::beg);
    obj.display();
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(stricmp(obj.designation,post)==0)
        {
            obj.display2();
            cout<<endl<<"***********************************************************************************************************************";
        }
    }

}

void exit()
    {
        exit(0);
    }

  void searchbysalary()
  {
     system("cls");
    fstream rd;
    rd.open("D:\\SALARY.txt",ios::in);
    char m[20];
    char y[10];
    cout<<endl<<"ENTER MONTH: ";
    cin>>m;
    cout<<endl<<"ENTER YEAR: ";
    cin>>y;
    rd.seekg(0,ios::end);
    int n= rd.tellg();
    n=n/sizeof(salobj);
    rd.seekg(0,ios::beg);
    salobj.display1();
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&salobj,sizeof(salobj ));
        if(stricmp(salobj.month,m)==0 && stricmp(salobj.year,y)==0)
        {
            salobj.display3();
            cout<<endl<<"***********************************************************************************************************************";
        }
    }


}

void menu()
{
    cout<<endl<<"                           ************************************************************";
    cout<<endl<<"                           ************************************************************";

    cout<<endl<<"                                                        *MENU*                                 ";
    cout<<endl<<"                                                        ******                                 ";
    cout<<endl<<"                                        **                                      **                 ";
    cout<<endl<<"                                        **                                      **                   ";
    cout<<endl<<"                                 \t**     \t ENTER A OPTION : \t        **";
    cout<<endl<<"                                        **                                      **              ";
    cout<<endl<<"                                 \t**  1=> ADD EMPLOYEE DATA :\t        ** ";
    cout<<endl<<"                                 \t**  2=> UPDATE EMPLOYEE DATA :\t        ** ";
    cout<<endl<<"                                 \t**  3=> PERFORM A SEARCH ACTION :\t** ";
    cout<<endl<<"                                 \t**  4=> DISPLAY ALL EMPLOYEE :\t        ** ";
    cout<<endl<<"                                 \t**  5=> REMOVE A EMPLOYEE :\t        ** ";
    cout<<endl<<"                                  \t**  6=> DISPENSE SALARY TO A EMPLOYEE :\t** ";
    cout<<endl<<"                                 \t**  7=> EXIT NOW !!!                   \t**";
    cout<<endl<<"                           ***********************************************************";
    cout<<endl<<"                           ***********************************************************";

    cout<<endl<<"";

}
void fun()
{
  menu();
  while(1)

  {


    int option;
    char sub_option;
    char c;







    cout<<endl<<"ENTER OPTION : ";
    cin>>option;
    system("cls");
          switch(option)
          {
            case 1 : addemployee();
            cout<<endl<<"DO YOU WANT TO CONTINUE (Y/N) : ";
            cin>>c;
            system("cls");
            if (c=='y')
                {
                    menu();
                }
            else {exit(0);}
            break;

            case 2 :  updateemployee();
            cout<<endl<<"DO YOU WANT TO CONTINUE (Y/N) : ";
            cin>>c;
            system("cls");
            if (c=='y')
                {
                    menu();
                }
            else {exit(0);}

            break;

            case 3 : char search;

                 cout<<endl<<"                                        ";
                 cout<<endl<<" A. SEARCH BY EMP_ID";
                 cout<<endl<<" B. SEARCH BY NAME ";
                 cout<<endl<<" C. SEARCH BY POST " ;
                 cout<<endl<<" D. SEARCH BY SALARY" ;
                 cout<<endl<<"                                         ";
                 cout<<endl<<"SELECT SEARCH ACTION TO BE PERFORMED : ";
                 cin>>sub_option;
                 switch(sub_option)
                 {
                     case 'A' : searchbyempid();
                     break;

                     case 'B' : searchbyname();
                     break;

                     case 'C' : searchbypost();
                     break;

                     case 'D' : searchbysalary();
                     break;

                     default: cout<<"INVALID ACTION !! ";

                 }

            cout<<endl<<"DO YOU WANT TO CONTINUE (Y/N) : ";
            cin>>c;
            system("cls");
            if (c=='y')
                {
                    menu();
                }

            else {exit(0);}
            break;

            case 4: showallemployee();
            cout<<endl<<"DO YOU WANT TO CONTINUE (Y/N) : ";
            cin>>c;
            system("cls");
            if (c=='y')
                {
                    menu();
                }
            else {exit(0);}

            break;

            case 5: removeemployee();
            cout<<endl<<"DO YOU WANT TO CONTINUE (Y/N) : ";
            cin>>c;
            system("cls");
            if (c=='y')
                {
                    menu();
                }
            else {exit(0);}
            break;

            case 6 : dispensesalary();
            cout<<endl<<"DO YOU WANT TO CONTINUE (Y/N) : ";
            cin>>c;
            system("cls");
            if (c=='y')
                {
                    menu();
                }
            else {exit(0);}
            break;

            case 7: exit();
            break;

            default :  cout<<endl<<"INVALID ACTION !!!!";
          }
  }
}


int main()
{

   fun();


}
