add_library(Unity STATIC
        Unity/src/Unity.c
)

target_include_directories(Unity PUBLIC
        Unity/src
)