#include "intervalle.h"
#include <iostream>
using namespace std;

intervalle::intervalle(double x, double y) 
{
	if(x<=y)
	{
		this->inf = x;
		this->sup = y;
	}
	else 
	{
		this->inf = y;
		this->sup = x;
	}
}

double intervalle::min() const
{
	return this->inf;
}

double intervalle::max() const
{
	return this->sup;
}

bool intervalle::operator[](double x) const
{
	if (this->inf <= x && x <= this->sup)
		return true;
	return false;
}

bool intervalle::operator[](intervalle& x) const
{
	if ((this->min() <= x.min()) && (this->max() >= x.max()))
		return true;
	return false;
}

intervalle& intervalle::operator+(intervalle& i) const
{
	double tempMax = 0;
	double tempMin = 0;

	if (i.sup >= this->inf && this->sup >= i.inf)
	{
		// recuperer le maximum le plus extreme 
		if (this->sup < i.sup)
			tempMax = i.sup;
		else tempMax = this->sup;
		// recuperer le minimum le plus extreme 
		if (this->inf < i.inf)
			tempMin = this->inf;
		else tempMin = i.inf;
	}

	return *(new intervalle(tempMin, tempMax));
}


intervalle& intervalle::operator-(intervalle& i) const
{
	double tempMax = 0;
	double tempMin = 0;

	if ((*this)[i.sup] || i[this->sup])
	{
		// recuperer le maximum le plus interne 
		if (this->sup < i.sup)
			tempMax = this->sup;
		else tempMax = i.sup;
		// recuperer le minimum le plus interne 
		if (this->inf < i.inf)
			tempMin = i.inf;
		else tempMin = this->inf;
	}

	return *(new intervalle(tempMin, tempMax));
}

void intervalle::afficher()
{
	cout << "le min est :" << this->inf << endl;
	cout << "le max est :" << this->sup << endl;
}
