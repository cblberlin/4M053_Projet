#include "matrice.hpp"
#include <iostream>
#include <cassert>

Matrice::Matrice(int nr, int nc)
{
    Nb_col = nc;
    Nb_row = nr;
    coef_ = std::vector<double> ();
    coef_.reserve(Nb_col * Nb_row);
}

Matrice::Matrice(const Matrice & M)
{
    Nb_row = M.Nb_row;
    Nb_col = M.Nb_col;
    coef_ = M.coef_;
}

Matrice Matrice::operator= (const Matrice M)
{
    Matrice X(M.Nb_row, M.Nb_col);
    X.coef_ = M.coef_;
    return X;
}

int Matrice::rows() const
{
    return Nb_row;
}

int Matrice::cols() const
{
    return Nb_col;
}

double & Matrice::operator() (int i, int j)
{
    return coef_[i*Nb_col + j];
}

double Matrice::operator() (int i, int j) const
{
    return coef_[i*Nb_col + j];
}

void Matrice::Load(const std::string filename)
{
    std::ifstream f(filename);
    std::string taille;
    std::string donnees;
    f >> taille;
    f >> Nb_row >> Nb_col;
    f >> donnees;
    double temp;
    coef_.reserve(Nb_row * Nb_col);
    for(int k = 0; k < Nb_row * Nb_col; k++){
        f >> temp;
        coef_.push_back(temp);
    }
    f.close();
}

std::ostream & operator << (std::ostream & os, const Matrice &m)
{
    std::cout.precision(4);
    for(int i = 0; i < m.Nb_row; ++i){
        for(int j = 0;  j < m.Nb_col; ++j){
            os << m(i,j) << "\t";
        }
        os << std::endl;
    }
    return os;
}

std::vector<double> operator*(const Matrice &A, const std::vector<double> &v)
{
    assert(A.cols() == v.size());
    std::vector<double> B(A.rows());
    double temp = 0.;
    for(int i = 0; i < A.rows(); ++i){
        for(int j = 0; j < A.cols(); ++j){
            temp += A(i,j)*v[i];
        }
        B[i] = temp;
    }
    return B;
}

Matrice operator*(const Matrice &A, const Matrice &B)
{
    assert(A.cols() == B.rows());
    Matrice C(A.rows(), B.cols());
    
    for(int i = 0; i < A.rows(); i++){
        for(int j = 0; j < B.cols(); j++){
            C(i, j) = 0.;
            for(int k = 0; k < B.rows(); k++){
                C(i, j) += A(i, k) * B(k, j);
            }
        }
    }
    return C;
}

void Solve(const Matrice& A, std::vector<double> & x, const std::vector<double> & b)
{
    if(A.cols() != A.rows())
    {
        std::cout << " The matrix is not square!" << std::endl;
        return;
    }else{
        
    }
}