/// \file RouteWithDiscount.h
/// \brief Объявление класса реализации совместно интерфейсы IRoute и IDiscount.
/// \author Чернов Роман
#pragma once

#include "Private/Route.h"
#include "IDiscount.h"

/// \brief Реализация класс "Маршрут со скидкой" с интерфейсами IRoute и IDiscount.
class AIRPORT_LIBRARY_LOCAL RouteWithDiscount:
  public Route,
  public IDiscount
{
public:
  /// \brief Конструктор инициализации.
  /// \param[in] target Название маршрута. 
  /// \param[in] cost Цена маршрута.
  /// \param[in] discount Скидка на маршрут.
  /// \throw std::invalid_argument Исключение создаётся в случае, если переданы неверные аргументы.
  RouteWithDiscount(const wchar_t* target, double cost, double discount);
  /// \brief Деструктор по умолчанию. 
  virtual ~RouteWithDiscount() = default;

public:
  /// \brief Установить стоимость маршрута.
  /// \param[in] cost Стоимость маршрута.
  /// \return Возвращает true, если стоимость больше скидки иначе false.
  bool setCost(double cost) override;
  /// \brief Возвращает стоимость маршрута с учётом скидки.
  /// \return Возвращает разницу стоимости маршрута и скидки.
  double getFinalCost() const override;

public:
  /// \copydoc IDiscount::getDiscount
  double getDiscount() const override;
  /// \brief Установить скидку на маршрут.
  /// \param[in] discount Скидка на маршрут.
  /// \return Возвращает true если значение скидки меньше стоимости и больше 0 иначе false.
  bool setDiscount(double discount) override;

private:
  /// \brief Конструктор по умолчанию.
  RouteWithDiscount() = delete;
  /// \brief Конструктор копирования.
  /// \param[in] right Копируемый объект.
  RouteWithDiscount(const RouteWithDiscount& right) = delete;
  /// \brief Конструктор перемещения.
  /// \param[in] right Перемещаемый объект.
  RouteWithDiscount(RouteWithDiscount&& right) = delete;
  /// \brief Оператор копирования.
  /// \param[in] right Копируемый объект.
  /// \return Ссылка на изменённый объект.
  RouteWithDiscount& operator=(const RouteWithDiscount& right) = delete;
  /// \brief Оператор перемещения.
  /// \param[in] right Перемещаемый объект.
  /// \return Ссылка на изменённый объект.
  RouteWithDiscount& operator=(RouteWithDiscount&& right) = delete;

private:
  /// \brief Скидка на маршрут. 
  double Discount;
};
