#include "sogouim.h"

namespace fcitx {
SogouIMEngine::SogouIMEngine(Instance *instance)
    : instance_(instance), bus_(dbus()->call<IDBusModule::bus>()),
      watcher_(*bus_) {
    watch();
    connectSignal();
}

SogouIMEngine::~SogouIMEngine() {}

void SogouIMEngine::keyEvent(const InputMethodEntry &entry,
                             KeyEvent &keyEvent) {
    FCITX_INFO() << "key = " << keyEvent.key();
}

void SogouIMEngine::activate(const InputMethodEntry &entry,
                             InputContextEvent &event) {
    FCITX_INFO() << "SogouIMEngine::activate";
    auto *inputContext = event.inputContext();
    printf("inputcontext = %p\n", inputContext);
}

void SogouIMEngine::deactivate(const InputMethodEntry &entry,
                               InputContextEvent &event) {
    FCITX_INFO() << "SogouIMEngine::deactivate";
}

void SogouIMEngine::reloadConfig() {
    FCITX_INFO() << "SogouIMEngine::reloadConfig";
}
void SogouIMEngine::reset(const InputMethodEntry &entry,
                          InputContextEvent &event) {
    FCITX_INFO() << "SogouIMEngine::reset";
}
void SogouIMEngine::doReset(InputContext *inputContext) {
    FCITX_INFO() << "SogouIMEngine::doReset";
}
void SogouIMEngine::save() { FCITX_INFO() << "SogouIMEngine::save"; }

void SogouIMEngine::connectSignal() {
    FCITX_INFO() << "\r\n";
    FCITX_INFO() << "connectSignal = " << __FUNCTION__;
    FCITX_INFO() << "\r\n";

    bus_->addMatch(dbus::MatchRule("com.kylin.statusmanager.interface", "/",
                                   "com.kylin.statusmanager.interface"),
                   [this](dbus::Message &message) {
                       FCITX_INFO() << "Commit";

                       return true;
                   });
}

void SogouIMEngine::watch() {
    FCITX_INFO() << "\r\n";
    FCITX_INFO() << "func = " << __FUNCTION__;
    FCITX_INFO() << "\r\n";
    watcher_.watchService("com.kylin.statusmanager.interface",
                          [this](const std::string &, const std::string &,
                                 const std::string &newOwner) {
                              FCITX_INFO()
                                  << "watchService"
                                  << "com.kylin.statusmanager.interface  : "
                                  << newOwner;
                          });
}
} // namespace fcitx

FCITX_ADDON_FACTORY(fcitx::SogouIMEngineFactory)
