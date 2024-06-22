#ifndef PRIMITIVE_STRING_H
#define PRIMITIVE_STRING_H

#include <iostream>
#include <fstream>

class primitive_string
{
    public:
        primitive_string()
        {
            this->size = 0;
            this->data = new char[this->size + 1];
            this->data[this->size] = '\0';
        }

        primitive_string(const char* data, const std::size_t size)
        {
            this->size = size;
            this->data = new char[this->size + 1];
            for (std::size_t i = 0; i < this->size; ++i)
            {
                this->data[i] = data[i];
            }
            this->data[this->size] = '\0';
        }

        primitive_string(const primitive_string& other)
        {
            copy(other);
        }

        primitive_string& operator=(const primitive_string& other)
        {
            if(this != &other)
            {
                free();
                copy(other);
            }
            return *this;
        }

        ~primitive_string()
        {
            free();
        }

        const char* get_data() const
        {
            return this->data;
        }

        const std::size_t get_size() const
        {
            return this->size;
        }

        void set_data(const char* data)
        {
            this->data = new char[this->size + 1];
            for (std::size_t i = 0; i < this->size; ++i)
            {
                this->data[i] = data[i];
            }
            this->data[this->size] = '\0';
        }

        void set_size(const std::size_t size)
        {
            this->size = size;
        }

        void print() const
        {
            for (std::size_t i = 0; i < this->size; ++i)
            {
                std::cout << this->data[i];
            }
        }

        void save_to_file(std::ofstream& out) const
        {
            if(out.is_open())
            {
                out << this->size << ' ';
                for (std::size_t i = 0; i < this->size; ++i)
                {
                    out << this->data[i];
                }
                out << '\n';
            }
        }

        const bool operator==(const primitive_string& other) const 
        {
            if(this->size != other.size)
            {
                return false;
            }

            for (std::size_t i = 0; i < this->size; ++i)
            {
                if(this->data[i] != other.data[i])
                {
                    return false;
                }
            }
            
            return true;
        }

    private:

        char* data;
        std::size_t size;

        void copy(const primitive_string& other)
        {
            this->size = other.size;
            this->data = new char[this->size + 1];
            for (std::size_t i = 0; i < this->size; ++i)
            {
                this->data[i] = other.data[i];
            }
            this->data[this->size] = '\0';
        }

        void free()
        {
            delete[] this->data;
            this->data = nullptr;
            this->size = 0;
        }
};  



#endif