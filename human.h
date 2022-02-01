#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
using namespace std;
class human
{
	protected:
		string name,gender,address,centre,nic,province,city;
		int age;
		double contact;
		static int count;
		//constructors
		human()
		{
			count++;
			set_age(0);
			set_nic("0");
		}
		public:
		//setters
		void set_data(string n, string g, string a, string c, string nic, string p, string city, int age, int contact)
		{
			name = n;
			gender = g;
			address = a;
			this->nic = nic;
			province = p;
			this->city = city;
			this->age = age;
			this->contact = contact;
		}
		
		void set_gender(string g)
		{
			gender = g;
		}
		void set_name(string n)
		{
			name = n;
		}
		void set_address(string a)
		{
			address = a;
		}
		void set_contact(double c)
		{
			contact = c;
		}
		void set_age(int n){
			age =n;
		}
		void set_city(string c)
		{
			city = c;
		}
		void set_centre(string cen){centre = cen;}
		void set_nic(string n)
		{
			nic = n;
		}
		//getters
		string get_name(){return name;}
		string get_nic(){return nic;}
		int get_age(){return age;}
		string get_gender(){return gender;}
	
};
int human::count = 0;

#endif
