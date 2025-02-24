/// \file Route.h
/// \brief Объявление класса реализации интерфейс IRoute.
/// \author Чернов Роман
#pragma once

#include "IRoute.h"
#include <string>

/// \brief Реализация класс "Маршрут" с интерфейсом IRoute.
class AIRPORT_LIBRARY_LOCAL Route :
  public IRoute
{
public:
  /// \brief Конструктор инициализации.
  /// \param[in] target Название маршрута. 
  /// \param[in] cost Цена маршрута.
  /// \throw std::invalid_argument Исключение создаётся в случае, если переданы неверные аргументы.
  Route(const wchar_t * target, double cost);
  /// \brief Деструктор по умолчанию. 
  virtual ~Route() = default;

public:
  /// \copydoc IRoute::getTarget
  const wchar_t* getTarget() const override;
  /// \brief Установить название маршрута.
  /// \param target Указатель на название маршрута.
  /// \return Возвращает true если переданная строка не nullptr и длина строки больше 0 иначе false.
  bool setTarget(const wchar_t* target) override;
  /// \copydoc IRoute::getCost
  double getCost() const override;
  /// \brief Установить стоимость маршрута.
  /// \param cost Стоимость маршрута.
  /// \return Возвращает true если переданное значение больше 0 иначе false.
  bool setCost(double cost) override;
  /// \brief Вернуть финальную стоимость маршрута.
  /// \return Возвращает стоимость маршрута.
  double getFinalCost() const override;

private:
  /// \brief Конструктор по умолчанию.
  Route() = delete;
  /// \brief Конструктор копирования.
  /// \param[in] right Копируемый объект.
  Route(const Route& right) = delete;
  /// \brief Конструктор перемещения.
  /// \param[in] right Перемещаемый объект.
  Route(Route&& right) = delete;
  /// \brief Оператор копирования.
  /// \param[in] right Копируемый объект.
  /// \return Ссылка на изменённый объект.
  Route& operator=(const Route& right) = delete;
  /// \brief Оператор перемещения.
  /// \param[in] right Перемещаемый объект.
  /// \return Ссылка на изменённый объект.
  Route& operator=(Route&& right) = delete;

private:
  /// \brief Название маршрута. 
  std::wstring Target;
  /// \brief Цена маршрута.
  double Cost;
};
