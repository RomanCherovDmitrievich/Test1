/// \file IRoute.h
/// \brief Объявление абстрактного интерфейса "Маршрут".
/// \author Чернов Роман
#pragma once

#include "AirportLib.h"
#include <memory>

/// \interface IRoute
/// \brief Абстрактный интерфейс "Маршрут".
class AIRPORT_LIBRARY_API IRoute
{
public:
  /// \brief Деструктор по умолчанию.
  virtual ~IRoute() = default;

public:
  /// \brief Вернуть название маршрута.
  /// \return Название маршрута.
  virtual const wchar_t* getTarget() const = 0;
  /// \brief Установить название маршрута.
  /// \param target Указатель на название маршрута.
  /// \return Признак успешности выполнения установки названия маршрута.
  virtual bool setTarget(const wchar_t* target) = 0;
  /// \brief Вернуть стоимость маршрута.
  /// \return Стоимость маршрута.
  virtual double getCost() const = 0;
  /// \brief Установить стоимость маршрута.
  /// \param cost Стоимость маршрута.
  /// \return Признак успешности выполнения установки стоимости маршрута.
  virtual bool setCost(double cost) = 0;
  /// \brief Вернуть финальную стоимость маршрута (стоимость с учётом скидок и т.п.).
  /// \return Финальная стоимость маршрута.
  virtual double getFinalCost() const = 0;
};

/// \brief Создать объект "Маршрут". 
/// \param target Название маршрута.
/// \param cost Стоимость маршрута.
/// \return Умный указатель на объект реализующий интерфейс IRoute.
AIRPORT_LIBRARY_API std::unique_ptr<IRoute> makeRoute(const wchar_t* target, double cost) noexcept(false);
