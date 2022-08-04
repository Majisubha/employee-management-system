#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;
class Employee_management
{
private:
    // Variables for employee details
    char name[30];
    char id[5];
    char designation[10];
    int age, ctc;
    char experience[20];

public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    int password_user();
};

void Employee_management::menu() //Project Menu
{
   
    password_user();
    //login screen
    while (true)
    {
        int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> EMPLOYEE MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t\t\t 6. Exit" << endl;

        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t>> Choice Options: [1/2/3/4/5/6] <<" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
        cout << " Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;  
        case 6:
            system("cls");
            cout << "\n\t\t\t>> EMPLOYEE MANAGEMENT SYSTEM <<\n\n";
            Sleep(10);
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void Employee_management::insert() // add data of employe
{
    system("cls");
    fstream file;
    char id1[5];
    char name1[30];
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
     label1:
    cout << "\n Enter Name of Employee: ";
    cin >> name1;
   
	cout << "\n Enter Employee ID [Exact 4 digits]: ";
    cin >> id1;
    fstream file2;
    file2.open("Employee_Record.txt", ios::in);
    if (!file2)
    {
    
        file2.close();
    }
    else
    {
        file2 >> name >> id >> designation >> age >> ctc >> experience;
        while (!file2.eof())
        {
            if (strcmp(id,id1)==0)
            {
              cout<<"\nId already exists\n";
			  getch();
              system("cls");
             
            
              getch();	
             
              goto label1;
            }
          
           
            file2 >> name >> id >> designation >> age >> ctc >> experience;
        }
         file2.close();
    }
    cout << "\n Enter Designation: ";
    cin >> designation;
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n Enter Employee CTC: ";
    cin >> ctc;
    cout << "\n Enter Employee Experience: ";
    cin >> experience;
    file.open("Employee_Record.txt", ios::app | ios::out);
    file << " " << name1 << " " << id1 << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
    file.close();
}

void Employee_management::display() // Display data of employee
{
    system("cls");
    int total = 1;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo file exists... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> ctc >> experience;
        cout << "\n ----------------------------------------------------------------------------------------------------------------";
        cout << "\n||    NAME    || 	  ID	    ||    DESIGNATION    ||      AGE    ||        CTC      ||   EXPERIENCE    ||";
        cout << "\n ----------------------------------------------------------------------------------------------------------------";
        while (!file.eof())
        {
            cout << "\n";
            cout << total++ << ". " << name << "\t\t" << id << "\t\t  " << designation << "\t\t " << age << "\t\t " << ctc << "\t\t  " << experience<<"years";
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}


void Employee_management::modify() // Modify data of employee
{
    system("cls");
    char checkId[5];
    int found = 0,ch;
    fstream file, file1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo such file exists..";
        file.close();
    }
    else
    {
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
            
                while(ch!=6)
				{
					cout<<"\n1.Modify Name\n2.Modify Designation\n3.Modify Age\n4.Modify CTC\n5.Modify Experience\n6.Go Back\n\nEnter your choice:";
					cin>>ch;
					
				if(ch==1)
			{
					cout << "\n Enter Name of Employee: ";
                cin >> name;
                         cout << "\n\nName Successfully Modified\n";
            }
               else if(ch==2) {
                cout << "\n Enter Designation: ";
                cin >> designation;
                         cout << "\n\n Designation Successfully Modified\n";
            }
                else if(ch==3){
				cout << "\n Enter Employee Age: ";
                cin >> age;
                         cout << "\n\nAge Successfully Modified\n";
            }
            
                else if(ch==4){
				cout << "\n Enter Employee CTC: ";
                cin >> ctc;
                         cout << "\n\nCTC Successfully Modified\n";
            }
                else if(ch==5)
				{
				cout << "\n Enter Employee Experience: ";
                cin >> experience;
                 cout << "\n\nExperience Successfully Modified\n";
            }
          
              
            }
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
                found++;
            }
            else
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
    }
    waitForEnter();
}

void Employee_management::search() // Search data of employee
{                                  //Displays all details according to Employee's id
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    cout << "\n\nEnter Employee ID: ";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Such file is present... ";
        file.close();
    }
    else
    {
    	int c=0;
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n---------------------\n";
                cout << "Employee Name: " << name << "\n";
                cout << "Employee ID.: " << id << "\n";
                cout << "Employee Designation: " << designation << "\n";
                cout << "Employee Age: " << age << "\n";
                cout << "Employee CTC: " << ctc << "\n";
                cout << "Employee Experience: " << experience << "\n";
                cout << "---------------------\n";
                c++;
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if(c==0)
        cout<<"No such Id exists"<<endl;
    }
    file.close();
    waitForEnter();
}

void Employee_management::deleted() // Delete data of employee
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo such file is present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tData Successfully Deleted ";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
        waitForEnter();
    }
}

void Employee_management::waitForEnter()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}

int Employee_management::password_user() // Employee Authentication
{
    label:
	string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    string conf_pass="";
    fstream file;
    char ch;
    int flag=0;
    system("cls");
    cout << "\n\t\t\t -------------------------------------------";
    cout << "\n\t\t\t||  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  ||";
    cout << "\n\t\t\t -------------------------------------------";
    cout << "\n\n\t\t\t   -| Press: [1] Register & [2] Login  |-";
    int selection;
    cout << "\n\nPlease Enter Value: ";
    cin >> selection;
   
	if(selection!=1 && selection!=2)
	{
		cout<<"wrong choice";
		getch();
		system("cls");
		goto label;
	}
    // if user press [1], then it would lead them to register.
    if (selection == 1)
    {
    	
        system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>> REGISTRATION EMPLOYEE <<";
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\n\t\t\t\t\tEnter User Name: ";
        cin >> name_reg;
                                        
    //system("cls");
    fstream file2;
    file2.open("Ep_data.txt", ios::in);
    if (!file2)
    {
    
        file2.close();
    }
    else
    {
        file2 >> name>> pass;
        while (!file2.eof())
        {
            if (name_reg==name )
            {
              cout<<"User name already exists";
             
              getch();	
             
              goto label;
            }
           
            file2 >> name>> pass;
        }
         file2.close();
    }
   

 {
	   cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = getch();
        while (ch != 13)
        {
        	if(ch!=8)
        	{
            pass_reg.push_back(ch);
            cout << '*';
        	}
            ch = getch();
        }
        cout<<"\n\t\t\t\t\tConfirm Password: ";
        char ch1=getch();
        while(ch1 != 13)
		{	
		if(ch1!=8)
			{
        	conf_pass.push_back(ch1);
        	cout<< '*';
        	}
        	ch1=getch();
		}
		if(pass_reg!=conf_pass){
			cout<<"\nPassword didn't match!!";
		
			getch();
			goto label;
		}
        file.open("Ep_data.txt", ios::app);
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();
        cout << "\nRegistration Succesfully saved";
        getch();
       
        password_user();
    
}
    }
    // if user press [2], then it would lead them to login.
 
   else if (selection == 2)
    {
        system("cls");
        file.open("Ep_data.txt", ios::in);
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\t\t\t\t\t>> LOGIN EMPLOYEE <<";
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = getch();
        while (ch != 13)
        {
        	if(ch!=8)
        	{
            pass.push_back(ch);
            cout << '*';
        	}
            ch = getch();
        }
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if (pass == pass_reg && name == name_reg)
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Granted..\n\n"; 
            
               getch();
                return 0;
            
				
				flag=1;
			
                break;
                system("cls");
               
            } 
           
            file >> name_reg >> pass_reg;
        }
        if(flag==0)
        {
        	cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
        	 cout << "\n\nInvalid credentials\nAccess Aborted...\n\n";
        	 system("PAUSE");
             system("cls");
             password_user();
		}
        file.close();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        password_user();
        return 0;
    }
    
}
int main()
{
    // Call the function
    Employee_management system;
    system.menu();
    return 0;
}
        


