#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Design a parking lot using object-oriented principles.
 */

class Vehicle
{
  public:
    virtual ~Vehicle() { }

    virtual VehicleType type() const = 0;
};

class ParkingSpace
{
  public:
    ParkingSpace() : width(12), length(12), timeLimit(2), 
                     empty(true), handicap(false) { }

    virtual ~ParkingSpace() { }

    bool fill(Vehicle v)
    { 
      if(!empty)
      { // space not available, already filled
        return false;
      }
      if(carWidth > width || carLength > length)
      { // car does not fit
        return false;
      }
      return true;
    }

    bool isEmpty() const { return empty; }

    bool isHandicap() const { return handicap; }

    int timeLimit() const { return timeLimit; }

    int width() const { return width; }

    int length() const { return length; }

    int area() const { return length*width; }

  protected:
    int width, length, timeLimit;

  private:
    bool empty, handicap;
};

class HandicapSpace : public ParkingSpace
{
  public:
    HandicapSpace() : handicap(true)
    
    virtual ~HandicapSpace() {  }
};

class MotorcycleSpace : public ParkingSpace
{
  public:

};

class CompactSpace : public ParkingSpace
{

};

class ParkingLot
{
  public:


};


int main(int argc, const char *argv[])
{

  
  return 0;
}
