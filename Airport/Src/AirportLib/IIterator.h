/// \file IIterator.h
/// \brief Объявление абстрактного интерфейса "Итератор контейнера".
/// \author Чернов Роман
#pragma once

#include "IBidirectionalIterator.h"

/// \interface IIterator
/// \brief Абстрактный интерфейс "Итератор контейнера".
/// \tparam T Тип элемента контейнера.
template<typename T>
class AIRPORT_LIBRARY_API IIterator :
  public IBidirectionalIterator<T>
{
public:
  /// \brief Тип на который ссылается итератор.
  typedef typename IBidirectionalIterator<T>::ValueType ValueType;

public:
  /// \brief Деструктор по умолчанию.
  virtual ~IIterator() = default;

public:
  /// \brief Вернуть ссылку на элемент без продвижения итератора.
  /// \return Ссылка на элемента контейнера.
  virtual ValueType& peek() = 0;
};
