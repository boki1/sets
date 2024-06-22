#ifndef SET_H
#define SET_H

#include "primitive_vector.h"

template <typename T>
class set
{
    public:

        virtual bool operator[](const T& element) const
        {
            std::size_t size = this->elements.get_size();
            for (std::size_t i = 0; i < size; ++i)
            {
                if(elements[i] == element)
                {
                    return true;
                }
            }
            return false;
        }

        virtual ~set() {};
        virtual set* clone() const = 0;

        virtual const primitive_vector<T>& get_elements() const
        {
            return this->elements;
        }

        virtual void set_elements(const primitive_vector<T>& vector)
        {
            this->elements = vector;
        }

    protected:
        primitive_vector<T> elements;
};


#endif