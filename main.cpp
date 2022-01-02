#include "matrice.hpp"

int main(int argc, char** argv)
{
    if(argc >= 2)
    {
        std::string filename = argv[1];
        Matrice M(3,2);
        M.Load(filename);
        std::cout << M;
        
        std::string filename2 = argv[2];
        Matrice N(2,2);
        N.Load(filename2);
        std::cout << N;
        std::cout << "checked" << std::endl;
        Matrice res = M * N;
        std::cout << res;
    }
}