#include "Airport.h"

RouteSharedPtr Airport::findMaxCost() const
{
  std::unique_ptr<IConstIterator<RouteSharedPtr>> it(createConstIterator());
  RouteSharedPtr result(0);
  double max(0);
  while(it->hasNext() != false)
  {
    if (max < it->peek()->getFinalCost())
    {
      max = it->peek()->getFinalCost();
      result = it->peek();
    }
    it->next();
  }
  return result;
}

AIRPORT_LIBRARY_API std::unique_ptr<IAirport> makeAirport() noexcept(false)
{
  std::unique_ptr<IAirport> result(new Airport());
  return result;
}
