#include <gtest/gtest.h>
#include "IAirport.h"
#include "IDiscount.h"

TEST(AirpotTests, DefaultConstructor)
{
  // После создания аэропорта в нём нет маршрутов и поиск максимального вернёт пустой умный указатель.
  std::shared_ptr<IAirport> a(makeAirport());

  ASSERT_EQ(a->size(), 0);
  RouteSharedPtr r(a->findMaxCost());
  ASSERT_EQ(r.get(), nullptr);
}

TEST(AirpotTests, FindMaxCost)
{
  // После создания аэропорта в нём нет маршрутов и поиск максимального вернёт пустой умный указатель.
  std::shared_ptr<IAirport> a(makeAirport());

  a->add(makeRoute(L"Test1", 10));
  RouteSharedPtr r = a->findMaxCost();
  ASSERT_EQ(r->getFinalCost(), 10);
  a->add(makeRouteWithDiscount(L"Test2", 20, 11));
  r = a->findMaxCost();
  ASSERT_EQ(r->getFinalCost(), 10);
  a->add(makeRouteWithDiscount(L"Test3", 30, 11));
  r = a->findMaxCost();
  ASSERT_EQ(r->getFinalCost(), 19);
}
