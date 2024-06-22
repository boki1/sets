#ifndef CRITERION_SET_H
#define CRITERION_SET_H

#include "set.h"

template <typename T>
using predicate_function = bool (*)(const T&);

template <typename T>
class criterion_set : public set<T>
{
    public:

        criterion_set(predicate_function<T> p) : predicate(p) {}

        virtual set<T>* clone() const
        {
            return new criterion_set<T>(*this);
        }

        virtual bool operator[](const T& element)
        {
            return predicate(element);
        }

        virtual void set_elements(const primitive_vector<T>& vector)
        {
            primitive_vector<T> temp;
            std::size_t size = vector.get_size();

            for (std::size_t i = 0; i < size; ++i)
            {
                T element = vector[i];
                if(predicate(element))
                {
                    temp.push_back(element);
                }
            }
            
            this->elements = temp;  
        }

    private:
        predicate_function<T> predicate;
};

#endif