#ifndef VACCINES_H
#define VACCINES_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class vaccines
{
	protected:
	int dose,age;
	float price;
	string name,producer;
	static int count;	
	public:
		//parametrized constructor
		vaccines(int d,float p, string name, string producer)
		{
			//count++;
			dose = d;
			price = p;
			this->name = name;
			this->producer = producer;
		}
		//default
		vaccines()
		{
			//count++;
		}
		int get_count(){
			return count;
		}
		float get_price()
		{
			return price;
		}
};

class pfizer : public vaccines
{
	// some attribute
	public:
		pfizer() : vaccines(2,350.00,"Pfizer","Bio N Tech") 
		{count++;
		}
		pfizer(int a,int d, float p, string producer) : vaccines(2,350.00,"Pfizer","Bio N Tech") 
		{
			if (a>16)
			{
				age = a;	
			}	
			else
			{
				cout<<"The entered age is not valid for Pfizer vaccine "<<endl;
			}
		
		}	
};

class sinopharm : public vaccines
{
	//some attribute
	public:
		sinopharm() : vaccines(2,500.00,"Sinopharm","Sinovac")
		{count++;
		}
		sinopharm(int a,int d, float p, string producer) : vaccines(d,p,"Sinopharm",producer)	
		{
			if (age>18 && age<60)
			{
				age = a;
			}
			else
			{
				cout <<"The entered age is not valid for Sinopharm vaccines "<<endl;
			}
		
		}
};

class cansino_bio : public vaccines
{
	//some attribute
	public:
		cansino_bio() : vaccines(1,680.95,"Cansino Bio","CansinoBio Biologics")
		{count++;
		}
		cansino_bio(int a,int d, float p, string producer) : vaccines(d,p,"Cansino bio",producer)
		{
			if (age>18)
			{
				age = a;
			}
			else
			{
				cout<<"The entered age is not valid for Cansino bio vaccines "<<endl;
			}
			if (d==1)
			{
				dose = d;
			}
			else
			{
				cout<<"Dose is not valid"<<endl;
			}
		}
};

class sputnik_v : public vaccines
{
	//some attribute
	public:
		sputnik_v() : vaccines(2,780.99,"Sputnik V","R-Pharm")
		{count++;
		}
		sputnik_v(int a,int d, float p, string producer) : vaccines(d,p,"Sputnik V",producer)
		{
			if (age>18)
			{
				age = a;
			}
			else
			{
				cout <<"The entered age is not valid for Sputnik V vaccine"<<endl;
			}

		}
};

class astra_zeneca : public vaccines
{
	public:
		astra_zeneca(int a,int d, float p, string producer) : vaccines(d,p,"Astra Zeneca",producer)
		{
			if (age>18)
			{
				age = a;
			}
			else
			{
				cout <<"The entered age is not valid for Astra Zeneca vaccine "<<endl;	
			}
			if (d==2)
			{
				dose = d;
			}
			else
			{
				cout<<"Dose is not valid";
			}
		}
		astra_zeneca() : vaccines(2,899.99,"Astra Zeneca","Oxford University")
		{
			count++;
		}
		void set_price(float p)
		{
			price = p;
		}
		
};
int vaccines::count = 0;

#endif
