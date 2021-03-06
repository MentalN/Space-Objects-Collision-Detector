#include <iostream>
#include <iomanip>
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
    cout << "Enably gravity (y/n)? "; cin >> GravitySwitch; Calculator.EnableGravity(GravitySwitch);
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
        Calculator.NoForceTrajectory();
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
        //Returning trajectory values to spaceObject
        for(int j = 0; j <= SimTime; j++){
            SpaceObjects[i].SetTrajectories(Calculator.GetXPoints(j), Calculator.GetYPoints(j), Calculator.GetZPoints(j), j);
        }
    }
    int NumCollisions=0;
    for(int i = 0; i < NumObjects; i++){
        for(int j = 0; j < NumObjects; j++){
            if(i==j)
                break;
            else{
                for(int k = 0; k <= SimTime; k++){
                    SpaceObjects[i].SetComparisonPoint(k);
                    if(SpaceObjects[i]==SpaceObjects[j]){
                        //NumCollisions++;
                        cout << "collision detected at time " << SpaceObjects[i].GetCollisionPoint() << endl;
                        break;
                    }
                    else
                        continue;
                }
            }
        }
    }

    //cout << "Number of collisions detected > " << NumCollisions << endl;

    //Test outputted values from SpaceObject objects
    for(int i = 0; i < NumObjects; i++){
        for(int j = 0; j <= SimTime; j++){
            cout << " >" << j << "  " << setprecision(4) << SpaceObjects[i].GetXPoints(j) << endl;
        }
    }

    //Values decay problem need to be solved, could be:
    // 1 - due to the conversion of degrees to radian5
    // 2 - Some array decay BS (maybe need to use const)
    // 3 - both
    // Update: setprecision(int) seems to help with it

    /*
    //To view and verify outputted trajectory values
    for(int i = 0; i < NumObjects; i++){
        for(int j = 0; j <= SimTime; j++){
            cout << " >" << j << "  " << setprecision(4) << Calculator.GetXPoints(j) << endl;
        }
    }
    */



}
