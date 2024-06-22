#ifndef INTERVAL_SET_H
#define INTERVAL_SET_H

#include "set.h"
#include "primitive_pair.h"

template <typename T>
class interval_set : public set<T>
{
    public:

        interval_set(const T& left, const T& right)
        {
            this->interval.left = left;       
            this->interval.right = right;       
        }

        virtual void set_elements(const primitive_vector<T>& vector)
        {
            primitive_vector<T> temp;
            std::size_t size = vector.get_size();

            for (std::size_t i = 0; i < size; ++i)
            {
                T element = vector[i];

                if(this->interval.left <= element && element <= this->interval.right)
                {
                    temp.push_back(element);
                }
            }
            
            this->elements = temp;  
        }

        virtual set<T>* clone() const
        {
            return new interval_set<T>(this->interval.left, this->interval.right);
        }

    private:
        primitive_pair<T, T> interval;
};



#endif