#include"CString.h"
#include<iostream>
using namespace std;
class CommissionEmployee
{
private:
	CString firstName;
	CString lastName;
	CString socialSecurityNumber;
	double grossSales;
	double commissionRate;
public:
	CommissionEmployee(const  CommissionEmployee & ref);
	CommissionEmployee & operator =(const CommissionEmployee & ref);
	CommissionEmployee(const CString & fn, const CString & ln, const CString & sn, double gs = 0.0, double cr = 0.0);
	void setFirstName(const CString & fn);
	CString getFirstName();
	void setLastName(const CString & ln);
	CString getLastName();
	void setSocialSecurityNumber(const CString & sn);
	CString getSocialSecurityNumber();
	void setGrossSales(double gs);
	double getGrossSales();
	void setCommissionRate(double cr);
	double getCommissionRate();
	double earnings()const;
	void print()const;
};