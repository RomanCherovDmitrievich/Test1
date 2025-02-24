add_executable (Airport1
Main.cpp
Route.cpp
RouteWithDiscount.cpp
)
target_include_directories(Airport1 PRIVATE ".")
set_property(TARGET Airport1 PROPERTY COMPILE_WARNING_AS_ERROR ON)
if(MSVC)
  target_compile_options(Airport1 PRIVATE /W4 /WX)
else()
  target_compile_options(Airport1 PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference)
endif()