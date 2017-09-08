#include "spaceobject.h"
#include <iostream>
using namespace std;

SpaceObject::SpaceObject()
{
}

//Setters
////Object's Specifications
void SpaceObject::SetParameters(char name, double vo, double elev, double bear, double m){
    ObjName        = name;
    Velocity       = vo;
    ElevationAngle = elev;
    BearingAngle   = bear;
    Mass           = m;
}
void SpaceObject::SetDimensions(double l, double w, double h){
    Length = l;
    Width  = w;
    Height = h;
}
////Object's Trajectory
void SpaceObject::SetTimeInterval(int SimTime){
    XTrajectoy = new double[SimTime];
    YTrajectoy = new double[SimTime];
    ZTrajectoy = new double[SimTime];
    TimeLine   = new double[SimTime];
}
void SpaceObject::SetTrajectories(double Xp, double Yp, double Zp, int t){
    XTrajectoy[t] = Xp;
    YTrajectoy[t] = Yp;
    ZTrajectoy[t] = Zp;
}
////Collision Detection
void SpaceObject::SetComparisonPoint(int cp){ComparisonPoint = cp;}

//Getters
////Object's Specifications
char   SpaceObject::GetName(){return ObjName;}
double SpaceObject::GetVelocity(){return Velocity;}
double SpaceObject::GetElevationAngle(){return ElevationAngle;}
double SpaceObject::GetBearingAngle(){return BearingAngle;}
double SpaceObject::GetMass(){return Mass;}
double SpaceObject::GetWidth(){return Width;}
double SpaceObject::GetHeight(){return Height;}
double SpaceObject::GetLength(){return Length;}
int    SpaceObject::GetCollisionPoint(){return CollisionPoint;}

////Object's Trajectory
double SpaceObject::GetXPoints(int  tp){return XTrajectoy[tp];}
double SpaceObject::GetYPoints(int  tp){return YTrajectoy[tp];}
double SpaceObject::GetZPoints(int  tp){return ZTrajectoy[tp];}
double SpaceObject::GetTimeLine(int tp){return TimeLine[tp];}
////Collision Detection Operator Overload
bool   SpaceObject::operator==(const SpaceObject& SpObj){
    if(this->XTrajectoy[ComparisonPoint]-0.5*Length >= SpObj.XTrajectoy[ComparisonPoint]-0.5*(SpObj.Length) &&
       this->XTrajectoy[ComparisonPoint]-0.5*Length <= SpObj.XTrajectoy[ComparisonPoint]+0.5*(SpObj.Length) &&
       this->YTrajectoy[ComparisonPoint]-0.5*Width  >= SpObj.YTrajectoy[ComparisonPoint]-0.5*(SpObj.Width)  &&
       this->YTrajectoy[ComparisonPoint]-0.5*Width  <= SpObj.YTrajectoy[ComparisonPoint]+0.5*(SpObj.Width)  &&
       this->ZTrajectoy[ComparisonPoint]-0.5*Height >= SpObj.ZTrajectoy[ComparisonPoint]-0.5*(SpObj.Height) &&
       this->ZTrajectoy[ComparisonPoint]-0.5*Height <= SpObj.ZTrajectoy[ComparisonPoint]+0.5*(SpObj.Height)){
       CollisionPoint = ComparisonPoint;
       return true;
    }
    else if(this->XTrajectoy[ComparisonPoint]+0.5*Length >= SpObj.XTrajectoy[ComparisonPoint]-(0.5*SpObj.Length) &&
            this->XTrajectoy[ComparisonPoint]+0.5*Length <= SpObj.XTrajectoy[ComparisonPoint]+(0.5*SpObj.Length) &&
            this->YTrajectoy[ComparisonPoint]+0.5*Width  >= SpObj.YTrajectoy[ComparisonPoint]-(0.5*SpObj.Width)  &&
            this->YTrajectoy[ComparisonPoint]+0.5*Width  <= SpObj.YTrajectoy[ComparisonPoint]+(0.5*SpObj.Width)  &&
            this->ZTrajectoy[ComparisonPoint]+0.5*Height >= SpObj.ZTrajectoy[ComparisonPoint]-(0.5*SpObj.Height) &&
            this->ZTrajectoy[ComparisonPoint]+0.5*Height <= SpObj.ZTrajectoy[ComparisonPoint]+(0.5*SpObj.Height)){
        CollisionPoint = ComparisonPoint;
        return true;
    }
    else
        return false;

}

SpaceObject::~SpaceObject()
{
}
