#include "Droite.hpp"

Droite::Droite( long long int _xa,
		long long int _ya, 
		long long int _xb, 
		long long int _yb) :
	xa (_xa),
	ya (_ya),
	xb (_xb),
	yb (_yb)
{};

Droite::Droite( Droite& dd) :
	xa (dd.xa),
	ya (dd.ya),
	xb (dd.xb),
	yb (dd.yb)
{};
	
Droite::~Droite() {};

long long int Droite::Fonction ( long long int xm, long long int ym) {
	return (ym - ya) * (xb - xa) - (xm - xa) * (yb - ya);
}


