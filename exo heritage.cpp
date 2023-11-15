/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class point{
    protected:
    int x,y;
    public:
    point(){x=y=0;}
    point(int a, int b){x=a;y=b;}
    point(point&P){x=P.x;y=P.y}
    friend ostream & operator<< (ostream &O, point& A);
    friend istream & operator>> (istream &I, point& A);
    void operator++(){
        x++;
        y++;
    }
    int val() {return x*y;}
    int getx(){return x;}
    int gety(){return y;}
    friend void droite::operator--();
}

ostream & operator<< (ostream &O, point& A){
    O << A.x << "," << A.y;
    return O;
}

istream & operator>> (istream &I, point& A){
    I >> A.x >> A.y;
    return I;
}

class droite:public point{
    //int x,y;
    point A;
    int M;
    public:
        droite():point(),A(){
            M=0;
        }
        droite(int x, int y, point& P, int M):A(P),point(x,y){
            this->M =M;
        }
        droite(droite & D):A(D.A),point(D){
            M = D.M;
        }
        friend ostream& operator << (ostream &O, droite& D);
        friend istream& operator >> (istream &I, droite& D);
        void operator++(){
            M++;
            A++;
            point::operator++();
        }
        void operator--(){
            M--;
            A.x--;
            A.y--;
            x--;
            y--;
        }
        
        int val(){
            return M;
        }
        
        point getA(){return A;}
        int getM(){return M;}
}

ostream& operator << (ostream &O, droite& D){
    O << D.A << D.M << D.x << D.y;
    // O << D.A << D.M << (point)D;
}

istream& operator >> (istream &I, droite& D){
    I >> D.A >> D.M >> (point)D;
}





int main()
{
    cout<<"Hello World";

    return 0;
}
