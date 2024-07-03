
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename Func>

void iter(T *array, size_t len, Func f)
{
    for(size_t i = 0; i < len; i++)
        f(array[i]);
}

#endif