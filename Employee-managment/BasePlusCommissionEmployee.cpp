#include"ComissionEmployee.h"
#include"BasePlusCommissionEmployee.h"
using namespace std;
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const CString & first, const CString & last, const CString & sn
	, double sales, double rate, double salary):CommissionEmployee(first, last, sn, sales, rate)
{
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings()const
{
	return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print()const
{
	cout << "base-salaried ";
	CommissionEmployee::print();
	cout << "\nbase salary: " << getBaseSalary();
}

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const BasePlusCommissionEmployee & ref):CommissionEmployee(ref)
{
	baseSalary = ref.baseSalary;
}

BasePlusCommissionEmployee & BasePlusCommissionEmployee::operator =(const BasePlusCommissionEmployee & ref)
{
	CommissionEmployee::operator=(ref);
	baseSalary = ref.baseSalary;
	return *this;
}

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const CommissionEmployee & ref) :CommissionEmployee(ref)
{
}


BasePlusCommissionEmployee & BasePlusCommissionEmployee::operator =(const CommissionEmployee & ref)
{
	CommissionEmployee::operator=(ref);
	return *this;
}

