#include "preferencesettings.h"

PreferenceSettings &PreferenceSettings::GetInstance()
{
    if (settings == nullptr) {
        settings = new PreferenceSettings();
    }

    return settings;
}

PreferenceSettings::PreferenceSettings()
{


}
