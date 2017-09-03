#include "calctrajectory.h"
#include <iostream>
#include <math.h>
using namespace std;

calcTrajectory::calcTrajectory(){}

//Setters
void calcTrajectory::SetStartLocation(double xo, double yo, double zo){
    xi = xo;
    yi = yo;
    zi = zo;
}
void calcTrajectory::EnableGravity(char grav){
    if (grav == 'y' || grav == 'Y')
        g = 9.807;
    else
        g = 0;
}
void calcTrajectory::EnableGravity(int grav){
    if (grav == 1)
        g = 9.807;
    else
        g = 0;
}
void calcTrajectory::TakeObjectParameters(double vel, double ele, double bea, double mass){
    vo   = vel;
    elev = ele;
    bear = bea;
    m    = mass;
}
void calcTrajectory::SetTimeInterval(int SimTime){
    Xcoords = new double[SimTime];
    Ycoords = new double[SimTime];
    Zcoords = new double[SimTime];
}
//Problems here
///Forces dt is not correctly defined
///Didn't account for no force intervals
void calcTrajectory::ApplyForce(double fx, double fy, double fz, int ti, int tf){
    for (ti; ti < tf; ti++) {
        Xcoords[ti] = vo*cos(bear*0.0174533)*cos(elev*0.0174533)*ti + 0.5*(fx/m)*pow(ti,2) + xi;
        Ycoords[ti] = vo*sin(bear*0.0174533)*cos(elev*0.0174533)*ti + 0.5*(fy/m)*pow(ti,2) + yi;
        Zcoords[ti] = vo*sin(elev*0.0174533)*ti - 0.5*g*pow(ti,2)   + 0.5*(fz/m)*pow(ti,2) + zi;
    }
}
//void calcTrajectory::ResetCalculator(){t = 0;}
void calcTrajectory::CleanUpWhendone(){
    delete[] Xcoords;
    Xcoords = NULL;
    delete[] Ycoords;
    Ycoords = NULL;
    delete[] Zcoords;
    Zcoords = NULL;
}

//Getters
double calcTrajectory::GetXPoints(int tp){return Xcoords[tp];}
double calcTrajectory::GetYPoints(int tp){return Ycoords[tp];}
double calcTrajectory::GetZPoints(int tp){return Zcoords[tp];}

