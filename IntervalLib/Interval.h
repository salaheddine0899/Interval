#pragma once
#include<assert.h>
namespace in {
	class Interval
	{
	private:
		double min=0;
		double max=0;
	public:
		Interval();
		Interval(double , double);
		Interval& operator()(const double, const double);
		Interval& operator=(const Interval& i);
		Interval& unionInterval(const Interval&);
		Interval& intersectInterval(const Interval&);
		double len();
		void afficher()const;
		bool appartenir(const double);
	};
}


