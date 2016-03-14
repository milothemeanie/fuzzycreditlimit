#include <string>
#include <iostream>
#include <math.h>
#include <limits>
#include "fuzzymembership.hpp"

using namespace std;
using namespace fuzzymembership;

struct ApplicantMembership
{
	double veryyoung;
	double young;
	double middle;
	double old;
	double veryold;

	double verylow;
	double low;
	double average;
	double high;
	double veryhigh;
};

void evalAge(struct ApplicantMembership &applicant, const double age, const double salary)
{
	cout << endl << "###########################" << endl << endl;
	cout << "Age MemberShip:" << endl;

	applicant.veryyoung = sigmoidMembership(age, 25, false, 10);
	applicant.young = triangleMembership(age, 35, 10);
	applicant.middle = triangleMembership(age, 45, 10);
	applicant.old = triangleMembership(age, 55, 10);
	applicant.veryold = sigmoidMembership(age, 65, true, 10);

	cout << "[veryyoung] " << applicant.veryyoung << endl;
	cout << "[young] " << applicant.young << endl;
	cout << "[middle] " << applicant.middle << endl;
	cout << "[old] " << applicant.old << endl;
	cout << "[veryold] " << applicant.veryold << endl << endl;

}

void evalSalary(struct ApplicantMembership &applicant, const double age, const double salary)
{
	cout << "###########################" << endl << endl;
	cout << "Salary Membership:" << endl;

	applicant.verylow = sigmoidMembership(salary, 15000, false, 15000);
	applicant.low = trapezoidMembership(salary, 30000, 35000, 15000);
	applicant.average = trapezoidMembership(salary, 50000, 55000, 15000);
	applicant.high = trapezoidMembership(salary, 70000, 85000, 15000);
	applicant.veryhigh = sigmoidMembership(salary, 100000, true, 15000);

	cout << "[verylow] " << applicant.verylow << endl;
	cout << "[low] " << applicant.low << endl;
	cout << "[average] " << applicant.average << endl;
	cout << "[high] " << applicant.high << endl;
	cout << "[veryhigh] " << applicant.veryhigh << endl;
}


double combo(const double ageweight, const double salaryweight)
{
	double weight = 0;
	if(ageweight > 0 && salaryweight > 0)
	{
		weight = ageweight + salaryweight; 
	}
	return weight;
}

double evaulate(const double age , const double salary)
{
	struct ApplicantMembership ap;
	evalAge(ap,age,salary);
	evalSalary(ap,age,salary);

	double smallcredittotal = combo(ap.veryyoung,ap.verylow) + combo(ap.veryyoung,ap.low) + combo(ap.veryyoung,ap.average);
		smallcredittotal += combo(ap.young,ap.verylow) + combo(ap.young,ap.low) + combo(ap.middle,ap.verylow);
		smallcredittotal += combo(ap.veryold,ap.verylow) + combo(ap.veryold,ap.low);

	double mediumcredittotal = combo(ap.veryyoung,ap.high) + combo(ap.veryyoung,ap.veryhigh) + combo(ap.young,ap.average);
		mediumcredittotal += combo(ap.middle,ap.low) + combo(ap.middle,ap.average) + combo(ap.old,ap.verylow);
		mediumcredittotal += combo(ap.old,ap.low) + combo(ap.young,ap.veryhigh) + combo(ap.veryold,ap.average);

	double largecredittotal = combo(ap.young,ap.veryhigh) + combo(ap.middle,ap.high) + combo(ap.middle,ap.veryhigh);
		largecredittotal += combo(ap.old,ap.high) + combo(ap.old,ap.veryhigh) + combo(ap.veryold,ap.high) + combo(ap.veryold,ap.veryhigh);


	double creditlimit = 0;
	double totalcreditweight = smallcredittotal + mediumcredittotal + largecredittotal;

	cout << endl << "###########################" << endl << endl;
	cout << "small credit weight:" << smallcredittotal << endl;
	cout << "medium credit weight:" << mediumcredittotal << endl;
	cout << "large credit weight:" << largecredittotal << endl;
	cout << "total credit weight:" << totalcreditweight << endl;

	if(smallcredittotal != 0)
	{	
		double smweight = smallcredittotal / totalcreditweight;
		creditlimit += 5000 * smweight; 
	}

	if(mediumcredittotal != 0)
	{
		double meweight = mediumcredittotal / totalcreditweight;
		creditlimit += 10000 * meweight;
	}

	if(largecredittotal != 0)
	{
		double laweight = largecredittotal / totalcreditweight;
		creditlimit += 15000 * laweight;
	}

	return creditlimit;
}

double numericalInput(const string message)
{
	double number;

 	cout << message << endl;
	cin >> number;
	while(1)
	{
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Numerical input only" << endl;
			cin >> number;
		}	
		if(!cin.fail())
		break;
	}	

	return number;
}

int main()
{
 
	double age;
	double salary;
	
	cout << "Credit limit App" << endl;

	age = numericalInput("Please enter age of applicant" );
	salary = numericalInput("Enter the annual salary of applicant");	

 	double creditlimit = evaulate(age,salary);
	cout << endl << "###########################" << endl << endl;
 	cout << "The Credit limit for this applicant is $" << creditlimit << endl;
	cout << endl; 
 	
}
