#include <iostream>
using namespace std;
class Box {
private:
    double length;
    double width;

public:
    // Default constructor
    Box() {
        length = 0.0;
        width = 0.0;
    }

    // Parameterized constructor
    Box(double l, double w) {
        length = l;
        width = w;
    }

    // Getter methods
    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    // Setter methods
    void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }

    // Method to get data
    void getData() const {
        std::cout << "Length: " << length << std::endl;
        std::cout << "Width: " << width << std::endl;
    }

    // Method to set data
    void setData(double l, double w) {
        length = l;
        width = w;
    }
};

int main() {
    // Using default constructor
    Box box1;
    std::cout << "Box 1:" << std::endl;
    box1.getData();
    std::cout << std::endl;

    // Using parameterized constructor
    Box box2(5.0, 3.0);
    std::cout << "Box 2:" << std::endl;
    box2.getData();
    std::cout << std::endl;

    // Using setter methods
    Box box3;
    box3.setLength(4.0);
    box3.setWidth(2.0);
    std::cout << "Box 3:" << std::endl;
    box3.getData();
    std::cout << std::endl;

    // Using getter methods
    Box box4;
    box4.setData(6.0, 3.0);
    std::cout << "Box 4:" << std::endl;
    std::cout << "Length: " << box4.getLength() << std::endl;
    std::cout << "Width: " << box4.getWidth() << std::endl;
	MessageBox("hello",*|*);
    return 0;
}

