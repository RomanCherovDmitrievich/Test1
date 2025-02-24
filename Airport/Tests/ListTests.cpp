#include <gtest/gtest.h>
#include "List.h"

TEST(ListTests, DefaultConstructor)
{
  // После создания контейнера размер контейнера равно 0.
  List<int> list;

  ASSERT_EQ(list.size(), 0);
}

TEST(ListTests, Add)
{
  // После каждого добавления элемента в контейнера размер контейнера увеличивается на 1. 
  List<int> list;
  list.add(1);

  ASSERT_EQ(list.size(), 1);
  
  list.add(2);
  ASSERT_EQ(list.size(), 2);
}

TEST(ListTests, Remove)
{
  // После каждого добавления элемента в контейнера размер контейнера увеличивается на 1. 
  List<int> list;
  list.add(1);
  list.add(2);
  list.add(3);

  ASSERT_EQ(list.remove(4), false);
  ASSERT_EQ(list.size(), 3);
  ASSERT_NE(list.remove(2), false);
  ASSERT_EQ(list.size(), 2);
}

TEST(ListTests, createIterator)
{
  List<int> list;
  // Итератор в пустом контейнере можно создать и функции определения следующего и предыдущего элемента возвращают false.
  {
    std::unique_ptr<IIterator<int>> it = list.createIterator();
    ASSERT_EQ(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);  
  }
  list.add(1);
  {
    std::unique_ptr<IIterator<int>> it = list.createIterator();
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);

    ASSERT_NE(it->next(), false);
    ASSERT_EQ(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);

    ASSERT_EQ(it->next(), false);
    ASSERT_EQ(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);

    ASSERT_NE(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);

    ASSERT_EQ(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);
  }
  list.add(2);
  // Проверка работы с итератором, когда в контейнере больше одного элемента.
  {
    std::unique_ptr<IIterator<int>> it = list.createIterator();
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);

    ASSERT_NE(it->next(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 2);

    ASSERT_NE(it->next(), false);
    ASSERT_EQ(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);

    ASSERT_NE(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 2);

    ASSERT_NE(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);

    ASSERT_EQ(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);
  }
  // Проверка возможности модифицировать значение элемента через итератор.
  {
    std::unique_ptr<IIterator<int>> it = list.createIterator();
    ASSERT_EQ(it->peek(), 1);
    it->peek() = 3;
    ASSERT_EQ(it->peek(), 3);
  }
}

TEST(ListTests, createConstIterator)
{
  List<int> list;
  // Итератор в пустом контейнере можно создать и функции определения следующего и предыдущего элемента возвращают false.
  {
    std::unique_ptr<IConstIterator<int>> it = list.createConstIterator();
    ASSERT_EQ(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);  
  }
  list.add(1);
  {
    std::unique_ptr<IConstIterator<int>> it = list.createConstIterator();
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);

    ASSERT_NE(it->next(), false);
    ASSERT_EQ(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);

    ASSERT_EQ(it->next(), false);
    ASSERT_EQ(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);

    ASSERT_NE(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);

    ASSERT_EQ(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);
  }
  list.add(2);
  // Проверка работы с итератором, когда в контейнере больше одного элемента.
  {
    std::unique_ptr<IConstIterator<int>> it = list.createConstIterator();
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);

    ASSERT_NE(it->next(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 2);

    ASSERT_NE(it->next(), false);
    ASSERT_EQ(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);

    ASSERT_NE(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_NE(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 2);

    ASSERT_NE(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);

    ASSERT_EQ(it->prev(), false);
    ASSERT_NE(it->hasNext(), false);
    ASSERT_EQ(it->hasPrev(), false);
    ASSERT_EQ(it->peek(), 1);
  }
}
