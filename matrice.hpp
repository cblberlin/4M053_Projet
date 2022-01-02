#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <iostream>
#include <fstream>

class Matrice{
private:
    int Nb_col;
    int Nb_row;
    std::vector<double> coef_;

public:
    Matrice (int nr = 0, int nc = 0);
    Matrice (const Matrice & M);
    ~Matrice () = default;

    int rows() const;
    int cols() const;
    double & operator() (int i, int j);      // Accès à la référence
    double operator() (int i, int j) const; // Accès à la valeur (recopie)
    Matrice operator= (const Matrice M);
    void Load(const std::string filename);
    friend std::ostream & operator << (std::ostream & os, const Matrice &m);
    friend void Solve(const Matrice& A, std::vector<double> & x, const std::vector<double> & b);
};

std::vector<double> operator*(const Matrice &A, const std::vector<double> &v);

Matrice operator*(const Matrice &A, const Matrice &B);
