/// \file IConstIterator.h
/// \brief Объявление абстрактного интерфейса "Константный итератор контейнера".
/// \author Чернов Роман
#pragma once

#include "IBidirectionalIterator.h"

/// \interface IConstIterator
/// \brief Абстрактный интерфейс "Константный итератор контейнера".
/// \tparam T Тип элемента контейнера.
template<typename T>
class AIRPORT_LIBRARY_API IConstIterator :
  public IBidirectionalIterator<T>
{
public:
  /// \brief Тип на который ссылается итератор.
  typedef typename IBidirectionalIterator<T>::ValueType ValueType;

public:
  /// \brief Деструктор по умолчанию.
  virtual ~IConstIterator() = default;

public:
  /// \brief Вернуть константную ссылку на элемент без продвижения итератора.
  /// \return Константная ссылка на элемента контейнера.
  virtual const ValueType& peek() const = 0;
};
