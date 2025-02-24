/// \file Airport.h
/// \brief Объявление класса реализации интерфейс IAirport.
/// \author Чернов Роман
#pragma once

#include "IAirport.h"
#include "IRoute.h"
#include "List.h"

/// \brief Реализация класс "Аэропорт" с интерфейсом IAirport.
class AIRPORT_LIBRARY_LOCAL Airport
  : public IAirport
{
public:
  /// \brief Конструктор по умолчанию.
  Airport() = default;
  /// \brief Деструктор по умолчанию.
  virtual ~Airport() = default;

public:
  /// \copydoc IAirport::findMaxCost
  RouteSharedPtr findMaxCost() const override;
};