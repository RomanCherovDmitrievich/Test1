/// \file AirportLib.h
/// \brief Конфигурационный файл проекта.
/// \author Чернов Роман
#pragma once

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#  ifdef AIRPORT_LIBRARY_EXPORTS
/// \def AIRPORT_LIBRARY_API
/// \brief Определения ключевых слов компилятора для определения экспортирования имени.
#    define AIRPORT_LIBRARY_API __declspec(dllexport)
#  else 
/// \def AIRPORT_LIBRARY_API
/// \brief Определения ключевых слов компилятора для определения экспортирования имени.
#    define AIRPORT_LIBRARY_API __declspec(dllimport)
#  endif
/// \def AIRPORT_LIBRARY_LOCAL
/// \brief Определения ключевых слов компилятора для скрытия экспортирования имени.
#  define AIRPORT_LIBRARY_LOCAL
#else
/// \def AIRPORT_LIBRARY_API
/// \brief Определения ключевых слов компилятора для определения экспортирования имени.
#  define AIRPORT_LIBRARY_API __attribute__((visibility("default")))
/// \def AIRPORT_LIBRARY_LOCAL
/// \brief Определения ключевых слов компилятора для скрытия экспортирования имени.
#  define AIRPORT_LIBRARY_LOCAL __attribute__((visibility ("hidden")))
#endif
