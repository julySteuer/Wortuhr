#include <EEPROM.h>
#include <Arduino.h>

// Untested
namespace Storage {
    struct t_Crendentials {
        String username;
        String password;
        String SSID;
    };

    void storeString(String input, int offset) {
        for (int i = 0;i <= input.length();i++) {
            EEPROM.write(i+offset, (int)input.charAt(i));
        }
    }

    void storeCredentials(t_Crendentials creds) { // Expensive operation both time and hardware. The eeprom is limited to ~ 100.000 writes so we want to be careful bout the state 
        // Store has_data 0x55 means data (0x55 for "Special Reasons")
        EEPROM.write(0,0x55); // + 1
        // Store username
        storeString(creds.username, 1); // username + 1 + 1
        // Store termination byte 
        EEPROM.write(creds.username.length()+2, '\n'); // username + 1 + 1
        // Store password
        storeString(creds.password, creds.username.length()+3); // username + 1 + 1 + 1
        // Store EOS
        EEPROM.write(creds.username.length()+creds.password.length()+4, '\n');
        // Store SSID
        storeString(creds.SSID, creds.username.length()+creds.password.length()+5);
        EEPROM.write(creds.username.length()+creds.password.length()+creds.SSID.length()+6, '\n');
    }


    String readString(int offset) { // Kinda tested ig 
        char curr;
        String build;
        int i = 0;
        while(curr != '\n') {
            build += curr;
            curr = EEPROM.read(i+offset);
            i++;
        }
        return build;
    }

    // Call after credentialsSet test only if true 
    t_Crendentials readCredentials() {
        struct t_Crendentials creds;
        creds.username = readString(1);
        creds.password = readString(creds.username.length()+3);
        creds.SSID = readString(creds.username.length()+creds.password.length()+5);
        return creds;
    }

    bool credentialsSet() {
        return EEPROM.read(0) == 0x55;
    }
}