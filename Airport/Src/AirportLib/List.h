/// \file List.h
/// \brief Реализация абстрактного интерфейса IContainer на базе стандартного списка.
/// \author Чернов Роман
#pragma once

#include "IContainer.h"
#include <list>

/// \brief Реализация абстрактного интерфейса IContainer на базе стандартного списка.
/// \tparam Тип элемента контейнера.
template<typename T>
class AIRPORT_LIBRARY_API List
  : public IContainer<T>
{
public:
  /// \brief Тип элементов контейнера.
  typedef typename IContainer<T>::ValueType ValueType;

public:
  /// \brief Конструктор по умолчанию.
  List()
    : Container(new std::list<ValueType>())
  {}
  /// \brief Деструктор по умолчанию.
  virtual ~List() = default;

public:
  /// \copydoc IContainer::add
  bool add(const ValueType& value) override
  {
    try
    {
      Container->push_back(value);
    }
    catch(...)
    {
      return false;
    }
    return true;
  }
  /// \copydoc IContainer::add
  bool remove(const ValueType& value) override
  {
    typename std::list<ValueType>::const_iterator it = std::find(Container->begin(), Container->end(), value);
    if (it != Container->end())
    {
      Container->erase(it);
      return true;
    }
    return false;
  }
  /// \copydoc IContainer::size
  std::size_t size() const override
  {
    return Container->size();
  }
  /// \copydoc IContainer::begin
  std::unique_ptr<IIterator<ValueType>> createIterator() const override
  {
    std::unique_ptr<IIterator<ValueType>> result(new ListIterator(Container, Container->begin()));
    return result;
  }
  /// \copydoc IContainer::begin
  std::unique_ptr<IConstIterator<ValueType>> createConstIterator() const override
  {
    std::unique_ptr<IConstIterator<ValueType>> result(new ListConstIterator(Container, Container->begin()));
    return result;
  }

private:
  /// \brief Реализация абстрактного интерфейса IConstIterator.
  class ListConstIterator
    : public IConstIterator<ValueType>
  {
  public:
    /// \brief Конструктор инициализации. 
    /// \param container Умный указатель на стандартный контейнер-список хранящий значения типа \a ValueType.
    /// \param const_iterator Константный итератор на элемент контейнера-список указывающий на элемент типа \a ValueType.
    ListConstIterator(std::shared_ptr<std::list<ValueType>> container, std::list<ValueType>::const_iterator const_iterator)
      : Container(container)
      , ConstIterator(const_iterator)
    {}
    /// \brief Деструктор по умолчанию.
    virtual ~ListConstIterator() = default;

  public:
    /// \brief Проверить, есть ли следующий элемент.
    /// \return Признак того, что существует следующий элемент контейнера.
    bool hasNext() const override
    {
      return (ConstIterator != Container->end());
    }
    /// \brief Проверить, есть ли предыдущий элемент.
    /// \return Признак того, что существует предыдущий элемент контейнера.
    bool hasPrev() const override
    {
      return (ConstIterator != Container->begin());
    }
    /// \brief Передвигает итератор на следующий элемент контейнера.
    /// \return Признак того, что операция перехода на следующий элемент контейнера - выполнена.
    bool next() override
    {
      if (hasNext() != false)
      {
        ++ConstIterator;
        return true;
      }
      return false;
    }
    /// \brief Передвигает итератор на предыдущий элемент контейнера.
    /// \return Признак того, что операция перехода на предыдущий элемент контейнера - выполнена.
    bool prev() override
    {
      if (hasPrev() != false)
      {
        --ConstIterator;
        return true;
      }
      return false;
    }
    /// \brief Вернуть текущий элемент без продвижения итератора.
    /// \return Значение текущего элемента контейнера.
    const ValueType& peek() const override
    {
      return *ConstIterator;
    }

  private:
    /// \brief Конструктор по умолчанию.
    ListConstIterator() = delete;
    /// \brief Конструктор копирования.
    /// \param[in] right Копируемый объект.
    ListConstIterator(const ListConstIterator& right) = delete;
    /// \brief Конструктор перемещения.
    /// \param[in] right Перемещаемый объект.
    ListConstIterator(ListConstIterator&& right) = delete;
    /// \brief Оператор копирования.
    /// \param[in] right Копируемый объект.
    /// \return Ссылка на изменённый объект.
    ListConstIterator& operator=(const ListConstIterator& right) = delete;
    /// \brief Оператор перемещения.
    /// \param[in] right Перемещаемый объект.
    /// \return Ссылка на изменённый объект.
    ListConstIterator& operator =(ListConstIterator&&) = delete;

  private:
    std::shared_ptr<std::list<ValueType>> Container;
    std::list<ValueType>::const_iterator ConstIterator;
  };

  /// \brief Реализация абстрактного интерфейса IIterator.
  class ListIterator
    : public IIterator<ValueType>
  {
  public:
    /// \brief Конструктор инициализации. 
    /// \param container Умный указатель на стандартный контейнер-список хранящий значения типа \a ValueType.
    /// \param const_iterator Итератор на элемент контейнера-список указывающий на элемент типа \a ValueType.
    ListIterator(std::shared_ptr<std::list<ValueType>> container, std::list<ValueType>::iterator iterator)
      : Container(container)
      , Iterator(iterator)
    {}
    /// \brief Деструктор по умолчанию.
    virtual ~ListIterator() = default;

  public:
    /// \brief Проверить, есть ли следующий элемент.
    /// \return Признак того, что существует следующий элемент контейнера.
    bool hasNext() const override
    {
      return (Iterator != Container->end());
    }
    /// \brief Проверить, есть ли предыдущий элемент.
    /// \return Признак того, что существует предыдущий элемент контейнера.
    bool hasPrev() const override
    {
      return (Iterator != Container->begin());
    }
    /// \brief Передвигает итератор на следующий элемент контейнера.
    /// \return Признак того, что операция перехода на следующий элемент контейнера - выполнена.
    bool next() override
    {
      if (hasNext() != false)
      {
        ++Iterator;
        return true;
      }
      return false;
    }
    /// \brief Передвигает итератор на предыдущий элемент контейнера.
    /// \return Признак того, что операция перехода на предыдущий элемент контейнера - выполнена.
    bool prev() override
    {
      if (hasPrev() != false)
      {
        --Iterator;
        return true;
      }
      return false;
    }
    /// \brief Вернуть текущий элемент без продвижения итератора.
    /// \return Значение текущего элемента контейнера.
    ValueType& peek() override
    {
      return *Iterator;
    }

  private:
    /// \brief Конструктор по умолчанию.
    ListIterator() = delete;
    /// \brief Конструктор копирования.
    /// \param[in] right Копируемый объект.
    ListIterator(const ListIterator& right) = delete;
    /// \brief Конструктор перемещения.
    /// \param[in] right Перемещаемый объект.
    ListIterator(ListIterator&& right) = delete;
    /// \brief Оператор копирования.
    /// \param[in] right Копируемый объект.
    /// \return Ссылка на изменённый объект.
    ListIterator& operator=(const ListIterator& right) = delete;
    /// \brief Оператор перемещения.
    /// \param[in] right Перемещаемый объект.
    /// \return Ссылка на изменённый объект.
    ListIterator& operator =(ListIterator&&) = delete;

  private:
    std::shared_ptr<std::list<ValueType>> Container;
    std::list<ValueType>::iterator Iterator;
  };

private:
  /// \brief Конструктор копирования.
  /// \param[in] right Копируемый объект.
  List(const List& right) = delete;
  /// \brief Конструктор перемещения.
  /// \param[in] right Перемещаемый объект.
  List(List&& right) = delete;
  /// \brief Оператор копирования.
  /// \param[in] right Копируемый объект.
  /// \return Ссылка на изменённый объект.
  List& operator=(const List& right) = delete;
  /// \brief Оператор перемещения. 
  /// \param[in] right Перемещаемый объект.
  /// \return Ссылка на изменённый объект.
  List& operator =(List&&) = delete;
 
private:
  std::shared_ptr<std::list<ValueType>> Container; 
};