#include <gtest/gtest.h>
#include "IRoute.h"
#include "IDiscount.h"

TEST(RouteWithDiscountTests, Constructor)
{
  const std::wstring target{L"Москва"};
  const double cost{1234.5678};
  const double discount{100.0};
  // Проверка возможности создания объекта "маршрут со скидкой" с корректными параметрами.
  {
    std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, discount));
    IDiscount* pd = dynamic_cast<IDiscount*>(p.get());

    ASSERT_NE(pd, nullptr);
    ASSERT_EQ(target, p->getTarget());
    ASSERT_EQ(cost, p->getCost());
    ASSERT_EQ(cost - discount, p->getFinalCost());

    ASSERT_NE(pd, nullptr);
    ASSERT_EQ(discount, pd->getDiscount());
  }
  // Проверка невозможности создания объекта "маршрут со скидкой" без указания названия маршрута.
  {
    ASSERT_THROW(makeRouteWithDiscount(nullptr, cost, discount), std::invalid_argument);
  }
  // Проверка невозможности создания объекта "маршрут со скидкой" с указанием названия маршрута нулевой длины.
  {
    ASSERT_THROW(makeRouteWithDiscount(L"", cost, discount), std::invalid_argument);
  }
  // Проверка невозможности создания объекта "маршрут со скидкой" с нулевой стоимостью.
  {
    ASSERT_THROW(std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), 0.0, discount)), std::invalid_argument);
  }
  // Проверка невозможности создания объекта "маршрут со скидкой" с отрицательной стоимостью.
  {
    ASSERT_THROW(makeRouteWithDiscount(target.c_str(), -8765.4321, discount), std::invalid_argument);
  }
  // Проверка невозможности создания объекта "маршрут со скидкой" с нулевой скидкой.
  {
    ASSERT_THROW(std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, 0.0)), std::invalid_argument);
  }
  // Проверка невозможности создания объекта "маршрут со скидкой" с отрицательной скидкой.
  {
    ASSERT_THROW(std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, -100.0)), std::invalid_argument);
  }
}

TEST(RouteWithDiscountTests, Discount)
{
  const std::wstring target{L"Москва"};
  const double cost{1000.0};
  const double discount1{100.0};
  const double discount2{200.0};
  // Проверка возможности указать корректной скидки после создания объекта "маршрут со скидкой".
  {
    std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, discount1));
    IDiscount* pd = dynamic_cast<IDiscount*>(p.get());

    ASSERT_NE(pd, nullptr);
    ASSERT_NE(pd->setDiscount(discount2), false);
    ASSERT_EQ(discount2, pd->getDiscount());
    ASSERT_EQ(cost - discount2, p->getFinalCost());
  }
  // Проверка невозможности указать скидку равной стоимости маршрута, после создания объекта "маршрут со скидкой".
  {
    std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, discount1));
    IDiscount* pd = dynamic_cast<IDiscount*>(p.get());

    ASSERT_NE(pd, nullptr);
    ASSERT_EQ(pd->setDiscount(cost), false);
    ASSERT_EQ(cost - discount1, p->getFinalCost());
  }
  // Проверка невозможности указать нулевой скидки, после создания объекта "маршрут со скидкой".
  {
    std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, discount1));
    IDiscount* pd = dynamic_cast<IDiscount*>(p.get());

    ASSERT_NE(pd, nullptr);
    ASSERT_EQ(pd->setDiscount(0.0), false);
    ASSERT_EQ(cost - discount1, p->getFinalCost());
  }
  // Проверка невозможности указать отрицательную скидку, после создания объекта "маршрут со скидкой".
  {
    std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, discount1));
    IDiscount* pd = dynamic_cast<IDiscount*>(p.get());

    ASSERT_NE(pd, nullptr);
    ASSERT_EQ(pd->setDiscount(-100.0), false);
    ASSERT_EQ(cost - discount1, p->getFinalCost());
  }
}

TEST(RouteWithDiscountTests, Cost)
{
  const std::wstring target{L"Москва"};
  const double cost{1000.0};
  const double discount{100.0};
  // Проверка возможности указать корректную стоимость после создания объекта "маршрут со скидкой".
  {
    std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, discount));

    ASSERT_NE(p->setCost(discount + 1.0), false);
    ASSERT_EQ(discount + 1.0, p->getCost());
    ASSERT_EQ(1.0, p->getFinalCost());
  }
  // Проверка невозможности указать некорректную стоимость после создания объекта "маршрут со скидкой".
  {
    std::shared_ptr<IRoute> p(makeRouteWithDiscount(target.c_str(), cost, discount));

    ASSERT_EQ(p->setCost(discount), false);
    ASSERT_EQ(cost, p->getCost());
    ASSERT_EQ(cost - discount, p->getFinalCost());
  }
}
