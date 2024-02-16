add_library(request)
target_sources(request PUBLIC request.cpp)
target_include_directories(request PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(server)
target_sources(server PRIVATE server.cpp)
target_link_libraries(server PRIVATE base request)
