#ifndef PREFERENCESETTINGS_H
#define PREFERENCESETTINGS_H


class PreferenceSettings
{
public:
    static PreferenceSettings& GetInstance();





private:
    PreferenceSettings();
    static PreferenceSettings settings = nullptr;
};

#endif // PREFERENCESETTINGS_H
