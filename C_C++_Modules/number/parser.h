#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_number(char *string)
{
    if(string == NULL || *string == '\0') return false; // Checking if the string is Empty...
    int count_dot = 0, count_plus = 0, count_minus = 0; // Initializing...
    // Checking if the string is a number...
    while(*string)
    {
        char c = *string;
        switch(c)
        {
            case '.':
                if(++count_dot > 1) return false;
                break;
            case '+':
                if(++count_plus > 1) return false;
                break;
            case '-':
                if(++count_minus > 1) return false;
                break;
            default:
                if(c < '0' || c > '9') return false;
                break;
        }
        string++;
    }
    // If it's a number then return True...
    return true;
}

char **split(char *string, char c)
{  
    // Initialize...
    int len = strlen(string), count_c = 0, number_of_tokens = 0;
    char str_c[1], **list_of_tokens = malloc(sizeof(char)*(len-count_c) + sizeof(char *)*(len-count_c-2));
    sprintf(str_c, "%c", c);
    // Split...
    char *token = strtok(string, str_c);
    while (token != NULL) 
    { 
        list_of_tokens[number_of_tokens] = token;
        number_of_tokens++;
        token = strtok(NULL, str_c);
    }
    // Return the splited 2D-Array of character...
    return list_of_tokens;
}

double *parse_number(char *string, int num)
{
    int count = 0, c = 0, i;
    double temp_num;
    // Get the splitted_String as a 2D_Character_Array...
    sprintf(string, "%s ", string);
    char **splitted_string = split(string, ' ');
    // Initialize the Number_Array...
    while(splitted_string[count]) count++;
    double *list_of_nums = (double *)malloc(count * sizeof(double));
    // Parse the numbers...
    for(i=0; i<count; i++)
    {
        if(is_number(splitted_string[i]))
        {
            sscanf(splitted_string[i], "%lf", &temp_num); 
            list_of_nums[c++] = temp_num;
            if(num != -1 && c == num) break;
        }
    }
    // Return the list as a double type Number_Array...
    return list_of_nums;
}