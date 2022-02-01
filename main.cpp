#include <iostream>
#include <string>
#include <iomanip>
#include "generalcitizen.h"
#include "vaccinationcentre(2).h"
#include "paramedical.h"
#include "vaccines.h"
//#include "filing.h"
#include <fstream>
using namespace std;
//                                            Function to Display                                          //
void display()
{
    cout<<setw(70)<<right<<"GROUP MEMBERS"<<endl<<setw(70)<<right<<"=============="<<endl<<endl;
    cout<<setw(50)<<right<<"1.Ammar Siddiqui "<<endl<<setw(31)<<right<<"2.Muaz Zafar"<<endl<<setw(36)<<"3.Huzaifa Tanzeel"<<endl;
    system("PAUSE");
    system("CLS");
    cout<<setw(70)<<right<<"WELCOME TO NCOC MANAGEMENT SYSTEM"<<endl<<setw(70)<<right<<"=================================="<<endl<<endl;
    cout<<setw(50)<<right<<"The vaccination process has been started in Pakistan and all people of age above 18 can get themself registered and vaccinated"<<endl;
    cout<<setw(50)<<right<<"Following is the list of vaccines available in Pakistan"<<endl;
    cout<<setw(50)<<right<<"1.Pfizer"<<endl<<setw(55)<<right<<"2.Cansino bio"<<endl<<setw(53)<<right<<"3.Sputnik V"<<endl<<setw(53)<<right<<"4.SinoPharm"<<endl<<setw(56)<<right<<"5.Astra Zeneca"<<endl;
    system("PAUSE");

}
//                                      Function to write details of centre in file                             //
void write_centre_in_file(general_centre &gc)
{
    fstream fp;
    fp.open("Centre.txt",ios::app);
    if (!fp)
    {
        cout<<"FIle not found"<<endl;
        exit(5);
    }
    else
    {
        fp<<gc.get_name()<<endl<<gc.get_city()<<endl<<gc.get_province()<<endl<<gc.get_customers()<<endl<<gc.get_staff();

    }
    fp.close();
}
//                              Function to read details of centre from file                                //
general_centre read_centre_from_file()
{
    general_centre g1;
    fstream fp;
    fp.open("Centre.txt",ios::out);
    if (!fp)
    {
        cout<<"File not found"<<endl;
        exit(7);
    }
    else
    {
        string name,city,province;
        int customers,staff;
        getline(fp,name);
        getline(fp,city);
        getline(fp,province);
        fp>>customers;
        fp>>staff;
        g1.set_name(name);
        g1.set_city(city);
        g1.set_province(province);
        g1.set_no_customers(customers);
        g1.set_no_staff(staff);
    }
    return g1;
}
//                                      Function to ask user what to perform                                    //
int user_option()
{
    int n;
    cout<<endl<<"Press 1 if you are a customer\nPress 2 if you are a staff\nPress 3 if you are ncoc\nPress 0 to exit"<<endl;
    cin>>n;
    return n;
}
//                                  Function to ask if the customer is new or existing                          //
int customer_option()
{
    int n;
    cout<<endl<<"Press 1 for new customer\nPress 2 for existing customer"<<endl;
    cin>>n;
    return n;
}
//                              Function to as if the centre was general or private                             //
int centre_choice()
{
    int n;
    cout<<endl<<"Press 1 for general centre\nPress 2 for private centre"<<endl;
    cin>>n;
    return n;
}

// declaration of global objects
// objects declared globally so that they won't have to be passed in every function and it does not violate principles of OOP

general_centre gc[2];
general_centre gc1 = read_centre_from_file();
private_centre p1;
//                          Function to display names of general centres                                 //
void display_general_centres()
{
    cout<<"Name of general centre(s): "<<endl;
    for (int i=0;i<2;i++)
    {
        cout<<gc[i].get_name()<<endl;
    }
}
//                          Function to display names of private centres                                 //
void display_private_centres()
{
    cout<<"Name of private centre(s): "<<endl<<p1.get_name()<<endl;
}
//                                          Function to set centres                                                 //
void set_centre()
{
    for (int i = 0; i < 2; i++)
    {
        gc[i].input();
        fflush(stdin);
    }
    fflush(stdin);
    p1.input();
  
}
//                              Function to run program because good programming approach                //
void run_program()
{
    date d;
    d.day=18;d.month=5;d.year=2021;
    while(1)
    {
        int n= user_option();
        if (n==1)
        {
            A:
            int n1= customer_option();
            if (n1==1)      //new customer
            {
               general_citizen temp;
               temp.input();
               int n2=centre_choice();
               if (n2==1)         //general centre
               {
                   display_general_centres();
                   system("PAUSE");
                   int check=0;
                   for (int i = 0; i < 2; i++)
                   {
                       if(gc[i].get_city()==temp.get_city())
                       {
                           if(temp.get_age()>=18)
                           {
                               if(temp.get_status()==false)
                               {
                                   check=1;
                                   temp.set_date(d);
                                   date d1;
                                   d1=temp.get_next_date(d);
                                   temp.set_next_date(d1);
                                   temp.set_centre(gc[i].get_name());
                                   gc[i].assign_customer(temp);
                                   cout<<"Centre assigned, here are the details"<<endl;
                                   temp.show();
                                   //write_into_file(temp);
                                   //cout<<endl<<temp.get_centre();
                                   system("PAUSE");
                                   gc[i].assign_staff();
                               }
                           }
                           else{
                               cout<<"Your age is less than 18, you cannot get vaccinated"<<endl;
                               exit(2);
                           }
                       }
                   }
                   if (check==0)
                   {
                       cout<<"There is no centre in your city right now, we are sorry for the inconvenience"<<endl;
                       exit(1);
                   }
                   
               }
               else if(n2==2)       //private centre
               {
                   display_private_centres();
                   system("PAUSE");
                   int check=0;
                   if (p1.get_city()==temp.get_city())
                   {
                       if (temp.get_age()>=18)
                       {
                           if(temp.get_status()==false)
                           {
                               check = 1;
                               p1.assign_customer(temp);
                               temp.set_date(d);
                               date d1;
                               d1=temp.get_next_date(d);
                               temp.set_next_date(d1);
                               temp.set_centre(p1.get_name());
                               cout<<"Centre assigned, here are the details"<<endl;
                               //date d;
                                //d.day=18;d.month=5;d.year=2021;
                               temp.show();
                               system("PAUSE");
                               p1.assign_staff();
                               
                           }
                       }
                       else{
                           cout<<"Your age is less than 18, you cannot get vaccinated"<<endl;
                           exit(3);
                       }
                   }
                   if (check==0)
                   {
                       cout<<"There is no centre in your city right now, we are sorry for the inconvenience"<<endl;
                       exit(4);
                   }
               }     
            }
            else if (n1==2)     //existing customer
            {
                cout<<"Please select in which centre you registered yourself";
                int n2=centre_choice();
               
                if (n2==1)      //general centre
                {
                    int check=0;
                    display_general_centres();
                    system("PAUSE");
                    string nic;
                    cout<<"Please enter your nic"<<endl;
                    fflush(stdin);
                    getline(cin,nic);
                    for (int i = 0; i < 2; i++)
                    {
                        if(gc[i].check_nic(nic))
                        {
                            check =1;
                            gc[i].show_customer(nic);

                        }
                    }
                    if (check==0)
                    {
                        cout<<"You does not appear in our record.\nPress 1 to try again and 0 to exit"<<endl;
                        int n3;
                        cin>>n3;
                        if(n3==0)
                        {
                            exit(5);
                        }
                        else if (n3==1)
                        {
                            goto A;
                        }
                    }
                    
                }   
                else if (n2==2)             //private centre
                {
                    int check=0;
                    display_private_centres();
                    system("PAUSE");
                    string nic;
                    cout<<"Please enter your nic"<<endl;
                    fflush(stdin);
                    getline(cin,nic);
                    if (p1.check_nic(nic))
                    {
                        check=1;
                        p1.show_customer(nic);
                    }
                    if (check==0)
                    {
                        cout<<"You does not appear in our record.\nPress 1 to try again and 0 to exit"<<endl;
                        int n3;
                        cin>>n3;
                        if(n3==0)
                        {
                            exit(5);
                        }
                        else if (n3==1)
                        {
                            goto A;
                        }
                    }

                }
            }
        }
        else if (n==2)              // Staff access
        {
            B:
            cout<<"welcome staff. Please enter your nic"<<endl;
            string nic;
            fflush(stdin);
            getline(cin,nic);
            cout<<"Please select your centre"<<endl;
            int n1=centre_choice();
            int check=0;
            if (n1==1)
            {
                for (int i=0;i<2;i++)
                {
                    if (gc[i].check_staff(nic))
                    {
                        check=1;
                        gc[i].search_staff(nic);
                    }

                }
            }
            else if (n1==2)
            {
                if (p1.check_staff(nic))
                {
                    check=1;
                    p1.search_staff(nic);
                }
            }
            if (check==0)
            {
                cout<<"You do not appear in our record. Press 1 to try again and 0 to exit"<<endl;
                int n3;
                cin>>n3;
                if(n3==0)
                {
                    exit(0);
                }
                else if (n3==1)
                {
                    goto B;
                }
            }
        }
        else if(n==3)
        {
            string id;
            cout<<"Welcome ncoc"<<endl<<"Please enter your id"<<endl;
            fflush(stdin);
            getline(cin,id);
            if (id==nc.get_id())
            {
                cout<<"Please enter password"<<endl;
                char pass[5];
                char ch;
                for (int i = 0; i < 5; i++)
                {
                    ch = _getch();
                    _putch('*');
                    pass[i] = ch;
                }
                if (nc.check_pass(pass))
                {
                    nc.show();
                }
                else
                {
                    cout<<"Incorrect password"<<endl;
                }
                
            } 
            else
            {
                cout<<"Incorrect id"<<endl;
            }
        
    }
    else if(n==0)           //To break the loop and end program
        {
            cout<<"Thank you for using our system"<<endl;
            break;
        }
}
}
//                                      *** MAIN DRIVER FUNCTION ***                                    //
int main()
{
    display();
    set_centre();
    system("CLS");
    run_program();
}
