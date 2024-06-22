#include "program.h"

void generate_example()
{
    primitive_vector<primitive_string> vector;
    vector.push_back(primitive_string("finite_set.bin", 14));
    vector.push_back(primitive_string("intersection.bin", 17));

    std::ofstream f_out("finite_set.bin", std::ios::binary);
    if(f_out.is_open())
    {
        std::uint16_t N = 2;
        std::uint16_t T = 8;

        f_out << N;
        f_out << ' ';
        f_out << T;
        f_out << '\n';

        for (size_t i = 0; i < N; i++)
        {
            for (std::size_t i = 0; i < 16; ++i)
            {
                f_out << std::rand() % 10;
            }
            f_out << '\n';
        }
        
    }
    f_out.close();

    std::ofstream i_out("intersection.bin", std::ios::binary);
    if(i_out.is_open())
    {
        std::uint16_t N = 1;
        std::uint16_t T = 0;

        i_out << N;
        i_out << ' ';
        i_out << T;
        i_out << '\n';

        for (size_t i = 0; i < N; i++)
        {
            for (std::size_t i = 0; i < 16; ++i)
            {
                i_out << std::rand() % 10;
            }
            i_out << '\n';
        }
        
    }
    i_out.close();

    std::ofstream out("sets_names.bin", std::ios::binary);

    if(out.is_open())
    {
        out << vector.get_size() << '\n';
        for (std::size_t i = 0; i < vector.get_size(); ++i)
        {
            vector.get_data()[i].save_to_file(out);
        }      
        out.close();
    }
}

int main()
{
    generate_example();
    primitive_string sets_names("sets_names.bin", 15);
    program<int> p(sets_names);
}
