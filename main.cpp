#include <iostream>
#include "eigen-eigen-10219c95fe65/Eigen/Eigen"

using namespace Eigen;
using namespace std;

int main()
{
    // initialisation stuff
    int numIters = 100;
    int np = 3;
    Vector3f pan_dir(0, (const float)M_PI/4, (const float)M_PI/2);

    cout << "pan_dir = \n" << pan_dir << endl;

    MatrixXf projmat(3,2);
    MatrixXf panmat(3,2);
    projmat << pan_dir.array().sin(), -(pan_dir.array().cos());
    panmat << pan_dir.array().cos(), pan_dir.array().sin();

    cout << "projmat =\n" << projmat << endl;
    cout << "panmat =\n" << panmat << endl;

    MatrixXf k1(3,3);
    MatrixXf kAbs(3,3);
    k1 = panmat * projmat.transpose();
    kAbs << k1.cwiseAbs();

    // compute pseudo-inverse
    MatrixXf pimat(3,2);
    Matrix3f ident = Matrix3f::Identity(3,3);
    pimat = projmat.fullPivHouseholderQr().solve(ident);
    cout << "pimat = \n" << pimat << endl;
    /*
     * void pinv( MatrixType& pinvmat) const
   {
     eigen_assert(m_isInitialized && "SVD is not initialized.");
     double  pinvtoler=1.e-6; // choose your tolerance wisely!
     SingularValuesType singularValues_inv=m_singularValues;
     for ( long i=0; i<m_workMatrix.cols(); ++i) {
        if ( m_singularValues(i) > pinvtoler )
           singularValues_inv(i)=1.0/m_singularValues(i);
       else singularValues_inv(i)=0;
     }
     pinvmat= (m_matrixV*singularValues_inv.asDiagonal()*m_matrixU.transpose());
   }
    * */
    return 0;

};