//INTRO32.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>
#include <string.h>

struct planet {
	char name[10];
	float distance;
	float radius;
};

planet mars;

int main()
{
	strcpy(mars.name,"Mars");
	mars.distance = 1.5;
	mars.radius = 0.4;

	cout << "Planetary statistics:\n";
	cout << "Name: "<< mars.name << '\n';
	cout << "Distance from Sun in AU: " << mars.distance << '\n';
	cout <<"Radius in Earth radii: " << mars.radius;

	return 0;
}
