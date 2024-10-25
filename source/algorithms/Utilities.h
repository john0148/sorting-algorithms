#ifndef UTILITIES_H
#define UTILITIES_H

template <class T>
void _swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif