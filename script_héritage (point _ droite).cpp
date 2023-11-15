#include <iostream>

using namespace std;

class point {
		int x, y;

	public:

		point() {
			x = y = 0;
		}

		point(int x, int y) {
			this -> x = x;
			this -> y = y;
		}

		point(const point& p) {
			x = p.x;
			y = p.y;
		}

		friend ostream& operator<< (ostream &o, const point&);
		friend istream& operator>> (istream &i, point&);

		void operator++ ();
		void operator-- ();
		int Val();

		int GetX();
		int GetY();
};



void point :: operator++ () {
	x++;
	y++;
}

void point :: operator-- () {
	x++;
	y++;
}

int point :: Val() {
	return x * y;
}

int point :: GetX() {
	return x;
}

int point :: GetY() {
	return y;
}

ostream& operator << (ostream &o, const point& p)  {
	printf("L'abscisse: ");
	o << p.x;
	printf("\n");
	printf("Le coordoné: ");
	o << p.y;
	printf("\n");
	return o;
}
istream& operator >> (istream &i, point& p) {
	i >> p.x >> p.y;
	return i;
}



//==================================================================================================



class droite: public point {
		int point::x, point::y;
		point P;
		int M;

	public:

		droite(): point(), P() {
			M = 0;
		}
		droite(int x, int y , const point& p, int M ): point(x, y), P(p) {
			this -> M = M;
		}
		droite(const droite& d) : point(d), P(d.P) {
			M = d.M;
		}

		friend ostream& operator << (ostream &o, const droite& d);
		friend istream& operator >> (istream &I, droite& D);

		void operator++ ();
		void operator-- ();

		int Val();

		point GetP();
		int GetM();
};




ostream& operator<< (ostream &o, const droite& d) {
	printf("La distance: ");
	o << d.M;
	printf("\n"); printf("\n");
	printf("------------Le point P------------");
	printf("\n");
	o << d.P;  
	printf("\n");
	printf("------------Le deuxième point------------");
	printf("\n");
	o << (point) d;
	return o;
}

istream& operator >> (istream &I, droite& d) {
	I >> d.P >> d.M >> d.x >> d.y;
	return I;
}

void droite :: operator++ () {
	P.point::operator++();
	M++;
}

void droite :: operator-- () {
	x--;
	y--;
	M--;
	P.point::operator--();
}

int droite :: Val() {
	return M;
}

point droite :: GetP() {
	return P;
}

int droite :: GetM() {
	return M;
}



int main() {

//petit test	

point P01(10,15);
droite D01(20,25,P01,1);

D01.droite::operator++();
cout << D01;

return 0;}
