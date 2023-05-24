#include "sogouim.h"

namespace fcitx {
SogouIMEngine::SogouIMEngine(Instance *instance) : instance_(instance) {}

SogouIMEngine::~SogouIMEngine() {}

void SogouIMEngine::keyEvent(const InputMethodEntry &entry,
                             KeyEvent &keyEvent) {
    std::cout << "key = " << std::endl;
}
} // namespace fcitx

FCITX_ADDON_FACTORY(fcitx::SogouIMEngineFactory)
