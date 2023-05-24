#ifndef _SOGOUIM_H_
#define _SOGOUIM_H_

#include <iostream>

#include <fcitx/addonfactory.h>
#include <fcitx/addonmanager.h>
#include <fcitx/inputmethodengine.h>
#include "fcitx/addoninstance.h"

namespace fcitx {

class SogouIMEngine final : public InputMethodEngineV3 {
public:
    SogouIMEngine(Instance *instance);
    ~SogouIMEngine();
    Instance *instance() { return instance_; }
    void keyEvent(const InputMethodEntry &entry, KeyEvent &keyEvent) override;

private:
    Instance *instance_;
};

class SogouIMEngineFactory : public AddonFactory {
public:
    AddonInstance *create(AddonManager *manager) override {
        FCITX_INFO() << "SogouIMEngineFactory ...";
        return new SogouIMEngine(manager->instance());
    }
};

} // namespace fcitx

#endif