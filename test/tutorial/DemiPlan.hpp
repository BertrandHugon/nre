#include "Droite.hpp"

class DemiPlan {

	public:
		// Demi-plan délimité par d auquel appartient C (xc, yc)
		DemiPlan( Droite& d, long long int xc, long long int yc);
		~DemiPlan();

		// M(xm, ym) appartient-il au demi-plan ?
		bool appartient (long long int xm, long long int ym);

	private:
		Droite d;
		bool signeFonction; // false si <= 0, true si > 0
};

