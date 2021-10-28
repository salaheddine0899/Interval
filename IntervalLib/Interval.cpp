#include "pch.h"
#include "Interval.h"
#include<iostream>
using namespace std;
namespace in {
	Interval::Interval()
	{
		this->min = 0;
		this->max = 0;
	}
	Interval::Interval(double min, double max)
	{
		assert(max > min);
		this->min = min;
		this->max = max;

	}
	Interval& Interval::operator()(const double min, const double max)
	{
		// TODO: insert return statement here
		assert(max > min);
		//Interval* i=new Interval(0,0);
		this->min = min;
		this->max = max;
		return *this;
		/*return *i;*/
	}
	Interval& Interval::operator=(const Interval& i)
	{
		// TODO: insert return statement here
		//Interval* i2=new Interval(0, 0);
		this->min = i.min;
		this->max = i.max;
		return *this;
	}
	Interval& Interval::unionInterval(const Interval&i)
	{
		// TODO: insert return statement here
		Interval *res=new Interval();
		if (this->appartenir(i.min) || this->appartenir(i.max)) {
			if (this->min <= i.min) {
				if (this->max >= i.max) {
					*res = *this;
				}
				else
				{
					res->min = this->min;
					res->max = i.max;
				}
			}
			else
			{
				if (this->max >= i.max) {
					res->min = i.min;
					res->max = this->max;
				}
				else {
					*res = i;
				}

			}
		}
		return *res;
	}
	Interval& Interval::intersectInterval(const Interval &i)
	{
		// TODO: insert return statement here
		Interval* res=new Interval();
		if (this->appartenir(i.min) || this->appartenir(i.max)) {
			if ((this->min >= i.min)) {
				if (this->max <= i.min) {
					*res = *this;
				}
				else {
					res->min = this->min;
					res->max = i.max;
				}
			}
			else {
				if (i.max <= this->max) {
					*res = i;
				}
				else {
					res->min = i.min;
					res->max = i.max;
				}
			}

			return *res;

		}

		
	}
	double Interval::len()
	{
		return (this->max - this->min + 1);
	}
	void Interval::afficher() const
	{
		cout << "l'interval est [" << this->min << "," << this->max << "]\n";
	}
	bool Interval::appartenir(const double x)
	{
		return (x>=this->min&&x<=this->max);
	}
}
