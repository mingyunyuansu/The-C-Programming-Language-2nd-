#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFSIZE 100
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

int getch(void);
void ungetch(int);
int getop(char *);
void push(double);
double pop(void);
void print_top();
double copy_top();
void swap_top();
void clear();

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
				op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}


void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char *s) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void print_top() {
    if (sp > 0)
        printf("\t%.8g\n", val[sp - 1]);
    else
        printf("error: stack empty\n");
}

double copy_top() {
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: empty stack\n");
        return 0.0;
    }
}

void swap_top() {
    if (sp < 2) {
        printf("not enough number in stack");
        return;
    }
    double tmp = val[sp - 1];
    val[sp - 1] = val[sp - 2];
    val[sp - 2] = tmp;
}

void clear() {
    sp = 0;
}
