#include <string>
#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

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

	//veryyoung
	if(age <= 25)
	{
 		applicant.veryyoung = 1;
 	}	
	else if (age > 25 && age < 35)
	{
		applicant.veryyoung = (35 - age) / 10;
	}
 	else 
	{
		applicant.veryyoung = 0;
	}

	//young
	if(age == 35)
	{
		applicant.young =  1;
	}
	else if (age < 35 && age > 25)
	{
		applicant.young =  1 - ((35 - age) / 10); 
	}
	else if (age > 35 && age < 45 )
	{
		applicant.young = (45 - age) / 10;
	}	
	else
	{
		applicant.young = 0;
	}

	//middle
	if(age == 45)
	{
		applicant.middle = 1;
	}
	else if (age < 45 && age > 35)
	{
		applicant.middle = 1 - ((45 - age) / 10);
	}
	else if (age > 45 && age < 55)
	{
		applicant.middle = (55 - age) / 10;
	}
	else
	{
		applicant.middle = 0;
	}

	//old
	if(age == 55)
	{
		applicant.old = 1;
	}	
	else if (age < 55 && age > 45)
	{
		applicant.old = 1 - ((55 - age ) / 10);
	}
	else if (age > 55 && age < 65)
	{
		applicant.old = (65 - age) / 10;
	}
	else
	{
		applicant.old = 0;
	}

	//veryold
	if(age >= 65)
	{
		applicant.veryold = 1;
	}
	else if (age < 65 && age > 55)
	{
		applicant.veryold = 1 - ((65 - age) / 10);
	}
	else
	{
		applicant.veryold = 0;
	}

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

	//verylow
	if(salary <= 15000)
	{
		applicant.verylow = 1;
	}
	else if (salary < 30000)
	{
		applicant.verylow = (30000 - salary) / 15000;
	}
	else
	{
		applicant.verylow = 0;
	}

	//low
	if(salary >= 30000 && salary <= 35000)
	{
		applicant.low = 1;
	}
	else if (salary < 30000 && salary > 15000)
	{
		applicant.low = 1 - ((30000 - salary) / 15000);
	}
	else if (salary > 35000 && salary < 50000)
	{
		applicant.low = (50000 - salary) / 15000;
	}
	else
	{
		applicant.low = 0;
	}

	//average
	if(salary >= 50000 && salary <= 55000)
	{
		applicant.average = 1;
	}
	else if (salary < 50000 && salary > 35000)
	{
		applicant.average = 1 - ((50000 - salary) / 15000);
	}
	else if (salary > 55000 && salary < 70000)
        {
                applicant.average = (70000 - salary) / 15000;
        }
        else
        {
                applicant.average = 0;
        }

	//high
        if(salary >= 70000 && salary <= 85000)
        {
                applicant.high = 1;
        }
        else if (salary < 70000 && salary > 55000)
        {
                applicant.high = 1 - ((70000 - salary) / 15000);
        }
        else if (salary > 85000 && salary < 100000)
        {
                applicant.high = (100000 - salary) / 15000;
        }
        else
        {
                applicant.high = 0;
        }

	//very high
	if(salary >= 100000)
	{
		applicant.veryhigh = 1;
	}
	else if (salary < 100000 && salary > 85000)
	{
		applicant.veryhigh = 1 - ((100000 - salary) / 15000);
	}
	else
	{
		applicant.veryhigh = 0;
	}
	
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
