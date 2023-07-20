#include "simpleim.h"

namespace fcitx {
SimpleIMEngine::SimpleIMEngine(Instance *instance)
    : instance_(instance), bus_(dbus()->call<IDBusModule::bus>()),
      watcher_(*bus_) {
    connectSignal();
}

SimpleIMEngine::~SimpleIMEngine() {}

void SimpleIMEngine::keyEvent(const InputMethodEntry &entry,
                              KeyEvent &keyEvent) {
    FCITX_INFO() << "key = " << keyEvent.key();
    FCITX_UNUSED(entry);
    FCITX_UNUSED(keyEvent);
}

void SimpleIMEngine::activate(const InputMethodEntry &entry,
                              InputContextEvent &event) {
    FCITX_INFO() << "SimpleIMEngine::activate";

    FCITX_UNUSED(entry);
    FCITX_UNUSED(event);

    timeout_ = instance_->eventLoop().addTimeEvent(
        CLOCK_MONOTONIC, now(CLOCK_MONOTONIC) + 300000, 0,
        [this](EventSourceTime *, uint64_t) {
            FCITX_INFO() << "time out";
            return true;
        });
}

void SimpleIMEngine::deactivate(const InputMethodEntry &entry,
                                InputContextEvent &event) {
    FCITX_INFO() << "SimpleIMEngine::deactivate";
    FCITX_UNUSED(entry);
    FCITX_UNUSED(event);
}

void SimpleIMEngine::reloadConfig() {
    FCITX_INFO() << "SimpleIMEngine::reloadConfig";
}
void SimpleIMEngine::reset(const InputMethodEntry &entry,
                           InputContextEvent &event) {
    FCITX_INFO() << "SimpleIMEngine::reset";
    FCITX_UNUSED(entry);
    FCITX_UNUSED(event);
}
void SimpleIMEngine::doReset(InputContext *inputContext) {
    FCITX_INFO() << "SimpleIMEngine::doReset";
    FCITX_UNUSED(inputContext);
}
void SimpleIMEngine::save() { FCITX_INFO() << "SimpleIMEngine::save"; }

void SimpleIMEngine::connectSignal() {
    slot_ =
        bus_->addMatch(dbus::MatchRule("com.kylin.statusmanager.interface", "/",
                                       "com.kylin.statusmanager.interface"),
                       [this](dbus::Message &message) {
                           FCITX_UNUSED(message);

                           return true;
                       });
}

void SimpleIMEngine::watch() {
    entry_ = watcher_.watchService(
        "com.kylin.statusmanager.interface",
        [this](const std::string &, const std::string &,
               const std::string &newOwner) {
            FCITX_INFO() << "watchService"
                         << "com.kylin.statusmanager.interface  : " << newOwner;
        });
}
} // namespace fcitx

FCITX_ADDON_FACTORY(fcitx::SimpleIMEngineFactory)
