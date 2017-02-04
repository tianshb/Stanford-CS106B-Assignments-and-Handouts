#include <iostream>
#include "map.h"

using namespace std;

struct pointT {
    int x, y;
};

struct cityT {
    string name;
    pointT coordinates;
};



int main()
{
    Vector<cityT> cities={{Beijing,{1,2}},{Shanghai,{3,4}}};
    Map<string> nameMap;
    for(int cityIndex = 0; cityIndex < cities.size();cityIndex++)
    {
        cityT currCity = cities[cityIndex];
        string key = IntegerToString(currCity.coordinates.x) + "-" +IntegerToString(currCity.coordinates.y);
        nameMap.add(key, currCity.name);
    }
    return 0;
}
