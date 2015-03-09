/**
 * @file linear_regression.hpp
 * @author James Cline
 * @author Michael Fox
 *
 * Simple least-squares linear regression.
 *
 * This file is part of mlpack 1.0.12.
 *
 * mlpack is free software; you may redstribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef __MLPACK_METHODS_LINEAR_REGRESSION_LINEAR_REGRESSION_HPP
#define __MLPACK_METHODS_LINEAR_REGRESSION_LINEAR_REGRESSION_HPP

#include <mlpack/core.hpp>

namespace mlpack {
namespace regression /** Regression methods. */ {

/**
 * A simple linear regression algorithm using ordinary least squares.
 * Optionally, this class can perform ridge regression, if the lambda parameter
 * is set to a number greater than zero.
 */
class LinearRegression
{
 public:
  /**
   * Creates the model.
   *
   * @param predictors X, matrix of data points to create B with.
   * @param responses y, the measured data for each point in X
   * @param intercept include intercept?
   * @param weights observation weights
   */
  LinearRegression(const arma::mat& predictors,
                   const arma::vec& responses,
                   const double lambda = 0,
                   const bool intercept = true,
                   const arma::vec& weights = arma::vec()
                   );

  /**
   * Initialize the model from a file.
   *
   * @param filename the name of the file to load the model from.
   */
  LinearRegression(const std::string& filename);

  /**
   * Copy constructor.
   *
   * @param linearRegression the other instance to copy parameters from.
   */
  LinearRegression(const LinearRegression& linearRegression);

  /**
   * Empty constructor.
   */
  LinearRegression() { }

  /**
   * Calculate y_i for each data point in points.
   *
   * @param points the data points to calculate with.
   * @param predictions y, will contain calculated values on completion.
   */
  void Predict(const arma::mat& points, arma::vec& predictions) const;

  /**
   * Calculate the L2 squared error on the given predictors and responses using
   * this linear regression model.  This calculation returns
   *
   * \f[
   * (1 / n) * \| y - X B \|^2_2
   * \f]
   *
   * where \f$ y \f$ is the responses vector, \f$ X \f$ is the matrix of
   * predictors, and \f$ B \f$ is the parameters of the trained linear
   * regression model.
   *
   * As this number decreases to 0, the linear regression fit is better.
   *
   * @param predictors Matrix of predictors (X).
   * @param responses Vector of responses (y).
   */
  double ComputeError(const arma::mat& points,
                      const arma::vec& responses) const;

  //! Return the parameters (the b vector).
  const arma::vec& Parameters() const { return parameters; }
  //! Modify the parameters (the b vector).
  arma::vec& Parameters() { return parameters; }

  //! Return the Tikhonov regularization parameter for ridge regression.
  double Lambda() const { return lambda; }
  //! Modify the Tikhonov regularization parameter for ridge regression.
  double& Lambda() { return lambda; }

  // Returns a string representation of this object. 
  std::string ToString() const;

 private:
  /**
   * The calculated B.
   * Initialized and filled by constructor to hold the least squares solution.
   */
  arma::vec parameters;
  /**
   * The Tikhonov regularization parameter for ridge regression (0 for linear
   * regression).
   */
  double lambda;
  //! Indicates whether first parameter is intercept.
  bool intercept;
};

}; // namespace linear_regression
}; // namespace mlpack

#endif // __MLPACK_METHODS_LINEAR_REGRESSCLIN_HPP
