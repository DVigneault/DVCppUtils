
#ifndef dvPointCorrespondenceRegularizer_h
#define dvPointCorrespondenceRegularizer_h

#include <limits>
#include <ceres/ceres.h>

namespace dv
{
template<class TMovingMesh>
class PointCorrespondenceRegularizer :
public ceres::CostFunction
{

  public:

  PointCorrespondenceRegularizer(
    const typename std::vector<typename TMovingMesh::Pointer>
      &_movingVector,
    const typename std::vector<typename TMovingMesh::PointsContainer::Pointer>
      &_initialPointsVector,
    unsigned int _frame,
    unsigned int _index);

  bool Evaluate(const double* const* parameters,
                double* residuals,
                double** jacobians) const;

  ~PointCorrespondenceRegularizer(){}

private:

  unsigned int GetNumberOfFrames() const;
  unsigned int GetCurrentFrame() const;
  unsigned int GetNextFrame() const;

  const typename std::vector<typename TMovingMesh::Pointer> movingVector;
  const typename std::vector<typename TMovingMesh::PointsContainer::Pointer> &initialPointsVector;

  const unsigned int frame;
  const unsigned int index;

}; // end class
} // end namespace

#include <dvPointCorrespondenceRegularizer.hxx>

#endif

