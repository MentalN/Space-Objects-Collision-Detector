#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H


class SpaceObject
{
public:
    SpaceObject();
    //Setters
    ////Object's Specifications
    void SetParameters(char, double, double, double, double);
    void SetDimensions(double, double, double);
    ////Object's Trajectory
    void SetTimeInterval(int);
    void SetTrajectories(double, double, double, int);
    ////Collision Detection
    void SetComparisonPoint(int);

    //Getters
    ////Object's Specifications
    char   GetName();
    double GetVelocity();
    double GetElevationAngle();
    double GetBearingAngle();
    double GetMass();
    double GetWidth();
    double GetHeight();
    double GetLength();
    ////Object's Trajectory
    double GetXPoints(int);
    double GetYPoints(int);
    double GetZPoints(int);
    double GetTimeLine(int);
    ////Collision Detection
    bool operator==(const SpaceObject&);
    int  GetCollisionPoint();
    ~SpaceObject();

protected:
    //Specifications related variables
    char   ObjName;
    double Velocity;
    double BearingAngle, ElevationAngle;
    double Mass;
    double Length = 1, Width = 1, Height = 1;
    //Trajectory arrays
    double *XTrajectoy;
    double *YTrajectoy;
    double *ZTrajectoy;
    double *TimeLine;
    //Collision Detection
    int ComparisonPoint;
    int CollisionPoint;
};

#endif // SPACEOBJECT_H
