add_library("${PROJECT_NAME}" SHARED sogouim.cpp)

include_directories("${PROJECT_SOURCE_DIR}/../../ks/include")
include_directories("${PROJECT_SOURCE_DIR}/../../../src/engine/include")
include_directories("${PROJECT_SOURCE_DIR}/../../../src/panel/include")
include_directories("${PROJECT_SOURCE_DIR}/../../../src/keyflow/include")
include_directories("${PROJECT_SOURCE_DIR}/../../../include")
include_directories("${PROJECT_SOURCE_DIR}/../../../include/third_part")

configure_file(config.h.in ${PROJECT_SOURCE_DIR}/config.h @ONLY)

target_link_libraries(${PROJECT_NAME} 
                        Fcitx5::Core
                        ${PKG_X11_LDFLAGS}
                        ${PKG_XTST_LDFLAGS}
                        cpis-panel
                        )

install(TARGETS "${PROJECT_NAME}" DESTINATION "${FCITX_INSTALL_LIBDIR}/fcitx5")

configure_file(sogouim-addon.conf.in sogouim-addon.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/sogouim-addon.conf" RENAME sogouim.conf DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon")

configure_file(sogouim.conf.in sogouim.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/sogouim.conf"  DESTINATION "${FCITX_INSTALL_PKGDATADIR}/inputmethod")


