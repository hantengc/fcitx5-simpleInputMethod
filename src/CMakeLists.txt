add_library("${PROJECT_NAME}" SHARED sogouim.cpp)
target_link_libraries(${PROJECT_NAME} 
                        Fcitx5::Core
                        ${PKG_X11_LDFLAGS}
                        ${PKG_XTST_LDFLAGS}
                        )

install(TARGETS "${PROJECT_NAME}" DESTINATION "${FCITX_INSTALL_LIBDIR}/fcitx5")

configure_file(sogouim-addon.conf.in sogouim-addon.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/sogouim-addon.conf" RENAME sogouim.conf DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon")

configure_file(sogouim.conf.in sogouim.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/sogouim.conf"  DESTINATION "${FCITX_INSTALL_PKGDATADIR}/inputmethod")


