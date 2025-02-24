/// \file IBidirectionalIterator.h
/// \brief Объявление абстрактного интерфейса "Двунаправленный итератор контейнера".
/// \author Чернов Роман
#pragma once

#include "AirportLib.h"

/// \interface IBidirectionalIterator
/// \brief Абстрактный интерфейс "Двунаправленный итератор контейнера".
/// \tparam T Тип элемента контейнера.
template<typename T>
class AIRPORT_LIBRARY_API IBidirectionalIterator
{
public:
  /// \brief Тип на который ссылается итератор.
  typedef T ValueType;

public:
  /// \brief Деструктор по умолчанию.
  virtual ~IBidirectionalIterator() = default;

public:
  /// \brief Проверить, есть ли следующий элемент.
  /// \return Признак того, что существует следующий элемент контейнера.
  virtual bool hasNext() const = 0;
  /// \brief Проверить, есть ли предыдущий элемент.
  /// \return Признак того, что существует предыдущий элемент контейнера.
  virtual bool hasPrev() const = 0;
  /// \brief Передвигает итератор на следующий элемент контейнера.
  /// \return Признак того, что операция перехода на следующий элемент контейнера выполнена.
  virtual bool next() = 0;
  /// \brief Передвигает итератор на предыдущий элемент контейнера.
  /// \return Признак того, что операция перехода на предыдущий элемент контейнера выполнена.
  virtual bool prev() = 0;
};
