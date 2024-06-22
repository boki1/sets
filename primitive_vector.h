#ifndef PRIMITIVE_VECTOR
#define PRIMITIVE_VECTOR

#include <iostream>

template <typename T>
class primitive_vector
{
    public:
        primitive_vector()
        {
            this->size = 0;
            this->capacity = 8;
            this->data = new T[this->capacity];
        }

        primitive_vector(const T* data, const std::size_t size, const std::size_t capacity)
        {
            this->size = size;
            this->capacity = capacity;
            this->data = new T[this->capacity];
            for (std::size_t i = 0; i < this->size; ++i)
            {
                this->data[i] = data[i];
            }
        }

        primitive_vector(const primitive_vector<T>& other)
        {
            copy(other);
        }

        primitive_vector<T>& operator=(const primitive_vector<T>& other)
        {
            if(this != &other)
            {
                free();
                copy(other);
            }
            return *this;
        }

        ~primitive_vector()
        {
            free();
        }

        const T* get_data() const
        {
            return this->data;
        }

        const std::size_t get_size() const
        {
            return this->size;
        }

        const std::size_t get_capacity() const
        {
            return this->capacity;
        }

        void set_data(const T* data)
        {
            this->data = new T[this->capacity];
            for (std::size_t i = 0; i < this->size; ++i)
            {
                this->data[i] = data[i];
            }
        }

        void set_size(const std::size_t size)
        {
            this->size = size;
        }

        void set_capacity(const std::size_t capacity)
        {
            this->capacity = capacity;
        }

        void push_back(const T& element)
        {
            if(this->size >= this->capacity)
            {
                resize();
            }
            this->data[this->size++] = element;
        }

        void pop(const std::size_t index)
        {
            if(index < 0 || index >= this->size)
            {
                //std::cout << "[-] cannot pop element at idx " << index << '\n';
                return;
            }
            
            for (std::size_t i = index; i < this->size - 1; ++i)
            {
                this->data[i] = this->data[i + 1];
            }
            --this->size;
        }

        void print() const
        {
            for (std::size_t i = 0; i < this->size; ++i)
            {
                std::cout << this->data[i] << ' ';
            }
        }

        T operator[](const std::size_t index) const
        {
            if(index < 0 || index >= this->size)
            {
                //std::cout << "[-] cannot indexise element at idx " << index << '\n';
                T sentinel = T();
                return sentinel;
            }

            return this->data[index];
        }

        void bubble_sort()
        {
            for (std::size_t i = 0; i < this->size; ++i)
            {
                for (std::size_t j = 0; j < this->size; ++j)
                {
                    if(this->data[i] < this->data[j])
                    {
                        std::swap(this->data[i], this->data[j]);
                    }
                }
            }
        }

        const bool operator==(const primitive_vector<T>& other) const 
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
        T* data;
        std::size_t size;
        std::size_t capacity;

        void copy(const primitive_vector<T>& other)
        {
            this->size = other.size;
            this->capacity = other.capacity;
            this->data = new T[this->capacity];
            for (std::size_t i = 0; i < this->size; ++i)
            {
                this->data[i] = other.data[i];
            }
        }

        void free()
        {
            delete[] this->data;
            this->data = nullptr;
            this->size = 0;
            this->capacity = 0;
        }

        void resize()
        {
            this->capacity *= 2;
            T* buffer = new T[this->capacity];
            for (std::size_t i = 0; i < this->size; ++i)
            {
                buffer[i] = this->data[i];
            }
            delete[] this->data;
            this->data = buffer;
        }
};



#endif