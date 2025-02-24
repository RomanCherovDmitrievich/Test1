/// \file IAirport.h
/// \brief Объявление абстрактного интерфейса "Аэропорт".
/// \author Чернов Роман
#pragma once

#include "AirportLib.h"
#include "List.h"
#include "IRoute.h"

/// \typedef std::shared_ptr<IRoute> RouteSharedPtr 
/// \brief Умный указатель на абстрактный маршрут. 
typedef std::shared_ptr<IRoute> RouteSharedPtr;

/// \interface IAirport
/// \brief Абстрактный интерфейс "Аэропорт".
class AIRPORT_LIBRARY_API IAirport
  : public List<RouteSharedPtr>
{
public:
  /// \brief Деструктор по умолчанию.
  virtual ~IAirport() = default;

public:
  /// \brief Найти маршрут с самой большой стоимостью. 
  /// \return Умный указатель на объект описывающий самый дорогой маршрут.
  virtual RouteSharedPtr findMaxCost() const = 0;
};

/// \brief Создать объект "Аэропорт". 
/// \return Умный указатель на объект реализующий интерфейс IAirport.
AIRPORT_LIBRARY_API std::unique_ptr<IAirport> makeAirport() noexcept(false);
