/**
 * @file complete_incremental_termination_hpp
 * @author Sumedh Ghaisas
 *
 * Complete incremental learning termination policy.
 *
 * This file is part of mlpack 1.0.12.
 *
 * mlpack is free software; you may redstribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef COMPLETE_INCREMENTAL_TERMINATION_HPP_INCLUDED
#define COMPLETE_INCREMENTAL_TERMINATION_HPP_INCLUDED

namespace mlpack
{
namespace amf
{

template <class TerminationPolicy>
class CompleteIncrementalTermination
{
 public:
  /**
   * Empty constructor
   *
   * @param t_policy object of wrapped class.
   */
  CompleteIncrementalTermination(TerminationPolicy t_policy = TerminationPolicy())
            : t_policy(t_policy) {}

  template <class MatType>
  void Initialize(const MatType& V)
  {
    t_policy.Initialize(V);

    incrementalIndex = accu(V != 0);
    iteration = 0;
  }

  void Initialize(const arma::sp_mat& V)
  {
    t_policy.Initialize(V);

    incrementalIndex = V.n_nonzero;
    iteration = 0;
  }

  bool IsConverged(arma::mat& W, arma::mat& H)
  {
    iteration++;
    if(iteration % incrementalIndex == 0)
      return t_policy.IsConverged(W, H);
    else return false;
  }

  const double& Index()
  {
    return t_policy.Index();
  }
  const size_t& Iteration()
  {
    return iteration;
  }

  const size_t& MaxIterations()
  {
    return t_policy.MaxIterations();
  }

 private:
  TerminationPolicy t_policy;

  size_t incrementalIndex;
  size_t iteration;
};

} // namespace amf
} // namespace mlpack


#endif // COMPLETE_INCREMENTAL_TERMINATION_HPP_INCLUDED

