# include <bits/stdc++.h>
using namespace std;

const double EPS = 0.000000001;

struct Point {
	double x, y;

	Point(double a = 0, double b=0){
		x = a; y = b;
	}

	double Dist(Point p1){
		return pow((pow(x-p1.x,2)+pow(y-p1.y, 2)), 1.0/2.0);
	}

	Point operator - (const Point &p)const{
		return Point(x-p.x, y-p.y);
	}

	Point operator + (const Point &p)const{
		return Point(x+p.x, y+p.y);
	}
};

struct Vector{
	double a, b;

	Vector (Point p1=Point(0, 0), Point p2=Point(0, 0)){
		a = p2.x-p1.x;
		b = p2.y-p1.y;
	}

	private: Vector Normal(){
		return Vector(a, -b);
	};
};

struct Recta{
	double A, B, C;

	Recta(Point p1, Point p2){
		Vector v = Vector(p1, p2);
		A = v.b;
		B = -v.a;
		C = v.a*p1.y - v.b*p1.x;
		Normalizar();
	}
	
	Recta(double a = 0, double b = 0, double c = 0){
		A = a;
		B = b;
		C = c;
		Normalizar();

	}
	///Vector v, vetor normal a la recta
	///que se quiere obtener
	void Recta1(Vector v, Point p){
		A = v.a;
		B = v.b;
		C = -A*p.x-B*p.y;
		Normalizar();
	}
	//Rectas Paralelas
	bool operator == (const Recta &P)const{
		return A==P.A && B == P.B;
	}

	private:

	void Normalizar(){
		 if(A < 0)
			A*=-1, B*=-1, C*=-1;
		 if(A == 0 && B < 0)
			B *= -1,C*= -1;
	}
	
	double Dist_Point(Point p){
		return abs(A*p.x+B*p.y+C)/pow(A*A+B*B, 1.0/2.0);
	}

	Point Intersection_Recta(Recta R2){
		Point p;
		Recta R1 = Recta(A, B, C);

		if(R1.A == 0)swap(R1, R2);
		p.y = (-R2.C*R1.A+R1.C*R2.A)/(R1.A*R2.B-R2.A*R1.B);
		p.x = (-R1.B*p.y-R1.C)/R1.A;

		return p;
	}
};

struct Circulo{
	double h, k, r;

	Circulo (Point p = Point(0, 0), double q = 0){
		h = p.x;
		k = p.y;
		r = q;
	}

	bool operator < (const Circulo &Q)const{
		if(h != Q.h)return h < Q.h;
		if(k != Q.k)return k < Q.k;
		return r < Q.r;
	}

	/// op-> diferenciar que punto devolver
	Point Interseccion_Recta(Recta R, int op){
		double x0 = -R.A*R.C/(R.A*R.A+R.B*R.B),
			y0 = -R.B*R.C/(R.A*R.A+R.B*R.B);

		if (R.C*R.C > r*r*(R.A*R.A + R.B*R.B)+EPS)
			return Point(-100000.0, -100000.0);
		else if (abs (R.C*R.C - r*r*(R.A*R.A+R.B*R.B)) < EPS) {
			//puts ("1 point");
			//cout << x0+h << ' ' << y0+k << '\n';
			return Point(x0+h, y0+k);
		}
		else {
			double d = r*r - R.C*R.C/(R.A*R.A+R.B*R.B);
			double mult = sqrt (d / (R.A*R.A+R.B*R.B));
			double ax,ay,bx,by;
			ax = x0 + R.B * mult + h;
			bx = x0 - R.B * mult + h;
			ay = y0 - R.A * mult + k;
			by = y0 + R.A * mult + k;

			if(op == 1)
				return Point(ax, ay);
			else
				return Point(bx, by);
		}
	}
	///op >
	Point Interseccion_Circle(Circulo C, int op){
		return Interseccion_Recta(Recta(2.0*(C.h-h), 2.0*(C.k-k), -(C.h-h)*(C.h-h)-(C.k-k)*(C.k-k)-r*r+C.r*C.r), op);
	}

	bool is_Interseccion_Circle(Circulo C){
		if((h-C.h)*(h-C.h)+(k-C.k)*(k-C.k) <= (r+C.r)*(r+C.r))
			return true;
		return false;
	}

	bool is_Inside_Circle(Point p){
		if((p.x-h)*(p.x-h)+(p.y-k)*(p.y-k) <= r*r+EPS)
			return true;
		return false;
	}

};


 int main(){
 }
