#include <gtest/gtest.h>
#include "IRoute.h"

TEST(RouteTests, Constructor)
{
  const std::wstring target{L"Москва"};
  const double cost{1234.5678};
  // Проверка возможности создания объекта "маршрут" с корректными параметрами.
  {
    std::shared_ptr<IRoute> p(makeRoute(target.c_str(), cost));

    ASSERT_EQ(target, p->getTarget());
    ASSERT_EQ(cost, p->getCost());
    ASSERT_EQ(cost, p->getFinalCost());
  }
  // Проверка невозможности создания объекта "маршрут" без указания названия маршрута.
  {
    ASSERT_THROW(makeRoute(nullptr, cost), std::invalid_argument);
  }
  // Проверка невозможности создания объекта "маршрут" с указанием пустого названия маршрута.
  {
    ASSERT_THROW(makeRoute(L"", cost), std::invalid_argument);
  }
  // Проверка невозможности создания объекта "маршрут" с нулевой ценой.
  {
    ASSERT_THROW(makeRoute(target.c_str(), 0.0), std::invalid_argument);
  }
  // Проверка невозможности создания объекта "маршрут" с отрицательной ценой.
  {
    ASSERT_THROW(makeRoute(target.c_str(), -8765.4321), std::invalid_argument);
  }
}

TEST(RouteTests, Target)
{
  double cost{1234.5678};
  // Проверка возможности указать название маршрута после создания объекта "маршрут".
  {
    std::wstring target{L"Москва"};
    std::shared_ptr<IRoute> p(makeRoute(target.c_str(), cost));
    target = L"Казань";

    ASSERT_NE(p->setTarget(target.c_str()), false);
    ASSERT_EQ(target, p->getTarget());
  }
  // Проверка невозможности не указать название маршрута после создания объекта "маршрут".
  {
    std::wstring target{L"Москва"};
    std::shared_ptr<IRoute> p(makeRoute(target.c_str(), cost));
    
    ASSERT_EQ(p->setTarget(nullptr), false);
    ASSERT_EQ(target, p->getTarget());
  } 
  // Проверка невозможности указать пустое название маршрута после создания объекта "маршрут".
  {
    std::wstring target{L"Москва"};
    std::shared_ptr<IRoute> p(makeRoute(target.c_str(), cost));
    
    ASSERT_EQ(p->setTarget(L""), false);
    ASSERT_EQ(target, p->getTarget());
  } 
}

TEST(RouteTests, Cost)
{
  const std::wstring target{L"Москва"};
  const double cost{1234.5678};
  // Проверка возможности указать стоимость маршрута после создания объекта "маршрут".
  {
    std::shared_ptr<IRoute> p(makeRoute(target.c_str(), cost));
    const double cost2 = 8765.4321;
    
    ASSERT_NE(p->setCost(cost2), false);
    ASSERT_EQ(cost2, p->getCost());
    ASSERT_EQ(cost2, p->getFinalCost());
  }
  // Проверка невозможности указать нулевую стоимость маршрута после создания объекта "маршрут".
  {
    std::shared_ptr<IRoute> p(makeRoute(target.c_str(), cost));
    
    ASSERT_EQ(p->setCost(0.0), false);
    ASSERT_EQ(cost, p->getCost());
    ASSERT_EQ(cost, p->getFinalCost());
  }
  // Проверка невозможности указать отрицательную стоимость маршрута после создания объекта "маршрут".
  {
    std::shared_ptr<IRoute> p(makeRoute(target.c_str(), cost));
    
    ASSERT_EQ(p->setCost(-1234.5678), false);
    ASSERT_EQ(cost, p->getCost());
    ASSERT_EQ(cost, p->getFinalCost());
  }
}
