#include <cmath>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "DemiPlan.hpp"

using namespace cv;

void Esperanta(Mat& mat, unsigned int n) {
	const double PI = 3.14159265;
	const double co = cos (2*PI/5);
	const double si = sin (2*PI/5);

	Point2i A(10*n, 0);
	Point2i B(10*n, 10*n);
	Point2i C(0, 10*n);

	Point2i D(5*n - n*7/2, 5*n);

	double xe = - co * n * 7 / 2;
	double ye = - si * n * 7 / 2;
	Point2i E(5*n + static_cast<int>(xe), 5*n + static_cast<int>(ye));

	double xf = co * xe - si * ye;
	double yf = si * xe + co * ye;
	Point2i F(5*n + static_cast<int>(xf), 5*n + static_cast<int>(yf));

	double xg = co * xf - si * yf;
	double yg = si * xf + co * yf;
	Point2i G(5*n + static_cast<int>(xg), 5*n + static_cast<int>(yg));

	double xh = co * xg - si * yg;
	double yh = si * xg + co * yg;
	Point2i H(5*n + static_cast<int>(xh), 5*n + static_cast<int>(yh));
 
	Droite AB(A.x, A.y, B.x, B.y);
	Droite BC(B.x, B.y, C.x, C.y);

	Droite DF(D.x, D.y, F.x, F.y);
	Droite EG(E.x, E.y, G.x, G.y);
	Droite FH(F.x, F.y, H.x, H.y);
	Droite GD(G.x, G.y, D.x, D.y);
	Droite HE(H.x, H.y, E.x, E.y);

	DemiPlan OAB(AB, 0, 0);
	DemiPlan OBC(BC, 0, 0);

	DemiPlan IDF(DF, 5*n, 5*n);
	DemiPlan IEG(EG, 5*n, 5*n);
	DemiPlan IFH(FH, 5*n, 5*n);
	DemiPlan IGD(GD, 5*n, 5*n);
	DemiPlan IHE(HE, 5*n, 5*n);

    	for (int i = 0; i < 20*n ; i ++) {
	    for (int j = 0; j < 30*n; j ++) {
		// std::cout << "M.at(" << i << "," << j << ") = " << static_cast<unsigned int>(M.at<unsigned char>(i,j)) << std::endl;
		if (OAB.appartient(i, j) && OBC.appartient(i, j)) {
			bool idf = IDF.appartient(i, j);
			bool ieg = IEG.appartient(i, j);
			bool ifh = IFH.appartient(i, j);
			bool igd = IGD.appartient(i, j);
			bool ihe = IHE.appartient(i, j);
			if (   (! idf && ! (ieg && ihe))
			    || (! ieg && ! (ifh && idf))
			    || (! ifh && ! (igd && ieg))
			    || (! igd && ! (ihe && ifh))
		            || (! ihe && ! (idf && igd))) {
				mat.at<unsigned char>(i,3*j) = 255;	
				mat.at<unsigned char>(i,3*j + 1) = 255;	
				mat.at<unsigned char>(i,3*j + 2) = 255;	
			 }
	    	}
	    }
    }
}

void Drapeau( unsigned int n) {
	Mat M(20*n, 30*n, CV_8UC3, Scalar(0,0x9F,0x6B));
	Esperanta(M, n);
	namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
	    imshow( "Display window", M );                // Show our image inside it.
	        waitKey(0); // Wait for a keystroke in the window
}
 
int main (int argc, char ** argv) {

    Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    std::cout << "M = " << std::endl << " " << M << std::endl << std::endl;
    for (int i = 0; i < 2 ; i ++) {
	    for (int j = 0; j < 6; j ++) {
    		std::cout << "M.at(" << i << "," << j << ") = " << static_cast<unsigned int>(M.at<unsigned char>(i,j)) << std::endl;
	    }
    }
    Point2i P(5, 1);
    std::cout << "Point (2D) = " << P << std::endl << std::endl;

    Drapeau(20);

    return 0;
}

