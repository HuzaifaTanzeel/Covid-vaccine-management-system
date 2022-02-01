#ifndef PARAMEDICAL_H
#define PARAMEDICAL_H
#include "human.h"
#include "citizen.h"
#include "generalcitizen.h"
class paramedical_staff : public human
{
	public:
		//citizen *c;
		int exp,customer_count;
		float tax,salary,net_salary,commission;
		//constructor
		paramedical_staff()
		{
			count++;
			customer_count=0;
			salary=0;
		}
		void calculate_salary()
		{
			salary+=commission;
		}
		void keep_count(general_citizen c)
		{
			customer_count++;
		}
		void cal_commission()
		{
			commission+=customer_count*0.5;
		}
		void cal_tax()
		{
			tax = salary*0.01;
			net_salary = salary - tax;
		}
		//getters
		
		int get_count(){return count;}
		float get_sal(){return net_salary;}
		string get_nic()
		{
			return nic;
		}
		void show()
		{
			cal_commission();
			calculate_salary();
			cal_tax();
			cout<<"Details of the staff are as follows: "<<endl<<"Name: "<<name<<endl<<"Age: "<<age<<endl<<"salary: $"<<net_salary<<endl<<endl;
		}
		void input()
		{
			fflush(stdin);
			cout<<"Enter name of the staff: "<<endl;
			getline(cin,name);
			cout<<"Enter gender,address,NIC of the staff: "<<endl;
			getline(cin,gender);
			getline(cin,address);
			getline(cin,nic);
			cout<<"Enter province and city: "<<endl;
			getline(cin,province);
			getline(cin,city);
			cout<<"Enter age and contact number: "<<endl;
			cin>>age>>contact;
			cout<<"Enter salary of the staff"<<endl;
			cin>>salary;
			cout<<"Enter experience of the staff (in years)"<<endl;
			cin>>exp;

		}
		
};

#endif
