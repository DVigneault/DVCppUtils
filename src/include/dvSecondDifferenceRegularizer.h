
#ifndef dvSecondDifferenceRegularizer_h
#define dvSecondDifferenceRegularizer_h

#include <limits>
#include <ceres/ceres.h>

namespace dv
{
template<class TMovingMesh>
class SecondDifferenceRegularizer :
public ceres::CostFunction
{

  public:

  SecondDifferenceRegularizer(
    const typename std::vector<typename TMovingMesh::Pointer>
      &_movingVector,
    const typename std::vector<typename TMovingMesh::PointsContainer::Pointer>
      &_initialPointsVector,
    unsigned int _frame,
    unsigned int _index);

  bool Evaluate(const double* const* parameters,
                double* residuals,
                double** jacobians) const;

  ~SecondDifferenceRegularizer(){}

private:

  unsigned int GetNumberOfFrames() const;
  unsigned int GetPrevFrame() const;
  unsigned int GetCurrentFrame() const;
  unsigned int GetNextFrame() const;

  const typename std::vector<typename TMovingMesh::Pointer> movingVector;
  const typename std::vector<typename TMovingMesh::PointsContainer::Pointer> &initialPointsVector;

  const unsigned int frame;
  const unsigned int index;

}; // end class
} // end namespace

#include <dvSecondDifferenceRegularizer.hxx>

#endif

