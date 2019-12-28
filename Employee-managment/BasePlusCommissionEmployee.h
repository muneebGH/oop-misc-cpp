#include"CString.h"
#include "ComissionEmployee.h"
using namespace std;
class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const CString &, const CString &,
	const CString &, double = 0.0, double = 0.0, double = 0.0);
	BasePlusCommissionEmployee(const BasePlusCommissionEmployee & ref);
	BasePlusCommissionEmployee & operator =(const BasePlusCommissionEmployee & ref);
	BasePlusCommissionEmployee & operator =(const CommissionEmployee & ref);
	BasePlusCommissionEmployee(const CommissionEmployee & ref);
	void setBaseSalary(double);
	double getBaseSalary() const;
	double earnings() const;
	void print() const; 
 private:
	 double baseSalary; 
	
};