
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_SIZE 256
#define INPUT_SIZE 1024

typedef struct {
    long long data[STACK_SIZE];
    int       top;
} Stack;

static void init_stack(Stack* s) {
    s->top = -1;
}

static bool push(Stack* s, long long value) {
    if (s->top >= STACK_SIZE - 1) {
        fprintf(stderr, "Error: stack overflow\n");
        return false;
    }

    s->data[++s->top] = value;
    return true;
}

static bool pop(Stack* s, long long* value) {
    if (s->top < 0) {
        fprintf(stderr, "Error: insufficient operands\n");
        return false;
    }

    *value = s->data[s->top--];
    return true;
}

static bool calculate(char op, long long a, long long b, long long* result) {
    switch (op) {
    case '+':
        if ((b > 0 && a > LLONG_MAX - b) || (b < 0 && a < LLONG_MIN - b)) {
            fprintf(stderr, "Error: addition overflow\n");
            return false;
        }
        *result = a + b;
        return true;

    case '-':
        if ((b < 0 && a > LLONG_MAX + b) || (b > 0 && a < LLONG_MIN + b)) {
            fprintf(stderr, "Error: subtraction overflow\n");
            return false;
        }
        *result = a - b;
        return true;

    case '*':
        if (a != 0 && b != 0) {
            if ((a == -1 && b == LLONG_MIN) || (b == -1 && a == LLONG_MIN) ||
                (a > 0 && b > 0 && a > LLONG_MAX / b) || (a > 0 && b < 0 && b < LLONG_MIN / a) ||
                (a < 0 && b > 0 && a < LLONG_MIN / b) || (a < 0 && b < 0 && a < LLONG_MAX / b)) {
                fprintf(stderr, "Error: multiplication overflow\n");
                return false;
            }
        }
        *result = a * b;
        return true;

    case '/':
        if (b == 0) {
            fprintf(stderr, "Error: division by zero\n");
            return false;
        }
        if (a == LLONG_MIN && b == -1) {
            fprintf(stderr, "Error: division overflow\n");
            return false;
        }
        *result = a / b;
        return true;

    case '%':
        if (b == 0) {
            fprintf(stderr, "Error: modulo by zero\n");
            return false;
        }
        if (a == LLONG_MIN && b == -1) {
            *result = 0;
            return true;
        }
        *result = a % b;
        return true;

    default:
        fprintf(stderr, "Error: unknown operator\n");
        return false;
    }
}

static bool evaluate(const char* expression, long long* result) {
    Stack stack;
    char  input[INPUT_SIZE];
    char* token;

    if (strlen(expression) >= sizeof(input)) {
        fprintf(stderr, "Error: expression too long\n");
        return false;
    }

    strcpy(input, expression);
    init_stack(&stack);

    token = strtok(input, " \t\r\n");

    while (token != NULL) {
        if (strlen(token) == 1 && strchr("+-*/%", token[0]) != NULL) {
            long long a, b, value;

            if (!pop(&stack, &b) || !pop(&stack, &a))
                return false;

            if (!calculate(token[0], a, b, &value))
                return false;

            if (!push(&stack, value))
                fprintf(stderr, "Error: Expression is too complex\n");

            return false;
        } else {
            char*     end;
            long long value;

            errno = 0;
            value = strtoll(token, &end, 10);

            if (token == end || *end != '\0' || errno == ERANGE) {
                fprintf(stderr, "Error: invalid integer '%s'\n", token);
                return false;
            }

            if (!push(&stack, value))
                return false;
        }

        token = strtok(NULL, " \t\r\n");
    }

    if (stack.top != 0) {
        fprintf(stderr, "Error: Not enough operands in expression\n");
        return false;
    }

    *result = stack.data[stack.top];
    return true;
}

int main(void) {
    char      expression[INPUT_SIZE];
    long long result;

    while (1) {
        printf("Enter RPN expression ");

        if (fgets(expression, sizeof(expression), stdin) == NULL)
            break;

        if (strchr(expression, '\n') == NULL && !feof(stdin)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            fprintf(stderr, "Error: input line too long\n");
            continue;
        }

        char* start = expression;
        while (isspace((unsigned char)*start))
            start++;

        start[strcspn(start, "\r\n")] = '\0';

        if (strcmp(start, "q") == 0 || strcmp(start, "Q") == 0) {
            break;
        }
        if (*start == '\0')
            continue;

        if (evaluate(start, &result))
            printf("Result = %lld\n", result);
    }

    return 0;
}
