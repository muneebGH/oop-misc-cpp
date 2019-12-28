#include"ComissionEmployee.h"
CommissionEmployee::CommissionEmployee(
	const CString & fn, const CString & ln, const CString & sn,
	double gs, double cr)
{
	firstName = fn;
	lastName = ln;
	socialSecurityNumber = sn;
	setGrossSales(gs);
	setCommissionRate(cr); 
}

void CommissionEmployee::setFirstName(const CString & fn)
{
	firstName = fn;
}

CString CommissionEmployee::getFirstName()
{
	return firstName;
}

void CommissionEmployee::setLastName(const CString & ln)
{
	lastName = ln;
}

CString CommissionEmployee::getLastName()
{
	return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const CString & sn)
{
	socialSecurityNumber = sn;
}

CString CommissionEmployee::getSocialSecurityNumber()
{
	return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double gs)
 {
	grossSales = (gs < 0.0) ? 0.0 : gs;
}

double CommissionEmployee::getGrossSales()
{
	return grossSales;
}

void CommissionEmployee::setCommissionRate(double cr)
{
	 commissionRate = (cr > 0.0 && cr < 1.0) ? cr : 0.0;
}

double CommissionEmployee::getCommissionRate()
{
	return commissionRate;
}

double CommissionEmployee::earnings() const
{
	return commissionRate * grossSales;
}

void CommissionEmployee::print() const
{
	cout << "commission employee: "; firstName.display(); lastName.display();
	cout << "\nsocial security number: "; socialSecurityNumber.display();
	cout << "\ngross sales: " << grossSales
		<< "\ncommission rate: " << commissionRate;
}

CommissionEmployee::CommissionEmployee(const  CommissionEmployee & ref):firstName(ref.firstName),lastName(ref.lastName),socialSecurityNumber(ref.socialSecurityNumber)
{
	grossSales = ref.grossSales;
	commissionRate = ref.commissionRate;
}

CommissionEmployee & CommissionEmployee::operator =(const CommissionEmployee & ref)
{
	if ()
		this->commissionRate();
	firstName = ref.firstName;
	lastName = ref.lastName;
	socialSecurityNumber = ref.socialSecurityNumber;
	grossSales = ref.grossSales;
	commissionRate = ref.commissionRate;
	return *this;
}

