
class Droite {

	public:
		Droite( long long int _xa,
			long long int _ya, 
			long long int _xb, 
			long long int _yb);
		Droite (Droite &);
		~Droite();

		// (ym - ya)(xb - xa) - (xm - xa)(yb - ya)
		inline long long int Fonction ( long long int xm, long long int ym); 
	private:

	// Droite passant par A (xa, ya) et B ( xb, yb)
	long long int xa;
	long long int ya;
	long long int xb;
	long long int yb;

};

