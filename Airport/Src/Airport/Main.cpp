#include <iostream>
#include <iomanip>
#include "Route.h"
#include "RouteWithDiscount.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  std::wcout.imbue(std::locale("ru_RU.UTF-8"));

  try
  {
    const int max_width_double = static_cast<int>(std::numeric_limits<double>::digits10);
    Route r1(makeRoute(L"Москва1", 1000.126));
    std::wcout << "target: " << r1->getTarget() << std::endl;
    std::wcout << "cost: " << std::left << std::setw(max_width_double) << std::defaultfloat << r1->getCost() << std::endl;
    std::wcout << "final cost: " << std::left << std::setw(max_width_double) << std::defaultfloat << r1->getFinalCost() << std::endl;

    Route r2(makeRouteWithDiscount(L"Москва2", 1000.126, 50.146));
    std::wcout << "target: " << r2->getTarget() << std::endl;
    std::wcout << "cost: " << std::left << std::setw(max_width_double) << std::defaultfloat << r2->getCost() << std::endl;
    std::wcout << "final cost: " << std::left << std::setw(max_width_double) << std::defaultfloat << r2->getFinalCost() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}