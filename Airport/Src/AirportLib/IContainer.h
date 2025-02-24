/// \file IContainer.h
/// \brief Объявление абстрактного интерфейса "Контейнер".
/// \author Чернов Роман
#pragma once

#include "AirportLib.h"
#include "IIterator.h"
#include "IConstIterator.h"
#include <memory>

/// \interface IContainer
/// \brief Абстрактный интерфейс "Контейнер".
/// \tparam T Тип элемента контейнера.
template<typename T>
class AIRPORT_LIBRARY_API IContainer
{
public:
  /// \brief Тип элементов контейнера.
  typedef T ValueType;

public:
  /// \brief Деструктор по умолчанию.
  virtual ~IContainer() = default;

public:
  /// \brief Добавить элемент в конец контейнера.
  /// \param value Ссылка на добавляемый элемент в конец контейнер.
  /// \return Признак успешности добавления элемента в конец контейнера.
  virtual bool add(const T& value) = 0;
  /// \brief Удалить элемент в контейнере.
  /// \param value Ссылка на элемент, который нужно удалить.
  /// \return Признак успешности удаления элемента в контейнере.
  virtual bool remove(const T& value) = 0;
  /// \brief Вернуть количество элементов контейнера.
  /// \return Количество элементов контейнера.
  virtual std::size_t size() const = 0;
  /// \brief Возвращает умный указатель на реализацию интерфейса итератора контейнера, который указывает на первый элемент
  /// контейнера.
  /// \return Умный указатель на реализацию интерфейса итератора контейнера, который указывает на первый элемент контейнера.
  virtual std::unique_ptr<IIterator<T>> createIterator() const = 0;
  /// \brief Возвращает умный указатель на реализацию интерфейса константного итератора контейнера, который указывает на
  /// первый элемент контейнера.
  /// \return Умный указатель на реализацию интерфейса константного итератора контейнера, который указывает на первый элемент
  /// контейнера.
  virtual std::unique_ptr<IConstIterator<T>> createConstIterator() const = 0;
};
