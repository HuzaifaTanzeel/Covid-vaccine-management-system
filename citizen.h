#ifndef CITIZEN_H
#define CITIZEN_H
#include "human.h"
struct date
{
	int day,year,month;
	void show()
	{
		cout<<day<<"/"<<month<<"/"<<year<<endl;
	}
};
class citizen : public human
{
	protected:
	bool covid_history,vaccine_status;
	string shift;
	int token;
	date appointment,next_appointment;
	void input()
		{
			fflush(stdin);
			cout<<"Enter name of the citizen: "<<endl;
			getline(cin,name);
			cout<<"Enter gender,address,NIC of the citizen: "<<endl;
			getline(cin,gender);
			getline(cin,address);
			getline(cin,nic);
			cout<<"Enter province and city: "<<endl;
			getline(cin,province);
			getline(cin,city);
			cout<<"Enter age and contact number: "<<endl;
			cin>>age>>contact;
			cout<<"Has you suffer corona in the last 6 months?"<<endl<<"Press 1 for yes, 2 for no";
			int n;
			cin>>n;
			if (n==1)
			{
				covid_history = true;
				cout<<"You are advise to not get vaccinated now and try later"<<endl;
				exit(2);
			}
			else if (n==2)
			{
				covid_history = false;
			}
			vaccine_status = false;
		}
	public:
		void set_token(int n)
		{
			token = n;
		}
		int get_token(){return token;}
		void set_date(date d)
		{
			appointment = d;
		}
		void set_next_date(date d)
		{
			next_appointment = d;
		}
		string get_shift()
		{
			return shift;
		}

	
};

#endif
