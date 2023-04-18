#define DEF(type, name, val) type name = val

#define TYPENAME_NONE 127

enum t_typename {
        TYPENAME_BOOL,
        TYPENAME_UNSIGNED_CHAR,
        TYPENAME_CHAR,
        TYPENAME_SIGNED_CHAR,
        TYPENAME_SHORT_INT,
        TYPENAME_UNSIGNED_SHORT_INT,
        TYPENAME_INT,
        TYPENAME_LONG_INT,
        TYPENAME_LONG_LONG_INT,
        TYPENAME_UNSIGNED_INT,
        TYPENAME_UNSIGNED_LONG_INT,
        TYPENAME_UNSIGNED_LONG_LONG_INT,
        TYPENAME_FLOAT,
        TYPENAME_DOUBLE,
        /* ... */
        TYPENAME_POINTER_TO_CHAR,
        TYPENAME_POINTER_TO_INT,
        TYPENAME_POINTER_TO_VOID,
        TYPENAME_OTHER
    };

 #define typeof(x) _Generic((x),                                                              \
             bool: TYPENAME_BOOL,          unsigned char: TYPENAME_UNSIGNED_CHAR,             \
             char: TYPENAME_CHAR,          signed char: TYPENAME_SIGNED_CHAR,                 \
        short int: TYPENAME_SHORT_INT,     unsigned short int: TYPENAME_UNSIGNED_SHORT_INT,   \
              int: TYPENAME_INT,           unsigned int: TYPENAME_UNSIGNED_INT,               \
         long int: TYPENAME_LONG_INT,      unsigned long int: TYPENAME_UNSIGNED_LONG_INT,     \
    long long int: TYPENAME_LONG_LONG_INT, unsigned long long int: TYPENAME_UNSIGNED_LONG_LONG_INT,  \
            float: TYPENAME_FLOAT,                  \
           double: TYPENAME_DOUBLE,                 \
           char *: TYPENAME_POINTER_TO_CHAR,        \
            int *: TYPENAME_POINTER_TO_INT,         \
           void *: TYPENAME_POINTER_TO_VOID,        \
          default: TYPENAME_OTHER)

#define typename(x) _Generic((x),                                                     \
             bool: "_Bool",                  unsigned char: "unsigned char",          \
             char: "char",                     signed char: "signed char",            \
        short int: "short int",         unsigned short int: "unsigned short int",     \
              int: "int",                     unsigned int: "unsigned int",           \
         long int: "long int",           unsigned long int: "unsigned long int",      \
    long long int: "long long int", unsigned long long int: "unsigned long long int", \
            float: "float",                \
          double: "double",                \
          char *: "pointer to char",       \
          int *: "pointer to int",         \
          void *: "pointer to void",       \
          default: "other")

