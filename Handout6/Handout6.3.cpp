template <typename ElemType>
ElemType FindMax(Vector<ElemType> &v, int (cmpFn)(ElemType, ElemType) = OperatorCmp)
{
    ElemType max = v[0];
    for(int i = 1; i < v.size(); i++)
    {
        if(cmpFn(max, v[i]) < 0)
        {
            max = v[i];
        }
    }
    return max;
}

struct Car {
    string name;
    int weight;
    int numAirbags;
};


int CarCompare(Car first, Car second)
{
    int diffAirbags = first.numAirbags - second.numAirbags;
    if(diffAirbags == 0)
        return first.weight - second.weight;
    else
        return diffAirbags;
}
int main() {
    Vector<Car> cars;
    // assume variables have been initialized here
    Car safestCar = FindMax(cars, CarCompare);
    cout << safestCar.name << endl;
    return 0;
}

   
