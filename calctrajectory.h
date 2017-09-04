#ifndef CALCTRAJECTORY_H
#define CALCTRAJECTORY_H


class calcTrajectory
{
public:
    calcTrajectory();
    //Setters
    void SetTimeInterval(int);
    void EnableGravity(char);
    void EnableGravity(int);
    void SetStartLocation(double, double, double);
    void TakeObjectParameters(double, double, double, double);
    void NoForceTrajectory();
    void ApplyForce(double, double, double, int, int);
    void CleanUpWhendone();
    //Getters
    double GetXPoints(int);
    double GetYPoints(int);
    double GetZPoints(int);
protected:
    //Calculations related variables
    int ts, dt;
    double g = 0;
    //Object's Specifications
    double xi = 0, yi = 0, zi = 0;
    double m, vo, elev, bear;
    //Object's Trajectory Arrays
    int    ArraySize;
    double *Xcoords;
    double *Ycoords;
    double *Zcoords;
};

#endif // CALCTRAJECTORY_H
