add_library("${PROJECT_NAME}" SHARED simpleim.cpp)

find_package(Fcitx5Core REQUIRED)
find_package(Fcitx5Module REQUIRED COMPONENTS DBus)

target_link_libraries(${PROJECT_NAME} 
                        Fcitx5::Core
                        ${PKG_X11_LDFLAGS}
                        ${PKG_XTST_LDFLAGS}
                        Fcitx5::Module::DBus
                        )

install(TARGETS "${PROJECT_NAME}" DESTINATION "${FCITX_INSTALL_LIBDIR}/fcitx5")

configure_file(simpleim-addon.conf.in simpleim-addon.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/simpleim-addon.conf" RENAME simpleim.conf DESTINATION "${FCITX_INSTALL_PKGDATADIR}/addon")

configure_file(simpleim.conf.in simpleim.conf)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/simpleim.conf"  DESTINATION "${FCITX_INSTALL_PKGDATADIR}/inputmethod")


