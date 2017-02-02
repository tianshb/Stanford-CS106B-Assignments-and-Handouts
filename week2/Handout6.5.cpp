
template <typename ElemType>)
void RemovDup(Vector<ElemType> &vec,int (cmp)(ElemType,ElemType))
{
    for(int i=0;i<vec.size();i++)
        for(int j=vec.size()-1;j>i;j--)
        {
            if(cmp(vec[i],vec[j])==0)
            {
                vec.removeAt(j);
            }
                
        }
}


int CompareIntAbsolute(int first, int second)
{
    first = abs(first);
    second = abs(second);
    if(first < second) return -1;
    else if(first > second) return 1;
    else return 0;
}

RemovDup(vector, CompareIntAbsolute);