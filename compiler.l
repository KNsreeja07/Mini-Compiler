%{
    #include <stdlib.h>
    #include <string.h>
    #include "compiler.h"
    #include "compiler.tab.h"

    void yyerror(char *s);
    int lineno = 0;
%}

ID      [a-zA-Z][a-z0-9A-Z_]*
EXPO    [Ee][-+]?[0-9]+

%%
"#".*   /* Single-line comment */

[0-9]+|[0-9]+"."[0-9]*{EXPO}?|"."?[0-9]+{EXPO}? {
    yylval.dValue = atof(yytext);
    return NUMBER;
}

\"[^"\n]*["\n] {
    yylval.sValue = strdup(yytext+1);
    if (yylval.sValue[yyleng-2] != '"')
        yyerror("improperly terminated string");
    else {
        yylval.sValue[yyleng-2] = 0;
        return STRING;
    }
}

[-()<>=+*/%^,;:{}] {
    return *yytext;
}

":="    return ASSIGN;
">="    return GE;
"<="    return LE;
"!="    return NE;
"while" return WHILE;
"for"   return FOR;
"if"    return IF;
"else"  return ELSE;
"then"  return THEN;
"and"   return AND;
"or"    return OR;
"not"   return NOT;

"print" return PRINT;
"scan"  return SCAN;
"exit"  return EXIT;

"PI"    return PI;

"random"    return RANDOM;
"log"       return LOG;
"exp"       return EXP;
"sqrt"      return SQRT;
"floor"     return FLOOR;
"ceil"      return CEIL;
"abs"       return ABS;
"sin"       return SIN;
"asin"      return ASIN;
"cos"       return COS;
"acos"      return ACOS;
"tan"       return TAN;
"atan"      return ATAN;

[a-zA-Z_][a-zA-Z0-9_]*  {
    yylval.vName = strdup(yytext);  // Copy the identifier
    return VARIABLE;               // Return the token type
}
[ \t]

\n { ++lineno; }

. {
    yyerror("Unknown character");
    exit(1);
}
%%

int yywrap(void) {
    return 1;
}

void yyerror(char *s) {
    fprintf(stdout, "line %d: %s\n", lineno, s);
}