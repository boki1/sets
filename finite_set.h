#ifndef FINITE_SET_H
#define FINITE_SET_H

#include "set.h"

template <typename T>
class finite_set : public set<T>
{
    public:

        finite_set(primitive_vector<T>& vector)
        {
            vector.bubble_sort();

            primitive_vector<T> temp;
            std::size_t size = vector.get_size();

            for (std::size_t i = 0; i < size; ++i)
            {
                T i_element = vector[i];
                T i_plus_1_element = vector[i + 1];
                
                if(i_element != i_plus_1_element)
                {
                    temp.push_back(i_element);
                }
            }

            this->elements = temp;
        }

        virtual set<T>* clone() const
        {
            return new finite_set<T>(*this);
        }

    private:
};



#endif