add_library(AirportLib SHARED
  Private/Route.cpp
  Private/RouteWithDiscount.cpp
  Private/Airport.cpp
  )
add_compile_definitions(AIRPORT_LIBRARY_EXPORTS)
target_include_directories(AirportLib PUBLIC ".")
set_property(TARGET AirportLib PROPERTY COMPILE_WARNING_AS_ERROR ON)
if(MSVC)
  target_compile_options(AirportLib PRIVATE /W4 /WX)
else()
  target_compile_options(AirportLib PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()

if(AIRPORT_COVERAGE)
    message(STATUS "Измерение покрытия кода тестами включено")
    target_compile_options(AirportLib PRIVATE --coverage -O0 -fprofile-arcs -ftest-coverage)
    target_link_options(AirportLib PRIVATE --coverage -fprofile-arcs -ftest-coverage)
endif()
