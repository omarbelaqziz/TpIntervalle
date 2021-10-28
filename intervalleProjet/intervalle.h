#pragma once
class intervalle
{
private:
	double sup;
	double inf;
public:
	intervalle(double x = 0, double y = 0);
	double min() const;
	double max() const;
	bool operator[](double x) const;
	bool operator[](intervalle& x) const;
	intervalle& operator+(intervalle& i) const;
	intervalle& operator-(intervalle& i) const;
	void afficher();

};

