#include <EEPROM.h>
#include <Arduino.h>

// Untested
namespace Storage
{
    struct t_Crendentials
    {
        String username;
        String password;
        String SSID;
    };

    void storeCredentials(t_Crendentials creds)
    {
        // Expensive operation both time and hardware. The eeprom is limited to ~ 100.000 writes so we want to be careful bout the state
        // Store has_data 0x55 means data (0x55 for "Special Reasons")
        int offset = 0;
        EEPROM.write(offset, 0x55); // + 1
        offset++;
        EEPROM.put(offset, creds);
        EEPROM.commit();
    }

    // Call after credentialsSet test only if true
    t_Crendentials readCredentials()
    {
        struct t_Crendentials creds;
        EEPROM.get(1, creds);
        return creds;
    }

    bool credentialsSet()
    {
        return EEPROM.read(0) == 0x55;
    }

    void initStorage(size_t size)
    {
        EEPROM.begin(size);
    }
}