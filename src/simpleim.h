#ifndef _SIMPLEIM_H_
#define _SIMPLEIM_H_

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

class SimpleIMEngine final : public InputMethodEngineV3 {
public:
    SimpleIMEngine(Instance *instance);
    ~SimpleIMEngine() override;
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
    std::unique_ptr<EventSourceTime> timeout_;
};

class SimpleIMEngineFactory : public AddonFactory {
public:
    AddonInstance *create(AddonManager *manager) override {
        FCITX_INFO() << "SimpleIMEngineFactory ...";
        return new SimpleIMEngine(manager->instance());
    }
};

} // namespace fcitx

#endif