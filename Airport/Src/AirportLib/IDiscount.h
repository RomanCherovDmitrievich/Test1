/// \file IDiscount.h
/// \brief Объявление абстрактного интерфейса "Скидка".
/// \author Чернов Роман
/// \copyright 
#pragma once

#include "IRoute.h"

/// \interface IDiscount
/// \brief Абстрактный интерфейс "Скидка".
class AIRPORT_LIBRARY_API IDiscount
{
public:
  /// \brief Деструктор по умолчанию.
  virtual ~IDiscount() = default;

public:
  /// \brief Вернуть скидку на маршрут.
  /// \return Скидка на маршрут.
  virtual double getDiscount() const = 0;
  /// \brief Установить скидку на маршрут.
  /// \param[in] discount Скидка на маршрут.
  /// \return Признак успешности выполнения установки скидки на маршрут.
  virtual bool setDiscount(double discount) = 0;
};

/// \brief Создать объект "Маршрут со скидкой". 
/// \param[in] target Название маршрута.
/// \param[in] cost Стоимость маршрута.
/// \param[in] discount Скидка на маршрут.
/// \return Умный указатель на объект реализующий интерфейс IRoute и IDiscount.
/// \throw std::invalid_argument Исключение создаётся в случае, если переданы неверные аргументы.
AIRPORT_LIBRARY_API std::unique_ptr<IRoute> makeRouteWithDiscount(
  const wchar_t* target,
  double cost,
  double discount) noexcept(false);
