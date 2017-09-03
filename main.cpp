#include <iostream>
#include <vector>
#include "spaceobject.h"
#include "calctrajectory.h"
using namespace std;

int main(){

    calcTrajectory Calculator;
    int NumObjects, SimTime; char GravitySwitch;
    cout << "Enter number of Space Objects in the simulation > "; cin  >> NumObjects;
    std::vector<SpaceObject> SpaceObjects;
    SpaceObjects.resize(NumObjects);
    cout << "Enter time duration of the simulation > "; cin  >> SimTime; Calculator.SetTimeInterval(SimTime);
    cout << "Enably gravity (y/n)?"; cin >> GravitySwitch; Calculator.EnableGravity(GravitySwitch);
    cout << "__________________________________________________" << endl;

    char name, DimensionSwitch;
    double velocity, elevation, bearing, mass, length, width, height;
    for(int i = 0; i < NumObjects; i++){
        SpaceObjects[i].SetTimeInterval(SimTime);
        cout << "-------------| Space Object [" << i+1 << "] |-------------" << endl;
        cout << "Name of the object (accepts only letters) > "      ; cin  >> name;
        cout << "Initial velocity > "                               ; cin  >> velocity;
        cout << "Elevation (Azimuth) angle, relative to xy-plane > "; cin  >> elevation;
        cout << "Bearing (Direction) angle, relative to x-axis   > "; cin  >> bearing;
        cout << "Mass > "                                           ; cin  >> mass;
        SpaceObjects[i].SetParameters(name, velocity, elevation, bearing, mass);
        cout << "Set object's box dimensions (y/n)? "               ; cin  >> DimensionSwitch;
        if(DimensionSwitch == 'y'){
             cout << "Length > "; cin >> length; cout << "Width > "; cin >> width; cout << "Height > "; cin >> height;
             SpaceObjects[i].SetDimensions(length, width, height);}
        else{
             cout << "Objects dimensions set to default." << endl;}
    }

    int ti, tf;
    double x, y, z;
    char ForceSwitch1, ForceSwitch2;
    for(int i = 0; i < NumObjects; i++){
        cout << "-------------| Space Object [" << SpaceObjects[i].GetName() << "] Initial Location Coordinates |-------------" << endl;
        cout << "x-Coordinate > "; cin >> x; cout << "y-Coordinate > "; cin >> y; cout << "z-Coordinate > "; cin >> z;
        Calculator.SetStartLocation(x, y, z);
        velocity  = SpaceObjects[i].GetVelocity();
        elevation = SpaceObjects[i].GetElevationAngle();
        bearing   = SpaceObjects[i].GetBearingAngle();
        mass      = SpaceObjects[i].GetMass();
        Calculator.TakeObjectParameters(velocity, elevation, bearing, mass);
        cout << "Apply forces (y/n)? "; cin >> ForceSwitch1;
        if(ForceSwitch1 == 'y'){
            while(1){
                cout << " Fx > "; cin >> x; cout << " Fy > "; cin >> y; cout << " Fz > "; cin >> z;
                cout << " Interval start timpoint > "; cin >> ti; cout << " Interval end timpoint > "; cin >> tf;
                Calculator.ApplyForce(x, y, z, ti, tf);
                cout << " Apply a force on another interval (y/n)? "; cin >> ForceSwitch2;
                if(ForceSwitch2 == 'y')
                    continue;
                else
                    break;
            }
        }
        else
            Calculator.ApplyForce(0,0,0,0,SimTime);
    }

    for(int i = 0; i < NumObjects; i++){
        for(int j = 0; j < SimTime; j++){
            cout << " >" << j << "  " << Calculator.GetXPoints(j) << endl;
        }
    }



}
