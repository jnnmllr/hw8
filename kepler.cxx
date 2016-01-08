/* Homework 8 */
/* symplectic Euler method */

#include <fstream>
#include <cmath>

using namespace std;

void step(double* q, double* p, const double dt);

int main(){

/* constants */
const double pi   = 3.1416;
const double e    = 0.6;
const double dt   = 0.0005;
const double tEnd = 20*pi;
const double t0   = 0;
const double N    = (tEnd-t0)/dt;

/* declare arrays for p and q */
double p[2],q[2];
/* define initial conditions */
q[0]=1.0-e; q[1]=0; p[0]=0; p[1]=sqrt((1.0+e)/(1.0-e));
/* zusätzlich brauch man noch H,
   was nach jedem Schritt berechnet werden soll */
double H;


ofstream out("Data.txt");

/* Schleife für q,p */
for(int i=0;i<N;i++){

/* Berechnung von H */
H = 0.5 * (pow(p[0],2)+pow(p[1],2)) - 1.0/(sqrt(pow(q[0],2)+pow(q[1],2)));

/* Ausgabe von q1, q2, H und t */
 out << q[0] << " " << q[1] << " " << H << " " << i*dt << endl;
/* Anwendung der Fkt 'step', welche die nächsten q1-,q2-,p1-,p2-Werte berechnet */
 step(q,p,dt);
}

out.close();
return 0;
}

void step(double* q, double* p, const double dt){
/* berechne neues p und überschreibe dabei das alte */
p[0] -= dt*(1.0/pow((pow(q[0],2)+pow(q[1],2)),3.0/2.0))*q[0];
p[1] -= dt*(1.0/pow((pow(q[0],2)+pow(q[1],2)),3.0/2.0))*q[1];

/* das gleiche für q */
q[0] += dt*p[0];
q[1] += dt*p[1];
}
