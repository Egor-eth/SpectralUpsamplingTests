set(MODULE_NAME precompute_sigpoly)
set(MODULE_PATH ${SRC}/apps/precompute_sigpoly)

set(MODULE_SOURCES
    main.cpp
    functions.cpp
)

set(MODULE_LIBS
    spectral ceres
)