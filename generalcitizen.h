#ifndef GENERALCITIZEN_H
#define GENERALCITIZEN_H
#include "citizen.h"
class general_citizen : public citizen
{
	public:
		//constructor
		general_citizen()
		{count++;}
		//getter
		int getcount(){return count;}
		void input()
		{
			citizen::input();
		}
		void show()
		{
			cout<<"Name is: "<<name<<endl<<"CNIC is: "<<nic<<endl<<"Date of 1st dose: ";
			appointment.show();
			cout<<"Date of 2nd dose: ";
			next_appointment.show();
			cout<<"Name of centre: "<<centre<<endl;
		}
		string get_city(){return city;
		}
		int get_age(){return age;
		}
		string get_nic(){return nic;}
		void show_token()
		{
			cout<<"Token is: "<<token<<endl;
			//cout<<"Vaccinated status is: "<<endl;
			if (vaccine_status==true)
			{
				cout<<"Vaccine status: true"<<endl;
			}
			else
			{
				cout<<"vaccine status: false"<<endl;
			}
		}
		void set_shift(string s)
		{
			shift = s;
		}
		void set_token(int t)
		{
			token = t;
		}
		
		void set_status(int n)
		{
			if(n==1)
			{
				vaccine_status = true;
			}
		}
		date get_next_date(date d)
		{
			date d1;
			int temp;
			temp = 21+d.day;
			if (temp>30)
			{
				d1.day=temp-30;
				int temp=d.month;
				temp+=1;
				d1.month=temp;
				d1.year=d.year;
			}
			else
			{
				d1.day=temp;
				d1.month=d.month;
				d1.year=d.year;
			}
			return (d1);
		}
		bool get_status()
		{
			return (covid_history);
		}
		string get_centre()
		{
			return centre;
		}
		date get_date_customer()
		{
			return (appointment);
		}
		date get_next_date_customer()
		{
			return (next_appointment);
		}
		
};

#endif
