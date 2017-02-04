template <typename ElemType>
class Mob {
public:
    Mob();
    void enqueue(ElemType newElem);
    ElemType dequeue();
    int size();
private:
    Vector<ElemType> elems;
};
(Mob.cpp):
template <typename ElemType>
void Mob<ElemType>::enqueue(ElemType newElem)
{
    elems.add(newElem);
}
template <typename ElemType>
ElemType Mob<ElemType>::dequeue()
{
    int elemNum = RandomInteger(0, elems.size()-1);
    ElemType value = elems[elemNum];
    elems.removeAt(elemNum);
    return value;
}
