/**
 * @file averge_init.hpp
 * @author Sumedh Ghaisas
 *
 * Intialization rule for Alternating Matrix Factorization.
 *
 * This file is part of mlpack 1.0.12.
 *
 * mlpack is free software; you may redstribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef __MLPACK_METHODS_AMF_AVERAGE_INIT_HPP
#define __MLPACK_METHODS_AMF_AVERAGE_INIT_HPP

#include <mlpack/core.hpp>

namespace mlpack {
namespace amf {

/**
 * This initialization rule initializes matrix W and H to root of average of V
 * with uniform noise. Uniform noise is generated by Armadillo's 'randu' function.
 * To have a better effect lower bound of the matrix is subtracted from average
 * before dividing it by the factorization rank. This computed value is added
 * with the random noise.
 */
class AverageInitialization
{
 public:
  // Empty constructor required for the InitializeRule template
  AverageInitialization() { }

  template<typename MatType>
  inline static void Initialize(const MatType& V,
                                const size_t r,
                                arma::mat& W,
                                arma::mat& H)
  {
    size_t n = V.n_rows;
    size_t m = V.n_cols;

    double V_avg = 0;
    size_t count = 0;
    double min = DBL_MAX;
    for(typename MatType::const_row_col_iterator it = V.begin();it != V.end();it++)
    {
      if(*it != 0)
      {
        count++;
        V_avg += *it;
        if(*it < min) min = *it;
      }
    }
    V_avg = sqrt(((V_avg / (n * m)) - min) / r);

    // Intialize to random values.
    W.randu(n, r);
    H.randu(r, m);

    W = W + V_avg;
    H = H + V_avg;
  }
};

}; // namespace amf
}; // namespace mlpack

#endif
