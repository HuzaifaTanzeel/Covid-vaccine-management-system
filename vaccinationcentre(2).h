#include <iostream>
#include <string>
#include <iomanip>
#include "generalcitizen.h"
#include "vaccines.h"
#include <conio.h>
#include "paramedical.h"
#include <fstream>
#include <string.h>
//#include "ncoc.h"
using namespace std;
void write_into_file (general_citizen &g1)
{
    fstream fp;
    fp.open("generalcitizen.txt", ios::app);        //reading is in
    if (!fp)
    {
        cout<<"FIle not found"<<endl;
    }
    else
    {
        fp<<g1.get_name()<<endl<<g1.get_nic()<<endl<<g1.get_age()<<endl<<g1.get_centre()<<endl<<g1.get_token()<<endl;
    }
    fp.close();
}

general_citizen read_from_file()
{
    general_citizen temp;
    date d1,d2;
    d1.day=18;d1.month=5;d1.year=2021;
    d2 = temp.get_next_date(d1);
    temp.set_date(d1);
    temp.set_next_date(d2);
    fstream fp;
    fp.open("generalcitizen.txt", ios::in);
    if (!fp)
    {
        cout<<"File not found"<<endl;
        exit(1);
    }
    else
    {
        string name,nic,centre;
        int age,token;
        getline(fp,name);
        getline(fp,nic);
        fp>>age;
        getline(fp,centre);
        fp>>token;
        temp.set_name(name);
        temp.set_nic(nic);
        temp.set_age(age);
        temp.set_centre(centre);
        temp.set_token(token);
    }
    return (temp);
}
class ncoc
{
    string head,id;
    char password[5];
    int no_of_vaccinated,no_of_active,vaccines,no_of_centres,no_staff;
    public:
    friend class vaccination_centre;
        ncoc()
        {
            id = "admin";
            strcpy(password,"12345");
            head = "Asad Umar";
            no_of_vaccinated = 964227;
            no_of_active = 68223;
            vaccines = 980090;
            no_of_centres = 50;
            no_staff = 189099;
            //total_affected = 
        }
        void add_no_of_vaccinated()
        {
            no_of_vaccinated++;        
        }
        void add_no_of_active(int n)
        {
            no_of_active+=n;
        }
        void give_vaccine(int n)
        {
            vaccines-=n;
            if (vaccines<=5000)
            {
                cout<<"The amount of vaccine is less than 5000"<<endl;
            }
        }
        void add_staff(int n)
        {
            no_staff+=n;
        }
        void add_no_of_centres()
        {
            no_of_centres++;
        }
        void show()
        {
            cout<<endl<<"The head of NCOC is: "<<head<<endl<<"Number of vaccinated customers: "<<no_of_vaccinated<<endl<<"Number of centres are: "<<no_of_centres<<endl<<"Number of active cases: "<<no_of_active<<endl;
            system("PAUSE");
        }
        string get_id(){return id;}
        //string get_password(){return password;}
        bool check_pass(char *ptr)
        {
            if(strcmp(ptr,password)==1)
            {
                return(true);
            }
            else{
                return (false);
            }
        }
};
ncoc nc;
class vaccination_centre 
{
	protected:
    //ncoc n;
	string name,city,province;
	general_citizen *cz;
	paramedical_staff *pmd;
	static int count;
	int no_of_customers,no_of_staff,vaccine_count,vaccinated_customer;
	float revenue;
	public:
    //friend class ncoc;
		vaccination_centre()
		{
			//count++;
			no_of_customers=0;
            vaccine_count=0;
			no_of_staff=0;
			revenue=0.00;
            vaccinated_customer=0;
            nc.add_no_of_centres();
		}
		void input()
		{
            static int check=0;
			cout<<"Enter name of the centre"<<endl;
			getline(cin,name);
			cout<<"Enter the city of centre: "<<name<<endl;
			getline(cin,city);
			cout<<"Enter the province of centre: "<<name<<endl;
			getline(cin,province);
			cout<<"Enter number of customers the centre can handle"<<endl;
			cin>>no_of_customers;
			cz = new general_citizen[no_of_customers];
            nc.add_no_of_active(no_of_customers);
            if (check==0)
            {
                //general_centre::assign_customer(read_from_file());
                //cz[0] = read_from_file();
            }
            check++;
			cout<<"Enter the number of paramedical staff the centre has"<<endl;
			cin>>no_of_staff;
            nc.add_staff(no_of_staff);
			pmd = new paramedical_staff[no_of_staff];
            for (int i = 0; i < no_of_staff; i++)
            {
                pmd[i].input();
                pmd[i].set_centre(name);
            }
            
		}
        void show()
        {
            cout<<"Name is"<<name<<endl<<"City is:"<<city<<endl<<"Province is: "<<province<<endl;
            for (int i=0;i<no_of_customers;i++)
            {
                cout<<"Details of customer"<<i+1<<endl;
                cz[i].show();
                cout<<endl;
            }
            for (int i = 0; i < no_of_staff; i++)
            {
                cout<<"Details of staff"<<i+1<<endl;
                pmd[i].show();
                cout<<endl;
            }
            

        }
		//getters
        void assign_staff()
        {
            int j=0;
            for (int i=0;i<no_of_customers;i++,j++)
            {
                if (j<no_of_staff)
                {
                    pmd[j].keep_count(cz[i]);
                }
                else
                {
                    j=0;
                }
            }
        }
        
        bool check_staff(string n)
        {
            for (int i = 0; i < no_of_staff; i++)
            {
                if(n==pmd[i].get_nic())
                {
                    return(true);
                }
                else
                {
                    return(false);
                }
            }
            
        }
        
        void search_staff(string n)
        {
            for (int i=0;i<no_of_staff;i++)
            {
                if (pmd[i].get_nic()==n)
                {
                    pmd[i].show();
                }
            }
        }
        void set_name(string n)
        {
            name =n;
        }
        void set_province(string p){
            province = p;
        }
        void set_city(string c)
        {
            city = c;
        }
        void set_no_customers(int n)
        {
            no_of_customers = n;
        }
        void set_no_staff(int n)
        {
            no_of_staff = n;
        }
        static int get_count(){return count;}
		int get_staff(){return no_of_staff;
		}
		int get_customers(){return no_of_customers;
		}
		string get_province(){return province;
		}
		string get_name(){return name;
		}
		string get_city(){return city;}
        bool check_nic(string n)
        {
            int check=0;
            for (int i=0 ;i<no_of_customers;i++)
            {
                if (n==cz[i].get_nic())
                {
                    check=1;
                }
               
            }
            if (check==1)
            {
                return(true);
            }
            else{
                return(false);
            }
        }
        void show_customer(string n)
        {
            //date d1,d2;
            for (int i=0;i<no_of_customers;i++)
            {
                if (n==cz[i].get_nic())
                {
                    vaccinated_customer++;
                    cz[i].set_status(1);
                    cout<<"Here are the details"<<endl;
                    cz[i].show();
                    cz[i].show_token();
                    // d1 = cz[i].get_date_customer();
                    // d2 = cz[i].get_next_date_customer();
                    // d1.show();
                    // d2.show();
                    system("PAUSE");
                    cout<<"You've been vaccinated. Contact NCOC helpline if you face any kind of side effects"<<endl;
                    system("PAUSE");
                    vaccinated_customer++;
                    nc.add_no_of_vaccinated();
                    //cz[i] = ~general_citizen();
                    for (int j=i ; j<no_of_customers-1;j++)
                    {
                        cz[j] = cz[j+1];
                    }
                    no_of_customers--;
                }
            }
            
        }
        void assign_token()
		{
			for (int i=0 ; i<no_of_customers-1;i++)
			{
				for (int j=0 ; j<no_of_customers-1-i;j++)
				{
					if (cz[j].get_age()<cz[j+1].get_age())
					{
						general_citizen temp;
						temp = cz[j];
						cz[j] = cz[j+1];
						cz[j+1] = temp;
					}
				}
			}
			for (int i=0 ; i<no_of_customers;i++)
			{
				cz[i].set_token(i+1);
			}
			
		}
};
class general_centre : public vaccination_centre
{
    //attributes
    sputnik_v *sv;
	cansino_bio *cb;
	sinopharm *sp;
	pfizer *pf;
    public:
        general_centre(){count++;}
        void input()
        {
            int n;
            cout<<"General centre: "<<endl;
            vaccination_centre::input();
            cout<<"Enter the amount of sputnik V vaccine this centre has"<<endl;
            cin>>n;
            vaccine_count+=n;
            sv = new sputnik_v[n];
            cout<<"Enter the amount of Cansino bio vaccine this centre has"<<endl;
            cin>>n;
            vaccine_count+=n;
            cb = new cansino_bio[n];
            cout<<"Enter the amount of Sinopharm vaccine this centre has"<<endl;
            cin>>n;
            vaccine_count+=n;
            sp = new sinopharm[n];
            cout<<"Enter the amount of pfizer vaccine this centre has"<<endl;
            cin>>n;
            vaccine_count+=n;
            nc.give_vaccine(vaccine_count);
            pf = new pfizer[n];
            if (vaccine_count_check())
            {
                cout<<"The amount of vaccines is less than 1000, kindly contact NCOC for more allocation of vaccines"<<endl;
            }
        }
        void cal_revenue()
        {
            revenue += sv[0].get_count()*sv[0].get_price();
            revenue+= cb[0].get_count()*cb[0].get_price();
            revenue+= sp[0].get_count()*sp[0].get_price();
            revenue+= pf[0].get_count()*pf[0].get_price(); 
        }
        float get_revenue()
        {
            cal_revenue();
            return revenue;}
        bool vaccine_count_check()
        {
            if (vaccine_count<=1000)
            {
                return(true);
            }
            else
            {
                return (false);
            }
        }
        void assign_customer(general_citizen g)
        {
            static int check=0;
            static int count=0;
            if (check<no_of_customers)
            {
                cz[check]= g ;
                //cz[check].set_centre(name);
                //cz[check].set_shift("morning");
            }
            else
            {
                cout<<"The centre capacity is full"<<endl;
            }
            if (count==0)
            {
                int temp=no_of_customers/2;
                if (check<=temp)
                {
                    cz[check].set_shift("morning");
                }
                else
                {
                    cz[check].set_shift("evening");
                }
                
            }
            vaccination_centre::assign_token();
            count++;
            check++;

            
        }
};

class private_centre : public vaccination_centre
{
    astra_zeneca *az;
    public:
        private_centre(){count++;}
        void input()
        {
            cout<<"Private Centre"<<endl;
            vaccination_centre::input();
            int n;
            cout<<"Enter the amount of astra zeneca vaccine this centre has"<<endl;
            cin>>n;
            az = new astra_zeneca[n];
        }
        void assign_customer(general_citizen g)
        {
            static int count=0;
            static int check=0;
            if (check<=no_of_customers)
            {
                cz[check] = g;
                cz[check].set_centre(name);
                //cz[check].set_shift("morning");
                if (count==0)
                {
                     int temp=no_of_customers/2;
                if (check<=temp)
                {
                    cz[check].set_shift("morning");
                }
                else
                {
                    cz[check].set_shift("evening");
                }
                vaccination_centre::assign_token();
                }
               
            }
            else
            {
                cout<<"The centre capacity is full"<<endl;
            }
            count++;
            check++;
        }
        void cal_revenue()
        {
            revenue+= az[0].get_count()*az[0].get_price();
        }
        float get_revenue(){
            cal_revenue();
            return revenue;}
};
int vaccination_centre::count=0;

void show_ncoc()
{
    nc.show();
}

