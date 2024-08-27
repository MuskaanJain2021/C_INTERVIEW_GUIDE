#include <stdio.h>

// Define a union to handle multiple data types
typedef union {
    int i;
    float f;
    double d;
} DataValue;

// Enum to identify the data type
typedef enum {
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE
} DataType;

// Structure to hold data with its type
typedef struct {
    DataValue value;
    DataType type;
} Operand;

// Structure for operation handling
typedef struct {
    char operator;
    Operand (*operation)(Operand, Operand);
} Operation;

// Function prototypes for mixed-type operations
Operand add(Operand a, Operand b);
Operand subtract(Operand a, Operand b);
Operand multiply(Operand a, Operand b);
Operand divide(Operand a, Operand b);

// Helper function to determine the dominant data type
DataType dominantType(DataType type1, DataType type2) {
    if (type1 == DOUBLE_TYPE || type2 == DOUBLE_TYPE) {
        return DOUBLE_TYPE;
    } else if (type1 == FLOAT_TYPE || type2 == FLOAT_TYPE) {
        return FLOAT_TYPE;
    }
    return INT_TYPE;
}

// Helper functions to perform type conversions
double toDouble(Operand op) {
    switch (op.type) {
        case INT_TYPE: return (double)op.value.i;
        case FLOAT_TYPE: return (double)op.value.f;
        case DOUBLE_TYPE: return op.value.d;
    }
    return 0.0;
}

Operand add(Operand a, Operand b) {
    Operand result;
    result.type = dominantType(a.type, b.type);
    if (result.type == DOUBLE_TYPE) {
        result.value.d = toDouble(a) + toDouble(b);
    } else if (result.type == FLOAT_TYPE) {
        result.value.f = (float)toDouble(a) + (float)toDouble(b);
    } else {
        result.value.i = (int)toDouble(a) + (int)toDouble(b);
    }
    return result;
}

Operand subtract(Operand a, Operand b) {
    Operand result;
    result.type = dominantType(a.type, b.type);
    if (result.type == DOUBLE_TYPE) {
        result.value.d = toDouble(a) - toDouble(b);
    } else if (result.type == FLOAT_TYPE) {
        result.value.f = (float)toDouble(a) - (float)toDouble(b);
    } else {
        result.value.i = (int)toDouble(a) - (int)toDouble(b);
    }
    return result;
}

Operand multiply(Operand a, Operand b) {
    Operand result;
    result.type = dominantType(a.type, b.type);
    if (result.type == DOUBLE_TYPE) {
        result.value.d = toDouble(a) * toDouble(b);
    } else if (result.type == FLOAT_TYPE) {
        result.value.f = (float)toDouble(a) * (float)toDouble(b);
    } else {
        result.value.i = (int)toDouble(a) * (int)toDouble(b);
    }
    return result;
}

Operand divide(Operand a, Operand b) {
    Operand result;
    result.type = dominantType(a.type, b.type);
    if (result.type == DOUBLE_TYPE) {
        if (toDouble(b) != 0.0) {
            result.value.d = toDouble(a) / toDouble(b);
        } else {
            printf("Error: Division by zero.\n");
            result.value.d = 0.0;
        }
    } else if (result.type == FLOAT_TYPE) {
        if ((float)toDouble(b) != 0.0f) {
            result.value.f = (float)toDouble(a) / (float)toDouble(b);
        } else {
            printf("Error: Division by zero.\n");
            result.value.f = 0.0f;
        }
    } else {
        if ((int)toDouble(b) != 0) {
            result.value.i = (int)toDouble(a) / (int)toDouble(b);
        } else {
            printf("Error: Division by zero.\n");
            result.value.i = 0;
        }
    }
    return result;
}

// Function to perform the calculation
Operand performCalculation(char operator, Operand num1, Operand num2, Operation operations[], int size) {
    for (int i = 0; i < size; i++) {
        if (operations[i].operator == operator) {
            return operations[i].operation(num1, num2);
        }
    }
    printf("Error: Invalid operator.\n");
    Operand invalid;
    return invalid;
}

int main(void) {
    // Operation array with function pointers for mixed-type operations
    Operation operations[] = {
        {'+', add},
        {'-', subtract},
        {'*', multiply},
        {'/', divide}
    };

    Operand num1, num2, result;
    char operator;
    int choice1, choice2;

    // User selects the data types for both operands
    printf("Select data type for operand 1 (1: int, 2: float, 3: double): ");
    scanf("%d", &choice1);
    printf("Select data type for operand 2 (1: int, 2: float, 3: double): ");
    scanf("%d", &choice2);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Set operand 1
    if (choice1 == 1) {
        num1.type = INT_TYPE;
        printf("Enter integer value: ");
        scanf("%d", &num1.value.i);
    } else if (choice1 == 2) {
        num1.type = FLOAT_TYPE;
        printf("Enter float value: ");
        scanf("%f", &num1.value.f);
    } else if (choice1 == 3) {
        num1.type = DOUBLE_TYPE;
        printf("Enter double value: ");
        scanf("%lf", &num1.value.d);
    } else {
        printf("Invalid choice.\n");
        return -1;
    }

    // Set operand 2
    if (choice2 == 1) {
        num2.type = INT_TYPE;
        printf("Enter integer value: ");
        scanf("%d", &num2.value.i);
    } else if (choice2 == 2) {
        num2.type = FLOAT_TYPE;
        printf("Enter float value: ");
        scanf("%f", &num2.value.f);
    } else if (choice2 == 3) {
        num2.type = DOUBLE_TYPE;
        printf("Enter double value: ");
        scanf("%lf", &num2.value.d);
    } else {
        printf("Invalid choice.\n");
        return -1;
    }

    // Perform calculation
    result = performCalculation(operator, num1, num2, operations, sizeof(operations) / sizeof(operations[0]));

    // Display the result based on the dominant type
    printf("Result: ");
    if (result.type == INT_TYPE) {
        printf("%d\n", result.value.i);
    } else if (result.type == FLOAT_TYPE) {
        printf("%f\n", result.value.f);
    } else if (result.type == DOUBLE_TYPE) {
        printf("%lf\n", result.value.d);
    }

    return 0;
}
