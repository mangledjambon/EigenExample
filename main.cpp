#include <iostream>
#include "eigen-eigen-10219c95fe65/Eigen/Eigen"

using namespace Eigen;
using namespace std;

int main()
{
    /*
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

    cout << "m1" << std::endl << m1 << std::endl;
    cout << "m2" << std::endl << m2 << std::endl;

    MatrixXd m3 = MatrixXd::Random(3,3);
    m3 = m3 + MatrixXd::Constant(3,3,1.2) * 50;

    cout << "m3 = " << endl << m3 << endl;

    VectorXd v(3);

    v << 1, 2, 3; //put values into vector

    cout << "m3 * v = " << endl << m3 * v << endl;
    */


    //============= New Stuff =================//

    int numIters = 100;
    int np = 3;
    Vector3f pan_dir(0, (const float)M_PI/4.f, (const float)M_PI/2.f);

    /* // details
    cout    << "Pan:" << endl
            << pan_dir << endl
            << "SIN:" << endl << pan_dir.array().sin() << endl
            << "COS:" << endl << pan_dir.array().cos();

    */

    MatrixXf projmat = MatrixXf::Zero(3,2);
    MatrixXf panmat = MatrixXf::Zero(3,2);
    projmat << pan_dir.array().sin(), -(pan_dir.array().cos());
    panmat << pan_dir.array().cos(), pan_dir.array().sin();

    MatrixXf k = MatrixXf::Zero(3,3);
    k = panmat.transpose() * projmat;
    cout << k;

    return 0;

};