#Включить предпочтительное использование флага компилятора и компоновщика -pthread.
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        ${GTEST_VERSION}
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(AirportLibTests RouteTests.cpp RouteWithDiscountTests.cpp ListTests.cpp AirportTests.cpp)

target_link_libraries(AirportLibTests
  PRIVATE
    GTest::GTest
    Threads::Threads
    AirportLib
    )

# Удалить все ранее созданные файлы для анализа покрытия.
add_custom_target(clean_all_gcda COMMAND find . -name "*.gcda" -print0 | xargs -0 rm)
# Запуск автотестов и создания файлов покрытия по которым будет оцениваться покрытие утилитой gcovr. Предварительно
# вызвать команду clean_all_gcda.
add_custom_target(check COMMAND AirportLibTests DEPENDS clean_all_gcda)

find_program(GCOVR_EXECUTABLE gcovr)
if(AIRPORT_COVERAGE AND GCOVR_EXECUTABLE)


    message(STATUS "Измерение покрытия кода тестами включено")

    target_compile_options(AirportLibTests PRIVATE --coverage -O0 -fprofile-arcs -ftest-coverage)
    target_link_options(AirportLibTests PRIVATE --coverage -fprofile-arcs -ftest-coverage)

    add_custom_target(coverage
        COMMAND
            ${GCOVR_EXECUTABLE}
                --root=${PROJECT_SOURCE_DIR}/
                --object-directory=${PROJECT_BINARY_DIR}
                --filter=${PROJECT_SOURCE_DIR}/C++

        DEPENDS
            check
    )
elseif(AIRPORT_COVERAGE AND NOT GCOVR_EXECUTABLE)
    set(AIRPORT_COVERAGE OFF)
    message(WARNING "Для замеров покрытия кода тестами требуется программа gcovr")
endif()

add_test(Test AirportLibTests)

