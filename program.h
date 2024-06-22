#ifndef PROGRAM_H
#define PROGRAM_H

#include "primitive_string.h"
#include "primitive_vector.h"

#include "set.h"
#include "finite_set.h"
#include "interval_set.h"
#include "criterion_set.h"
#include "intersection_set.h"
#include "union_set.h"

#include "primitive_tuple.h"

const std::size_t byte_size = 16;

/*
std::uint16_t type_input = T & 0b11;
std::uint16_t type_set = (T >> 2) & 0b11111111111111;
*/

template <typename T>
class program
{
    public:
        program(const primitive_string& sets_names)
        {
            std::ifstream in(sets_names.get_data(), std::ios::binary);
            
            std::size_t outer_size = 0;
            primitive_vector<primitive_string> vector;

            if(in.is_open())
            {
                in >> outer_size;

                for (std::size_t i = 0; i < outer_size; ++i)
                {
                    std::size_t inner_size = 0;
                    in >> inner_size;

                    char* array = new char[inner_size + 1];
                    in >> array;
                    array[inner_size] = '\0';
                    
                    primitive_string temp(array, inner_size);
                    vector.push_back(temp);
                    delete[] array;
                }
            }
            in.close();
            
            primitive_tuple<std::uint16_t, std::uint16_t, 
            primitive_vector<primitive_string>>* almost_sets
                            =
                            new primitive_tuple<std::uint16_t, std::uint16_t, 
                            primitive_vector<primitive_string>>[outer_size * 8];
           
            for (std::size_t i = 0; i < outer_size; ++i)
            {
                std::ifstream in_too(vector[i].get_data(), std::ios::binary);
                if(in_too.is_open())
                {
                    std::uint16_t N_ = 0;
                    in_too >> N_;
                    almost_sets[i].first = N_;

                    std::uint16_t T_ = 0;
                    in_too >> T_;
                    almost_sets[i].second = T_;

                    primitive_vector<primitive_string> to_fill;
                    for (std::size_t j = 0; j < N_; ++j)
                    {
                        char* array = new char[byte_size + 1];
                        in_too >> array;
                        array[byte_size] = '\0';
                        primitive_string temp(array, byte_size);
                        to_fill.push_back(temp);          
                    }                  

                    almost_sets[i].third = to_fill;
                }
            }  
    
            primitive_vector<primitive_tuple<std::uint16_t, 
                                         std::uint16_t, 
                                         primitive_vector<primitive_string>>> vec(almost_sets, outer_size, outer_size * 8);
            this->almost_sets = vec;
            delete[] almost_sets;
        }


    private:
        primitive_vector<primitive_tuple<std::uint16_t, 
                                         std::uint16_t, 
                                         primitive_vector<primitive_string>>> almost_sets;
        set<primitive_vector<T>>* result;
};



#endif