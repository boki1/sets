#ifndef INTERSECTION_SET_H
#define INTERSECTION_SET_H

#include "set.h"

template <typename T>
class intersection_set : public set<T>
{
    public:

        intersection_set(const primitive_vector<set<T>*>& vector)
        {
            std::size_t outer_size = vector.get_size();
            
            primitive_vector<T> temp;
            for (std::size_t i = 0; i < outer_size; ++i)
            {
                std::size_t inner_size = vector[i]->get_elements().get_size();

                for (std::size_t j = 0; j < inner_size; ++j)
                {
                    T element = vector[i]->get_elements()[j];
                    temp.push_back(element);
                }
            }   

            temp.bubble_sort();

            primitive_vector<T> temp_copy;
            std::size_t temp_size = temp.get_size();
            for (std::size_t i = 0; i < temp_size; ++i)
            {
                T i_element = temp[i];
                T i_plus_1_element = temp[i + 1];
                
                if(i_element == i_plus_1_element)
                {
                    temp_copy.push_back(i_element);
                }
            }

            this->elements = temp_copy;  
        }

        virtual set<T>* clone() const
        {
            return new intersection_set<T>(*this);
        }

    private:
};

#endif