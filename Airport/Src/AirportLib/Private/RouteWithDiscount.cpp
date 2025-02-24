#include "Private/RouteWithDiscount.h"

RouteWithDiscount::RouteWithDiscount(const wchar_t * target, double cost, double discount) :
  Route(target, cost)
{
  if (setDiscount(discount) == false)
    throw std::invalid_argument("Invalid discount");
}

bool RouteWithDiscount::setCost(double cost)
{
  if (cost <= getDiscount())
    return false;
  return Route::setCost(cost);
}

double RouteWithDiscount::getDiscount() const
{
  return Discount;
}

bool RouteWithDiscount::setDiscount(double discount)
{
  if (discount > 0.0 && discount < getCost())
  {
    Discount = discount;
    return true;
  }
  return false;
}

double RouteWithDiscount::getFinalCost() const
{
  return Route::getFinalCost() - getDiscount();
}

std::unique_ptr<IRoute> makeRouteWithDiscount(const wchar_t* target, double cost, double discount)
{
  std::unique_ptr<IRoute> result(new RouteWithDiscount(target, cost, discount));
  return result;
}
