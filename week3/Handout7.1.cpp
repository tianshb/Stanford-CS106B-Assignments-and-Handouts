a)
template <typename Type>
void Stack<Type>::reverse() {
    for (int lh = 0, rh = elems.size()-1; lh < rh; rh--, lh++)
    {
        Swap(elems[lh], elems[rh]);
    }
}

b)
template <typename Type>
void reverse(Stack<Type> &s) {
    Stack<Type> t;
    while (!s.isEmpty())
    {
        t.push(s.pop());
    }
    s = t;
}