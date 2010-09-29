
#ifndef PARSE_OPTIONS_H
#define PARSE_OPTIONS_H


#ifdef __cplusplus
extern "C" {
#endif

enum parse_opt_type {
    OPTION_BOOL,
    OPTION_STRING,
    OPTION_END,
};

struct options {
    enum parse_opt_type type;
    int short_name;
    const char *long_name;
    void *value;
    const char *help;
};

#define OPT_END()                   { OPTION_END }
#define OPT_BOOL(s, l, v, h)        { OPTION_BOOL, (s), (l), (v), (h) }
#define OPT_STRING(s, l, v, h)      { OPTION_STRING, (s), (l), (v), (h) }

void parse_opts(int argc, char **argv, const struct options *opt,
                const char * const usage[]);

void parse_usage_and_die(const char * const * usage, const struct options *opt);

#ifdef __cplusplus
}
#endif

#endif
