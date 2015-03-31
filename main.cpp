#include <iostream>
#include "eigen-eigen-10219c95fe65/Eigen/Eigen"

using namespace Eigen;
using namespace std;

int main()
{
    MatrixXd m1(2,2);
    MatrixXd m2(2,2);

    m1(0,0) = 3;
    m1(1,0) = 2.5;
    m1(0,1) = -1;
    m1(1,1) = m1(1,0) + m1(0,1);

    m2(0,0) = 5;
    m2(1,0) = 1;
    m2(0,1) = 3;
    m2(1,1) = m1(1,0) + m2(0,1);


    std::cout << "m1" << std::endl << m1 << std::endl;
    std::cout << "m2" << std::endl << m2 << std::endl;

    MatrixXd m3 = MatrixXd::Random(3,3);

    m3 = m3 + MatrixXd::Constant(3,3,1.2) * 50;

    cout << "m3 = " << endl << m3 << endl;

    VectorXd v(3);

    v << 1, 2, 3; //put values into vector

    cout << "m * v = " << endl << m3 * v << endl;

    return 0;

}