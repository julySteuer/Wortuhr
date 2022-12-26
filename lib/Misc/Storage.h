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

    void storeString(int offset, String input)
    {
        input += "\n";
        for (int i = 0; i < input.length(); i++)
        {
            EEPROM.write(i + offset, (byte)input.charAt(i));
        }
        return offset + input.length();
    }

    void storeCredentials(t_Crendentials creds)
    {
        // Expensive operation both time and hardware. The eeprom is limited to ~ 100.000 writes so we want to be careful bout the state
        // Store has_data 0x55 means data (0x55 for "Special Reasons")
        int offset = 0;
        EEPROM.write(offset, 0x55); // + 1
        offset++;
        EEPROM.put(offset, creds)
    }

    String readString(int offset)
    { // Kinda tested ig
        char curr;
        String build;
        int i = 0;
        while (curr != '\n')
        {
            build += curr;
            curr = EEPROM.read(i + offset);
            i++;
        }
        return build;
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
}