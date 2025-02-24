#include "Private/Route.h"

Route::Route(const wchar_t* target, double cost)
{
  if (setTarget(target) == false)
    throw std::invalid_argument("Invalid target");
  if (setCost(cost) == false)
    throw std::invalid_argument("Invalid cost");
}

const wchar_t* Route::getTarget() const
{
  return Target.c_str();
}

bool Route::setTarget(const wchar_t* target)
{
  if (target != nullptr && wcslen(target) > 0)
  {
    Target = target;
    return true;
  }
  return false;
}

double Route::getCost() const
{
  return Cost;
}

bool Route::setCost(double cost)
{
  if (cost > 0.0)
  {
    Cost = cost;
    return true;
  }
  return false;
}

double Route::getFinalCost() const
{
  return getCost();
}

std::unique_ptr<IRoute> makeRoute(const wchar_t* target, double cost)
{
  return std::unique_ptr<IRoute>(new Route(target, cost));
}
