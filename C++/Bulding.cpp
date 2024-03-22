//#include <iostream>
//using namespace std;
//
//class Getter{
//	public:
//		void areainsqft(){
//			return totalarea / givenarea;
//		}
//		void 
//};













#include <iostream>

class Building {
private:
    int area;

public:
    int occupants;
    int floors;

    Building(int initialArea, int initialOccupants, int initialFloors) {
        area = initialArea;
        occupants = initialOccupants;
        floors = initialFloors;
    }

    int getArea() const {
//    	int narea = area / noccupants;
        return narea;
    }

    void setArea(int newArea) {
        area = newArea;
    }

    int getOccupants() const {
        return occupants;
    }

    void setOccupants(int newOccupants) {
        occupants = newOccupants;
    }

    int getFloors() const {
        return floors;
    }

    void setFloors(int newFloors) {
        floors = newFloors;
    }

    void showData() const {
        std::cout << "Area: " << area << " sq.ft" << std::endl;
        std::cout << "Occupants: " << occupants << std::endl;
        std::cout << "Floors: " << floors << std::endl;
    }
};

int main() {
    Building myBuilding(5000, 50, 5);

    std::cout << "Initial Building Data:" << std::endl;
    myBuilding.showData();

    myBuilding.setArea(6000);
    myBuilding.setOccupants(60);

    std::cout << "\nUpdated Building Data:" << std::endl;
    myBuilding.showData();

    return 0;
}

