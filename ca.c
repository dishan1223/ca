#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to provide help text
char *help() {
    char *helpText = (char *)malloc(1024);
    if (!helpText) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(helpText, "\nUsage:\n");
    strcat(helpText, "  ca -p {chars_separated_with_underscores}  # Print the given characters with underscores\n");
    strcat(helpText, "  ca sf filePath                            # Show the contents of a file\n");
    strcat(helpText, "  ca sf-l                                   # Show file contents with line numbers\n");
    strcat(helpText, "  ca cp SourceFile DistFile                 # Copy SourceFile to DistFile\n");
    strcat(helpText, "  ca finfo FileName                         # Get information about a specific file\n");
    strcat(helpText, "  ca lines FileName                         # Display the number of lines in a file\n");
    strcat(helpText, "  ca c FILENAME                             # Create a blank file\n");
    strcat(helpText, "\nSystem Commands:\n");
    strcat(helpText, "  ca -p 'text'                              # Print 'text' (with underscores)\n");
    strcat(helpText, "  ca -sysinfo                               # Display system information\n");
    strcat(helpText, "  ca -sysS                                  # Show storage capacity\n");
    strcat(helpText, "  ca -time                                  # Display current system time\n");
    strcat(helpText, "  ca -del FileName                          # Delete a specified file\n");

    return helpText;
}

// Function to create a blank file
void create_blank_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fclose(file);
    } else {
        fprintf(stderr, "Unable to create file: %s\n", filename);
    }
}

// Function to print a file with line numbers
void print_file_with_line_numbers(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return;
    }

    char line[256];
    int lineNumber = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("%d %s", lineNumber, line);
        lineNumber++;
    }

    fclose(file);
}

// Function to count the number of lines in a file
int count_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return -1;
    }

    char line[256];
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;
    }

    fclose(file);
    return lineNumber;
}

// Function to copy a file
void copy_file(const char *sourceFilename, const char *destFilename) {
    FILE *sourceFile = fopen(sourceFilename, "r");
    if (!sourceFile) {
        fprintf(stderr, "Unable to open source file: %s\n", sourceFilename);
        return;
    }

    FILE *destFile = fopen(destFilename, "w");
    if (!destFile) {
        fprintf(stderr, "Unable to open destination file: %s\n", destFilename);
        fclose(sourceFile);
        return;
    }

    char c;
    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);

    printf("Success: Contents copied successfully!\n");
}

// Function to display system information
void sys_info() {
    system("neofetch");
}

// Function to display the current time
void display_time() {
    system("date");
}

// Function to show storage capacity
void show_storage_capacity() {
    system("df -H");
}

// Function to display file information
void file_info(const char *filename) {
    char filetypeCmd[256];
    char fileStatCmd[256];
    snprintf(filetypeCmd, sizeof(filetypeCmd), "file %s", filename);
    snprintf(fileStatCmd, sizeof(fileStatCmd), "stat %s", filename);
    system(filetypeCmd);
    printf("\n");
    system(fileStatCmd);
}

// Function to delete a file
void delete_file(const char *filename) {
    if (remove(filename) != 0) {
        fprintf(stderr, "Error: Unable to delete the file: %s\n", filename);
    } else {
        printf("Success: %s Deleted successfully.\n", filename);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("\n use 'ca -h' or 'ca help' to get the help menu\n\n");
        return 0;
    }

    if (strcmp(argv[1], "-p") == 0) {
        if (argc >= 3 && strlen(argv[2]) > 0) {
            printf("%s\n", argv[2]);
        } else {
            printf("Error found at argv[2]\n");
            printf("Correct syntax: ca -p {chars_separated_with_underscores}\n");
            return 1;
        }
    } else if (strcmp(argv[1], "sf") == 0) {
        if (argc >= 3 && strlen(argv[2]) > 0) {
            FILE *inputFile = fopen(argv[2], "r");

            if (inputFile) {
                char line[256];
                while (fgets(line, sizeof(line), inputFile)) {
                    printf("%s", line);
                }
                fclose(inputFile);
                return 0;
            } else {
                printf("Unable to open file: %s\n", argv[2]);
                return 1;
            }
        } else {
            printf("Error found at argv[2]\n");
            printf("Correct syntax: ca --read-file filename\n");
            return 1;
        }
    } else if (strcmp(argv[1], "-sysinfo") == 0) {
        sys_info();
        return 0;
    } else if (strcmp(argv[1], "sf-l") == 0) {
        if (argc >= 3 && strlen(argv[2]) > 0) {
            print_file_with_line_numbers(argv[2]);
        } else {
            printf("Argument and filePath needed. Type ca -h or ca help for details\n");
        }
    } else if (strcmp(argv[1], "-sysS") == 0) {
        show_storage_capacity();
    } else if (strcmp(argv[1], "c") == 0 && strlen(argv[2]) > 0) {
        create_blank_file(argv[2]);
    } else if (strcmp(argv[1], "cp") == 0) {
        if (argc >= 4 && strlen(argv[2]) > 0 && strlen(argv[3]) > 0) {
            copy_file(argv[2], argv[3]);
        }
    } else if (strcmp(argv[1], "finfo") == 0) {
        if (argc >= 3 && strlen(argv[2]) > 0) {
            file_info(argv[2]);
        }
    } else if (strcmp(argv[1], "-time") == 0) {
        display_time();
    } else if (strcmp(argv[1], "lines") == 0) {
        if (argc >= 3 && strlen(argv[2]) > 0) {
            int lines = count_lines(argv[2]);
            printf("Lines: %d\n", lines);
        }
    } else if (strcmp(argv[1], "-del") == 0 && strlen(argv[2]) > 0) {
        delete_file(argv[2]);
        return 0;
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0) {
        char *helpText = help();
        printf("%s\n", helpText);
        free(helpText);
    } else {
        printf("\nInvalid Input\n");
        char *helpText = help();
        printf("%s\n", helpText);
        free(helpText);
        return 1;
    }

    return 0;
}

