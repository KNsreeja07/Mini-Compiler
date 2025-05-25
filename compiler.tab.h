

#ifndef YY_YY_COMPILER_TAB_H_INCLUDED
# define YY_YY_COMPILER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    VARIABLE = 259,                /* VARIABLE  */
    STRING = 260,                  /* STRING  */
    WHILE = 261,                   /* WHILE  */
    FOR = 262,                     /* FOR  */
    IF = 263,                      /* IF  */
    THEN = 264,                    /* THEN  */
    PRINT = 265,                   /* PRINT  */
    ASSIGN = 266,                  /* ASSIGN  */
    EXIT = 267,                    /* EXIT  */
    RANDOM = 268,                  /* RANDOM  */
    PI = 269,                      /* PI  */
    SCAN = 270,                    /* SCAN  */
    LOG = 271,                     /* LOG  */
    EXP = 272,                     /* EXP  */
    SQRT = 273,                    /* SQRT  */
    FLOOR = 274,                   /* FLOOR  */
    CEIL = 275,                    /* CEIL  */
    ABS = 276,                     /* ABS  */
    SIN = 277,                     /* SIN  */
    ASIN = 278,                    /* ASIN  */
    COS = 279,                     /* COS  */
    ACOS = 280,                    /* ACOS  */
    TAN = 281,                     /* TAN  */
    ATAN = 282,                    /* ATAN  */
    IFX = 283,                     /* IFX  */
    ELSE = 284,                    /* ELSE  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    GE = 287,                      /* GE  */
    LE = 288,                      /* LE  */
    NE = 289,                      /* NE  */
    NOT = 290,                     /* NOT  */
    UMINUS = 291                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "compiler.y"

    double dValue;
    char *sValue;
    char *vName;
    nodeType *nPtr;

#line 107 "compiler.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_COMPILER_TAB_H_INCLUDED  */
