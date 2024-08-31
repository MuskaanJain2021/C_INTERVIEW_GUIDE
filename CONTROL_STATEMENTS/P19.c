/*Accept a month in digit from the user. Display the month in words. If number is not
        between 1 and 12 display message “Invalid Month”. (Use ‘switch’)*/
#include <stdio.h>

// Function to get the month name based on the month number
const char* getMonthName(int month) {
    const char *months[] = {"Invalid", "January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    
    if (month >= 1 && month <= 12)
        return months[month];
    else
        return "Invalid Month";
}

// Function to get user input
int getUserInput() {
    int month;
    printf("Enter the month number (1-12): ");
    scanf("%d", &month);
    return month;
}

// Function to display the month name
void displayMonthName(const char* monthName) {
    printf("%s\n", monthName);
}

int main() {
    int month = getUserInput();           // Get user input
    const char* monthName = getMonthName(month);  // Get the month name based on the input
    displayMonthName(monthName);          // Display the month name

    return 0;
}
