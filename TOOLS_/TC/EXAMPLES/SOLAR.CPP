//SOLAR.CPP--Example from Chapter 3, "An Introduction to C++"

#include <graphics.h>
#include <iostream.h>
#include <string.h>

struct planet {
	char name[10];
	float distance;
	float radius;
	int color;
	int fill_type;
};

planet solar_system[9];
planet *planet_ptr;
int    planet_num;

int main()
{
	strcpy(solar_system[0].name,"Mercury");
	solar_system[0].distance = 0.4;
	solar_system[0].radius = 0.4;
	solar_system[0].color = EGA_YELLOW;
	solar_system[0].fill_type = EMPTY_FILL;

	planet_ptr = solar_system;
	planet_ptr++;             // Point to second planet structure
	 strcpy (planet_ptr->name,"Venus");
	planet_ptr->distance = 0.7;
	planet_ptr->radius = 1.0;
	planet_ptr->color = EGA_BROWN;
	planet_ptr->fill_type = SOLID_FILL;

	planet_ptr = solar_system;         // Reset to first element
	for (planet_num = 0; planet_num < 2; planet_num++, planet_ptr++) 
        {
	   cout << " \nPlanetary statistics: ";
	   cout << " \nName: "<< planet_ptr->name;
	   cout << " \nDistance from Sun in AU: "<< planet_ptr->distance;
	   cout << " \nRadius in Earth radii: "<<  planet_ptr->radius;
	   cout << " \nColor constant value "<< planet_ptr->color;
	   cout << " \nFill pattern constant value "<< planet_ptr->fill_type;
        }

   return 0;
}
