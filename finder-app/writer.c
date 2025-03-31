#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    
    openlog("MyUtility", LOG_PID | LOG_CONS, LOG_USER);
	
    // Check for correct arguments
    if (argc != 3) {
        syslog(LOG_ERR,"Usage: %s <file_path> <string_to_write>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    const char *string_to_write = argv[2];

    // Open file for writing
    FILE *file = fopen(file_path, "w");
    if (!file) {
        syslog(LOG_ERR, "Error opening file");
        exit(1);
    }

    // Write string to file
    fprintf(file, "%s\n", string_to_write);
    syslog(LOG_INFO,"Successfully written to %s\n", file_path);

    // Close file
    fclose(file);
    
    
    closelog();
    return 0;
}
