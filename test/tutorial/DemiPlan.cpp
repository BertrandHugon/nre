#include "DemiPlan.hpp"

DemiPlan::DemiPlan( Droite& _d, long long int _xc, long long int _yc) :
	d (_d),
	signeFonction (false) {
		if (_d.Fonction(_xc, _yc) > 0) {
			signeFonction = true;
		}
	};

DemiPlan::~DemiPlan() {};

// M(xm, ym) appartient-il au demi-plan ?
bool DemiPlan::appartient (long long int _xm, long long int _ym) {
	bool signeFonctionM = false;
	if (d.Fonction(_xm, _ym) > 0) {
			signeFonctionM = true;
	}
	return signeFonction == signeFonctionM;
};

