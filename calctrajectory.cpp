#include "calctrajectory.h"
#include <iostream>
#include <math.h>
using namespace std;


calcTrajectory::calcTrajectory(){}

//Setters
void calcTrajectory::SetTimeInterval(int SimTime){
    ArraySize = SimTime;
    Xcoords = new double[ArraySize];
    Ycoords = new double[ArraySize];
    Zcoords = new double[ArraySize];
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
void calcTrajectory::SetStartLocation(double xo, double yo, double zo){
    xi = xo;
    yi = yo;
    zi = zo;
}
void calcTrajectory::TakeObjectParameters(double vel, double ele, double bea, double mass){
    vo   = vel;
    elev = ele;
    bear = bea;
    m    = mass;
}
void calcTrajectory::NoForceTrajectory(){
    for(int i = 0; i <= ArraySize; i++){
        Xcoords[i] = vo*cos(bear*0.0174533)*cos(elev*0.0174533)*i + xi;
        Ycoords[i] = vo*sin(bear*0.0174533)*cos(elev*0.0174533)*i + yi;
        Zcoords[i] = vo*sin(elev*0.0174533)*i - 0.5*g*pow(i,2)    + zi;
    }
}
void calcTrajectory::ApplyForce(double fx, double fy, double fz, int ti, int tf){
    ts = ti;
    for(ti; ti <= tf; ti++){
        dt = ti - ts;
        Xcoords[ti] = Xcoords[ti] + 0.5*(fx/m)*pow(dt,2);
        Ycoords[ti] = Ycoords[ti] + 0.5*(fy/m)*pow(dt,2);
        Zcoords[ti] = Zcoords[ti] + 0.5*(fz/m)*pow(dt,2);
    }
    tf++;
    for(tf; tf <= ArraySize; tf++){
        Xcoords[tf] = Xcoords[tf] + 0.5*(fx/m)*pow(dt,2);
        Ycoords[tf] = Ycoords[tf] + 0.5*(fy/m)*pow(dt,2);
        Zcoords[tf] = Zcoords[tf] + 0.5*(fz/m)*pow(dt,2);
    }
}
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

