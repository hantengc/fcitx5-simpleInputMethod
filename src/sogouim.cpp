#include "sogouim.h"

namespace fcitx {
SogouIMEngine::SogouIMEngine(Instance *instance) : instance_(instance) {}

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

} // namespace fcitx

FCITX_ADDON_FACTORY(fcitx::SogouIMEngineFactory)
