#ifndef MPC_SOLVER_H
#define MPC_SOLVER_H

#include <unistd.h>
#include <iostream>
#include <cmath>
#include <csignal>
#include <memory>
#include <Eigen/Dense>

#include "cpptoml/include/cpptoml.h"
#include "OsqpEigen/OsqpEigen.h"
#include <casadi/casadi.hpp>
using namespace Eigen;

class MPC_Solver{
    public:
    MPC_Solver(){};
    MPC_Solver(int Cons_Num, int Vars_Num);
    Eigen::VectorXd Update_Solver(casadi::DM Aeq, casadi::DM beq,casadi::DM Aiq, casadi::DM biq,casadi::DM H, casadi::DM f);

    private:
    int QP_initialized_;
    OsqpEigen::Solver solver_;
    int Vars_Num_;
    int Cons_Num_;
    Eigen::VectorXd gradient_; 
    Eigen::SparseMatrix<double> hessian_;
    Eigen::SparseMatrix<double> linearMatrix_;
    Eigen::VectorXd lowerBound_;
    Eigen::VectorXd upperBound_;
    std::vector<Eigen::Triplet<double>> hessian_coeff_;
    std::vector<Eigen::Triplet<double>> linearm_coeff_;

    Eigen::VectorXd sol_;
};

#endif //MPC_SOLVER_H

