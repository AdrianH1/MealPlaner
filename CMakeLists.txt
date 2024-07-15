cmake_minimum_required(VERSION 3.27.0)
project(TestProj VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(
    "libs/asio-1.28.0/include"
    ${PROJECT_SOURCE_DIR}/Datastructures
    ${PROJECT_SOURCE_DIR}/DbHelper
    ${PROJECT_SOURCE_DIR}/DbHelper/Query
    )

find_package(SQLite3 REQUIRED)

set(HEADERS
    DbHelper/Query/IQuery.hpp
    DbHelper/Query/CCondition.hpp
    DbHelper/Query/CSelectQuery.hpp
    DbHelper/Query/CInsertQuery.hpp
    DbHelper/Query/IColumnValue.hpp
    DbHelper/CDatabaseManager.hpp
    DbHelper/CDatabaseQueryWrapper.hpp
    Datastructures/CIngredient.hpp
    DbHelper/CIngredientsTable.hpp
    )
    
    set(SOURCES
    DbHelper/Query/CInsertQuery.cpp
    DbHelper/Query/CSelectQuery.cpp
    DbHelper/CDatabaseManager.cpp
    DbHelper/CDatabaseQueryWrapper.cpp

    testDb.cpp
)

add_executable(TestProj ${HEADERS} ${SOURCES} )

target_link_libraries(TestProj wsock32 ws2_32 SQLite::SQLite3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
