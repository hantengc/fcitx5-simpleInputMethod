#ifndef _SOGOUIM_H_
#define _SOGOUIM_H_

#include <dbus_public.h>
#include <fcitx-utils/dbus/bus.h>
#include <fcitx-utils/dbus/servicewatcher.h>
#include <fcitx-utils/event.h>
#include <fcitx/addonfactory.h>
#include <fcitx/addoninstance.h>
#include <fcitx/addonmanager.h>
#include <fcitx/inputmethodengine.h>
#include <fcitx/instance.h>

namespace fcitx {

class SogouIMEngine final : public InputMethodEngineV3 {
public:
    SogouIMEngine(Instance *instance);
    ~SogouIMEngine();
    Instance *instance() { return instance_; }
    void activate(const InputMethodEntry &entry,
                  InputContextEvent &event) override;
    void deactivate(const InputMethodEntry &entry,
                    InputContextEvent &event) override;
    void keyEvent(const InputMethodEntry &entry, KeyEvent &keyEvent) override;
    void reloadConfig() override;
    void reset(const InputMethodEntry &entry,
               InputContextEvent &event) override;
    void doReset(InputContext *inputContext);
    void save() override;

private:
    void connectSignal();
    void watch();

private:
    FCITX_ADDON_DEPENDENCY_LOADER(dbus, instance_->addonManager());

private:
    Instance *instance_;
    dbus::Bus *bus_ = nullptr;
    dbus::ServiceWatcher watcher_;
    std::unique_ptr<dbus::ServiceWatcherEntry> entry_;
    std::unique_ptr<dbus::Slot> slot_;
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