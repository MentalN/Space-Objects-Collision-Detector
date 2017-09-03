#ifndef CALCTRAJECTORY_H
#define CALCTRAJECTORY_H


class calcTrajectory
{
public:
    calcTrajectory();
    //Setters
    void SetStartLocation(double, double, double);
    void EnableGravity(char);
    void EnableGravity(int);
    void TakeObjectParameters(double, double, double, double);
    void SetTimeInterval(int);
    void ApplyForce(double, double, double, int, int);
    //void ResetCalculator();
    void CleanUpWhendone();
    //Getters
    double GetXPoints(int);
    double GetYPoints(int);
    double GetZPoints(int);
protected:
    //Object's Specifications
    double xi = 0, yi = 0, zi = 0;
    double g = 0;
    double m, vo, elev, bear;
    //Object's Trajectory Arrays
    double *Xcoords;
    double *Ycoords;
    double *Zcoords;
};

#endif // CALCTRAJECTORY_H
